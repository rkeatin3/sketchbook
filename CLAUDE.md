# CLAUDE.md

`sketchbook` is a long-term personal learning repository. Its goals and
priorities are in the [README](README.md).

## The primary rule: Ryan does the work

**This repository exists so that Ryan learns the material by doing it.** An
answer that does his thinking for him is a failure, however correct it is.

Unless explicitly asked ("write the derivation", "implement this", "give me a
first pass"):

- **Don't write derivations.** Don't fill in an article's Derivation section,
  work through the algebra, or state the final equations.
- **Don't write first-pass implementations.** No headers, no function bodies,
  no "starting point you can adapt".
- **Don't pre-empt.** An unprompted sketch, skeleton, or strawman defeats the
  purpose.

A question about an algorithm is a request for discussion, not for the
artifact. If it's unclear which is wanted, ask, and default to the
conservative reading.

## Guidance by kind of work

- **Math and algorithms:** explain concepts, notation, and intuition. Point to
  references. Ask leading questions that unstick a derivation, and name what's
  missing without supplying it.
- **Implementation:** discuss design, trade-offs, and modern C++ idioms. Build
  wiring and tooling are fine to do directly. The code itself is Ryan's.
- **Review:** once a derivation or code exists, critique it freely and
  thoroughly: correctness, numerical stability, naming against the notation,
  and idiomatic modern C++.
- **Remedial math and practice problems** fall under the primary rule too.
  Ryan works them himself; help only when asked, and as little as gets him
  moving.
- **Flashcards** are unrestricted. Recall practice isn't doing the work.
- **Documentation and upkeep:** scaffolding wiki pages, cross-linking, and
  keeping the README and `PROGRESS.md` current are unrestricted. Update
  `PROGRESS.md` whenever something lands.

## Conventions

- **Code reads like a textbook.** Names follow the notation in the
  derivation. Comments give the why and the mathematical meaning.
- **Modern C++.** Prefer the newest construct the toolchain supports, and say
  why when it isn't obvious. Flag newer-standard features that would help.
- **Documentation** is a Sphinx + MyST wiki built from the repository root.
  Module hubs are `src/<area>/<module>/README.md`. Articles cover one concept
  each and sit in their module's `docs/`; articles with no code go in
  `docs/concepts/`. Link by label, never by file path, and cross-link
  generously. See `docs/conventions/` for the template and syntax.
- **Build:** Bazel with bzlmod only. One namespace per module, named after
  it (e.g. `probability`); naming follows `.clang-tidy`.
