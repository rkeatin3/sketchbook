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

## Robotics

| Module | Articles | Implementation | Tests | Examples |
|---|---|---|---|---|
| transforms    | — | — | — | — |
| kalman        | — | — | — | — |
| factor_graphs | — | — | — | — |
| tracking      | — | — | — | — |

## Utilities

| Module | Articles | Implementation | Tests |
|---|---|---|---|
| containers  | — | — | — |
| concurrency | — | — | — |

## Design patterns

None started.

## Next up

1. Tracking phase 0: foundations and the 2D simulator (see the
   [tracking roadmap](src/robotics/tracking/docs/roadmap.md)).
2. Sketch the repo's agent skills (`.claude/skills/`).
3. Seed the papers reading queue.
