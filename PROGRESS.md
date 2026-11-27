# Progress

What is done and what is next. Updated as work lands.

## Infrastructure

- [x] Bazel (bzlmod) + C++23, clang-format, clang-tidy
- [x] CI: build, test, sanitizers (ASan/UBSan/TSan), format, advisory
      clang-tidy, coverage, Python lint/type/test, strict wiki build
- [x] Pre-commit hooks, VS Code + clangd setup
- [x] Wiki: Sphinx + MyST, deployed to GitHub Pages from `main`
- [x] `//src/common:toolchain_test` smoke test; delete once real tests land
- [x] GitHub repo, Pages deploy, and branch protection on `main`
- [ ] Codecov project linked (`CODECOV_TOKEN` secret)

## Math

| Module | Articles | Implementation | Tests | Examples |
|---|---|---|---|---|
| lie_groups | — | — | — | — |

## Estimation

| Module | Articles | Implementation | Tests | Examples |
|---|---|---|---|---|
| filtering     | — | — | — | — |
| factor_graphs | — | — | — | — |

## Robotics

| Module | Articles | Implementation | Tests | Examples |
|---|---|---|---|---|
| tracking | — | — | — | — |

## Utilities

| Module | Articles | Implementation | Tests |
|---|---|---|---|
| containers  | — | — | — |
| concurrency | — | — | — |

## Modern C++

Feature and idiom inventories in `src/cpp/`, checked by every review.
`//src/cpp/features:support_test` checks the features available on both
toolchains.

| Module | Articles | Experiments |
|---|---|---|
| features | 1 scaffolded (deducing `this`) | — |
| idioms   | — | — |

## Design patterns

None started.

## Agent skills

In `.claude/skills/`: `review` (criteria shared with the CI review),
`docs-check`, `hint`, `scaffold-article`, `course-map`, and `flashcards`
(with `tools/flashcards.py` for the Anki package).

## Next up

1. Tracking phase 0: foundations and the 2D simulator (see the
   [tracking roadmap](src/robotics/tracking/docs/roadmap.md)).
2. Seed the papers reading queue.
3. Modern C++ upkeep: convert the C++ articles' Exercises to `{exercise}`
   blocks once sphinx-exercise is enabled; recheck the feature inventory's
   toolchain gaps on compiler upgrades, and assess the C++26 rows.
