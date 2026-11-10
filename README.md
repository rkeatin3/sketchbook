# sketchbook

[![C++ CI](https://github.com/rkeatin3/sketchbook/actions/workflows/cpp.yml/badge.svg)](https://github.com/rkeatin3/sketchbook/actions/workflows/cpp.yml)
[![Python CI](https://github.com/rkeatin3/sketchbook/actions/workflows/python.yml/badge.svg)](https://github.com/rkeatin3/sketchbook/actions/workflows/python.yml)
[![Docs](https://github.com/rkeatin3/sketchbook/actions/workflows/docs.yml/badge.svg)](https://rkeatin3.github.io/sketchbook/)
[![codecov](https://codecov.io/gh/rkeatin3/sketchbook/branch/main/graph/badge.svg)](https://codecov.io/gh/rkeatin3/sketchbook)

A personal sketchbook for robotics and software. On the robotics side, my
first focus is estimation and tracking. On the software side, I plan to
explore common design patterns and utilities, and to get up to speed with
modern C++. I'm also using it to experiment with AI in my learning and
development workflow.

With learning as the main goal, the priorities are:

- Concepts and algorithms are derived and explored before they are
  implemented.
- Build from scratch by default. Third-party libraries come in only when
  writing the thing myself would be prohibitive or beside the point (e.g.
  Eigen for linear algebra), or when a toy implementation wouldn't be enough.
- Readability trumps performance.
- Examples show the math and the code in practical use, with visualizations
  wherever possible.
- The [documentation](https://rkeatin3.github.io/sketchbook/) is a reference
  with inline math, code, and visualizations, links between related concepts,
  and a glossary of terms.

## Contents

- `src/robotics/`: transforms and Lie groups, Kalman filtering, factor graphs,
  multi-object tracking
- `src/patterns/`: design patterns in modern C++
- `src/utilities/`: data structures and concurrency primitives
- `papers/`: paper reproductions and a reading queue
- `docs/`: wiki configuration and cross-cutting pages. Module docs live beside
  their code.

Later, maybe: motion planning, controls, trajectory optimization, integrated
robot projects, and benchmarks on open datasets.

## Development

Requires Bazel (see `.bazelversion`) and a C++23 compiler.

```bash
bazel build //...
bazel test //...                  # --config=asan | ubsan | tsan for sanitizers

pip install pre-commit && pre-commit install   # format/lint checks on commit

pip install --group docs          # wiki toolchain (Python >= 3.13)
sphinx-autobuild -c docs . docs/_build/html \
  --watch docs --watch src --re-ignore 'bazel-.*'   # live wiki preview
```

CI runs the build, tests, sanitizers, format and lint checks, coverage, and a
strict wiki build on every push. The wiki deploys to GitHub Pages from `main`.

Editor setup for VS Code is described in [.vscode/README.md](.vscode/README.md).
Progress is tracked in [PROGRESS.md](PROGRESS.md).
