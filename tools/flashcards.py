"""Build an Anki package from the flashcard files that sit beside wiki articles.

An article's cards live next to it, as `<topic>.cards.yaml` beside
`<topic>.md`:

    cards:
      - id: bayes-rule-evidence  # stable forever; Anki updates the card by it
        front: Why can the evidence $p(z)$ be skipped in a Bayes update?
        back: ...
        tags: [bayes]            # optional

The article's label is read from the first line of `<topic>.md`, and the deck
is the article's module (`src/<area>/<module>/docs/` gives
`sketchbook::<module>`; `docs/concepts/` gives `sketchbook::concepts`).

Math uses the wiki's delimiters, $...$ and $$...$$, and is converted to
MathJax's \\(...\\) and \\[...\\], which Anki renders. Inline `code` and line
breaks are kept.

Usage: python tools/flashcards.py [--root .] [--out docs/_build/sketchbook.apkg]
"""

from __future__ import annotations

import argparse
import hashlib
import html
import re
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Any

import genanki
import yaml

REPO_ROOT = Path(__file__).resolve().parent.parent
DEFAULT_OUT = REPO_ROOT / "docs" / "_build" / "sketchbook.apkg"
# Searched for card files. The repository root itself holds bazel-* symlinks
# into the build cache, so the search never starts there.
SEARCH_DIRS = ("src", "docs", "papers")
CARD_SUFFIX = ".cards.yaml"
DECK_PREFIX = "sketchbook"

# Anki identifies a note type by this number. It must never change, or every
# card would be re-imported as new.
MODEL_ID = 1_607_392_319

MODEL = genanki.Model(
    MODEL_ID,
    "sketchbook basic",
    fields=[{"name": "Front"}, {"name": "Back"}, {"name": "Article"}],
    templates=[
        {
            "name": "Card",
            "qfmt": "{{Front}}",
            "afmt": '{{FrontSide}}<hr id="answer">{{Back}}<div class="article">{{Article}}</div>',
        }
    ],
    css=".card { font-family: sans-serif; font-size: 18px; text-align: left; }\n"
    ".article { margin-top: 1em; font-size: 12px; color: grey; }",
)

LABEL_LINE = re.compile(r"^\(([\w-]+)\)=\s*$")
DISPLAY_MATH = re.compile(r"\$\$(.+?)\$\$", re.DOTALL)
INLINE_MATH = re.compile(r"\$(.+?)\$")
INLINE_CODE = re.compile(r"`([^`]+)`")


@dataclass(frozen=True)
class CardFile:
    """One article's cards, with the deck and label they belong to."""

    path: Path
    deck: str
    article: str
    cards: list[dict[str, Any]]


def to_anki_html(text: str) -> str:
    """Convert a card's Markdown-ish text to the HTML Anki stores."""
    escaped = html.escape(text.strip(), quote=False)
    escaped = DISPLAY_MATH.sub(r"\\[\1\\]", escaped)
    escaped = INLINE_MATH.sub(r"\\(\1\\)", escaped)
    escaped = INLINE_CODE.sub(r"<code>\1</code>", escaped)
    return escaped.replace("\n", "<br>")


def stable_deck_id(name: str) -> int:
    """A deck id derived from its name, so rebuilding never duplicates decks."""
    return int(hashlib.sha256(name.encode()).hexdigest()[:8], 16)


def deck_for(path: Path, root: Path) -> str:
    """The module an article belongs to: src/<area>/<module>/docs/ or docs/<dir>/."""
    parts = path.relative_to(root).parts
    if parts[0] == "src" and len(parts) >= 4:
        return parts[2]
    return path.parent.name


def article_label(path: Path) -> str:
    """The label on the first line of the article beside a card file."""
    article = path.with_name(path.name.removesuffix(CARD_SUFFIX) + ".md")
    if not article.exists():
        sys.exit(f"{path}: no article {article.name} beside it")
    first_line = article.read_text().splitlines()[0]
    match = LABEL_LINE.match(first_line)
    if match is None:
        sys.exit(f"{article}: first line isn't a label like (topic-label)=")
    return match.group(1)


def find_card_files(root: Path) -> list[CardFile]:
    paths = sorted(
        path
        for directory in SEARCH_DIRS
        if (root / directory).is_dir()
        for path in (root / directory).rglob(f"*{CARD_SUFFIX}")
        if "_build" not in path.parts
    )
    return [
        CardFile(
            path,
            deck_for(path, root),
            article_label(path),
            yaml.safe_load(path.read_text())["cards"],
        )
        for path in paths
    ]


def build_decks(card_files: list[CardFile]) -> list[genanki.Deck]:
    decks: dict[str, genanki.Deck] = {}
    seen_ids: dict[str, Path] = {}
    for card_file in card_files:
        deck_name = f"{DECK_PREFIX}::{card_file.deck}"
        deck = decks.setdefault(deck_name, genanki.Deck(stable_deck_id(deck_name), deck_name))
        for card in card_file.cards:
            card_id = card["id"]
            if card_id in seen_ids:
                sys.exit(
                    f"{card_file.path}: card id '{card_id}' already used in {seen_ids[card_id]}"
                )
            seen_ids[card_id] = card_file.path
            tags = [card_file.deck, card_file.article, *card.get("tags", [])]
            deck.add_note(
                genanki.Note(
                    model=MODEL,
                    fields=[
                        to_anki_html(card["front"]),
                        to_anki_html(card["back"]),
                        card_file.article,
                    ],
                    guid=genanki.guid_for(card_id),
                    tags=[tag.replace(" ", "_") for tag in tags],
                )
            )
    return list(decks.values())


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--root", type=Path, default=REPO_ROOT)
    parser.add_argument("--out", type=Path, default=DEFAULT_OUT)
    args = parser.parse_args()

    decks = build_decks(find_card_files(args.root.resolve()))
    if not decks:
        sys.exit(f"No *{CARD_SUFFIX} files found under {args.root}")
    args.out.parent.mkdir(parents=True, exist_ok=True)
    genanki.Package(decks).write_to_file(args.out)
    count = sum(len(deck.notes) for deck in decks)
    print(f"Wrote {count} cards in {len(decks)} decks to {args.out}")


if __name__ == "__main__":
    main()
