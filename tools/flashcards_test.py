"""Tests for tools/flashcards.py: text conversion, file discovery, and decks."""

from __future__ import annotations

from pathlib import Path

import flashcards
import genanki
import pytest


def write(path: Path, text: str) -> Path:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text)
    return path


def make_article(root: Path, relative: str, label: str, cards: str) -> Path:
    """An article with a label line, and a card file beside it."""
    article = write(root / relative, f"({label})=\n# Title\n")
    return write(article.with_name(article.stem + flashcards.CARD_SUFFIX), cards)


ONE_CARD = "cards:\n  - id: {id}\n    front: Q\n    back: A\n"


class TestToAnkiHtml:
    def test_converts_inline_and_display_math_to_mathjax(self) -> None:
        assert flashcards.to_anki_html("$x$ and $$y$$") == r"\(x\) and \[y\]"

    def test_escapes_html_inside_math(self) -> None:
        assert flashcards.to_anki_html("$a < b$") == r"\(a &lt; b\)"

    def test_keeps_dollar_signs_in_code_spans(self) -> None:
        assert flashcards.to_anki_html("`$HOME` and $x$") == r"<code>$HOME</code> and \(x\)"

    def test_turns_newlines_into_breaks(self) -> None:
        assert flashcards.to_anki_html("one\ntwo\n") == "one<br>two"


class TestDeckFor:
    def test_module_article_uses_module_name(self, tmp_path: Path) -> None:
        path = tmp_path / "src/math/probability/docs/bayes_rule.cards.yaml"
        assert flashcards.deck_for(path, tmp_path) == "probability"

    def test_concept_page_uses_concepts(self, tmp_path: Path) -> None:
        path = tmp_path / "docs/concepts/cholesky_factorization.cards.yaml"
        assert flashcards.deck_for(path, tmp_path) == "concepts"


class TestFindCardFiles:
    def test_reads_label_from_the_article_beside_the_cards(self, tmp_path: Path) -> None:
        make_article(
            tmp_path,
            "src/math/probability/docs/bayes_rule.md",
            "bayes-rule",
            ONE_CARD.format(id="c1"),
        )
        (card_file,) = flashcards.find_card_files(tmp_path)
        assert (card_file.deck, card_file.article) == ("probability", "bayes-rule")

    def test_ignores_build_output(self, tmp_path: Path) -> None:
        make_article(tmp_path, "docs/_build/copy/page.md", "page", ONE_CARD.format(id="c1"))
        assert flashcards.find_card_files(tmp_path) == []

    def test_card_file_without_article_fails(self, tmp_path: Path) -> None:
        write(tmp_path / "docs/concepts/orphan.cards.yaml", ONE_CARD.format(id="c1"))
        with pytest.raises(SystemExit, match="no article orphan.md"):
            flashcards.find_card_files(tmp_path)

    def test_article_without_label_fails(self, tmp_path: Path) -> None:
        write(tmp_path / "docs/concepts/page.md", "# No label\n")
        write(tmp_path / "docs/concepts/page.cards.yaml", ONE_CARD.format(id="c1"))
        with pytest.raises(SystemExit, match="isn't a label"):
            flashcards.find_card_files(tmp_path)

    @pytest.mark.parametrize(
        ("content", "message"),
        [
            ("", "expected a mapping"),
            ("cards: {}\n", "expected a mapping"),
            ("cards:\n  - id: c1\n    front: Q\n", "missing back"),
        ],
    )
    def test_malformed_card_file_fails_clearly(
        self, tmp_path: Path, content: str, message: str
    ) -> None:
        make_article(tmp_path, "docs/concepts/page.md", "page", content)
        with pytest.raises(SystemExit, match=message):
            flashcards.find_card_files(tmp_path)


class TestBuildDecks:
    def test_one_deck_per_module_with_stable_guids(self, tmp_path: Path) -> None:
        make_article(tmp_path, "src/math/probability/docs/a.md", "a", ONE_CARD.format(id="a-1"))
        make_article(tmp_path, "docs/concepts/b.md", "b", ONE_CARD.format(id="b-1"))
        decks = flashcards.build_decks(flashcards.find_card_files(tmp_path))
        assert sorted(deck.name for deck in decks) == [
            "sketchbook::concepts",
            "sketchbook::probability",
        ]
        guids = {note.guid for deck in decks for note in deck.notes}
        assert guids == {genanki.guid_for("a-1"), genanki.guid_for("b-1")}

    def test_duplicate_card_id_fails(self, tmp_path: Path) -> None:
        make_article(tmp_path, "docs/concepts/a.md", "a", ONE_CARD.format(id="same"))
        make_article(tmp_path, "docs/concepts/b.md", "b", ONE_CARD.format(id="same"))
        with pytest.raises(SystemExit, match="already used"):
            flashcards.build_decks(flashcards.find_card_files(tmp_path))

    def test_rebuilding_gives_the_same_deck_ids(self, tmp_path: Path) -> None:
        make_article(tmp_path, "docs/concepts/a.md", "a", ONE_CARD.format(id="a-1"))
        first = flashcards.build_decks(flashcards.find_card_files(tmp_path))
        second = flashcards.build_decks(flashcards.find_card_files(tmp_path))
        assert [deck.deck_id for deck in first] == [deck.deck_id for deck in second]
