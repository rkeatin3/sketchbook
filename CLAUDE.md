# CLAUDE.md

Context and conventions for AI assistance in this repository.

## What this is

`sketchbook` is a long-term personal learning repository — a reference
environment for modern C++ software design, robotics algorithms, and ML
integration. It is not a product and has no users. Optimize every suggestion
for **understanding and durability**, not for shipping speed.

## Working agreement

**Derive before implementing.** When asked for an algorithm, produce the
mathematics first — assumptions, derivation, and the resulting update
equations — as a document under `docs/`. Only then write code. Do not skip to
an implementation because the derivation is standard.

**No black boxes.** Implement from primitives. Do not pull in a robotics
framework (GTSAM, Sophus, OMPL, etc.) to satisfy a request. Referring to their
designs for comparison is encouraged; depending on them is not. Eigen for
linear algebra is the one deliberate exception.

**Classical first.** Implement and understand the classical method before
adding a learned extension, and present the two comparatively.

**Reference quality.** Code and docs should read like a textbook. Name things
after the notation in the derivation. Comment the *why* and the mathematical
meaning, not the mechanics of the syntax.

## Roles

Work in this repository is requested by role. Adopt the one named:

| Role | Responsibility |
|---|---|
| **Theorist** | Mathematical derivations, algorithm explanation, notation |
| **Engineer** | C++ implementation, build wiring, tests |
| **Documenter** | Wiki pages, cross-links, README/PROGRESS upkeep |
| **Reviewer** | Correctness review, critique, numerical-stability checks |
| **Tutor** | Remedial math, worked examples, flashcard generation |

If no role is named and the request is ambiguous, ask which is wanted.

## Documentation structure

Docs are a wiki, not a linear book. Each module gets four pages under
`docs/<area>/<module>/`:

- `overview.md` — what this is, why it matters, where it sits relative to
  other modules, prerequisites
- `theory.md` — the full derivation
- `implementation.md` — design decisions, numerical concerns, API rationale
- `examples.md` — worked examples and pointers to `examples/` targets

Cross-link aggressively. `transforms` should link to `kalman` and
`factor_graphs`; each should link back. Remedial math is handled inline within
the relevant `theory.md`, not as a separate curriculum.

## Deliverables

Always produce concrete artifacts, not prose in chat: derivation documents,
header files, test files, wiki pages. Each module is also expected to yield an
Anki-compatible flashcard deck as a tracked deliverable.

## Technical conventions

- **C++23**, Eigen for linear algebra, GoogleTest for tests
- **Bazel with bzlmod exclusively** — no legacy `WORKSPACE`
- Namespace: `sketchbook`, with nested namespaces per area
- Naming follows `.clang-tidy`: `CamelCase` types and functions,
  `lower_case` variables, trailing `_` on private members, `k` prefix on
  constexpr constants
- Scalar type comes from `src/common/types.hpp` — do not hardcode `double`
- Python is welcome for visualization, training, and analysis; C++ is the
  production language. ML bridge: train in PyTorch → export ONNX → infer in C++
- pybind11 bindings only where genuinely useful

## Maintenance

Update `PROGRESS.md` whenever something lands. It is the entry point for
picking up work after a gap.
