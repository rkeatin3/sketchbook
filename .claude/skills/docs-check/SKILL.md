---
name: docs-check
description: Check the wiki for broken or missing links, stale hubs and plans, and docs that no longer match the code, then fix what's mechanical. Use after changing articles or code, before a review or PR, or when asked to check the docs.
---

# Docs check

Keep the Sphinx + MyST wiki consistent with itself and with the code. The
conventions are in `docs/conventions/` (template, notation, where pages live,
linking); read them first.

## 1. Mechanical checks

- **Strict build:** `sphinx-build -c docs -W --keep-going . docs/_build/html`
  from the repository root, in a virtual environment with
  `pip install --group docs` (pip >= 25.1). This catches broken `{ref}` and
  `{doc}` links, unknown citation keys, and pages missing from a toctree.
- **External links (slower, run when asked or when URLs changed):**
  `sphinx-build -b linkcheck -c docs . docs/_build/linkcheck`.

## 2. Judgment checks

Limit these to the files the branch changed (diff against the merge base:
`git diff "$(git merge-base HEAD "$(git base)")"..HEAD`) unless asked for the
whole wiki.

- **Missing links:** a concept that has an article is mentioned without a
  `{ref}` to it, or is missing from "See also". Search for each article's
  title and key terms across the wiki.
- **Template conformance:** sections in the template's order, none missing
  without reason, "See also" and "References" present.
- **Hubs and plans:** every article is in its hub's toctree; the module's
  plan (article table, proofs table, work chunks, API status) matches the
  articles and the code.
- **Docs vs. code:** an article's Implementation section, embedded
  `literalinclude` markers, and named equations still match the code; API
  status in the plan matches what's implemented.
- **Progress:** `PROGRESS.md` reflects what landed.
- **Notation and glossary:** symbols used are in `docs/conventions/notation.md`,
  terms are defined in the glossary on first use, and articles agree with each
  other.
- **Notation clashes:** the same symbol with two meanings (across articles, or
  between an article and a text it cites, such as $\eta$ for a normalizer and
  for an information vector), or two symbols for one quantity. Report each
  clash with where it occurs; the choice of symbol is Ryan's.
- **Flashcards:** each `<topic>.cards.yaml` sits beside its article
  (`python tools/flashcards.py` fails otherwise), and no card states a result
  still on the article's "_To prove:_" list.
- **Code documentation:** headers and public types and functions carry the
  brief comments the review criteria ask for, naming the article they
  implement.
- **Citations:** every key exists in `docs/references.bib`; new entries have
  verified URLs where a free copy exists.

## 3. Fix or report

- **Fix directly:** broken links, missing cross-links and "See also" entries,
  toctrees, plan and progress tables, citation keys, template structure.
- **Report, don't write:** anything that would fill in a derivation, state a
  result Ryan hasn't proved yet, or change his code (see `CLAUDE.md`). An
  article out of date with the code gets a note to Ryan, not a rewrite of
  his explanation.

Rerun the strict build after fixing, and list what changed and what's left
for Ryan.
