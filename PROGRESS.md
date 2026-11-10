# Progress

What is done and what is next. Updated as work lands.

## Infrastructure

- [x] Bazel (bzlmod) + C++23, clang-format, clang-tidy
- [x] CI: build, test, sanitizers (ASan/UBSan/TSan), format, advisory
      clang-tidy, coverage, Python lint/type/test, strict wiki build
- [x] Pre-commit hooks, VS Code + clangd setup
- [x] Wiki: Sphinx + MyST, deployed to GitHub Pages from `main`
- [x] `//src/common:toolchain_test` smoke test; delete once real tests land
- [ ] GitHub remote pushed; Pages source set to "GitHub Actions"
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

1. Create the GitHub remote, push, and enable Pages.
2. Write the tracking roadmap into its hub.
3. Sketch the repo's agent skills (`.claude/skills/`).
4. Seed the papers reading queue.
