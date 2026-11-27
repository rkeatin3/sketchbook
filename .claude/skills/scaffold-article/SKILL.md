---
name: scaffold-article
description: Create a new wiki article from the template and wire it into its hub, the module plan, cross-links, and PROGRESS.md, with results to prove named but not answered. Use when asked to add, scaffold, or plan an article or a module's articles.
---

# Scaffold an article

Scaffolding is unrestricted under `CLAUDE.md`; the derivation and the code are
Ryan's. A scaffold names what to work out and where to read, and leaves the
answers out.

## 1. Place and name it

Follow `docs/conventions/index.md`:

- An article about a module's code goes in `src/<area>/<module>/docs/<topic>.md`;
  an article with no code in `docs/concepts/<topic>.md`. Prefer a code home:
  if the topic can be checked in code, it belongs in a module.
- File name in `snake_case`; label in `kebab-case`, named after the topic.
  Check the label isn't already taken (`grep -rn "^(label)=" .`).

## 2. Fill the template

Copy the block in `docs/conventions/article-template.md`, then:

- **Opening:** one or two sentences on what it is and what problem it solves.
- **Intuition:** leave empty.
- **Prerequisites:** `{ref}` links to the articles it builds on.
- **Derivation:** a "_To prove:_" list naming the results, without stating
  answers that are the point of the exercise (name "the conditional of a
  joint Gaussian", not its formula).
- **Numerical considerations:** leave empty.
- **Implementation:** design questions to settle. No signatures, no code.
- **Examples:** pointers to worked examples in references or course notes.
- **Exercises:** course and textbook problems by source and number, with a
  link; never copy problem statements. Mark coding exercises.
- **See also** and **References:** cross-links with one line each, and
  citations with a pointer to the section. Add new books to
  `docs/references.bib` with a verified URL when a free copy exists.

## 3. Wire it in

- The module hub's toctree (`src/<area>/<module>/README.md`), or
  `docs/concepts/index.md`.
- The module plan: the article table, the proofs table, and the work chunk it
  belongs to.
- "See also" links back from the related articles.
- `PROGRESS.md`: the module's article count.

## 4. Check

Run the strict wiki build (see the `docs-check` skill) and fix anything it
reports.
