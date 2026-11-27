---
name: flashcards
description: Write Anki flashcards for a wiki article into a cards file beside it, and build the Anki package. Use when asked for flashcards or recall practice on a topic, or after Ryan finishes an article's derivation or code.
---

# Flashcards

Flashcards are unrestricted under `CLAUDE.md`: recall practice isn't doing the
work. The one limit is timing. Cards come from what Ryan has already written
(a finished derivation, implemented code, a worked exercise), so a card never
hands him the answer to a result still on an article's "_To prove:_" list.
If the article's derivation isn't written yet, say so and offer cards on its
prerequisites or definitions instead.

## Where cards live

Beside the article, as `<topic>.cards.yaml` next to `<topic>.md` (see
`docs/conventions/index.md`). The file holds only the cards; the article's
label and the deck (its module) are worked out from where it sits. The
format is documented at the top of `tools/flashcards.py`.

Card ids are permanent: Anki updates a card by its id, so editing a card's
text is fine, but changing its id duplicates it. Prefix ids with the article
label (`bayes-rule-evidence`).

## Writing good cards

- One fact or idea per card; a question with one short answer.
- Prefer "why" and "when" over "what": why the evidence normalizes, when
  `LLT` fails, which assumption the prediction step uses.
- Include the key equations, the conditions under which they hold, the
  common pitfalls from the article's Numerical considerations, and the C++
  idioms and design decisions from its Implementation section.
- Use the wiki's notation and `$...$` math, so cards match the articles.
- 5–15 cards per article; fewer, better cards beat exhaustive ones.

## Build

```bash
pip install --group flashcards   # once, in a virtual environment
python tools/flashcards.py
```

This writes `docs/_build/sketchbook.apkg` (gitignored, with the wiki build),
with one deck per module under `sketchbook::`. Importing it into Anki
(File → Import) adds new cards and updates changed ones, keeping review
history.
