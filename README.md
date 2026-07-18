# sketchbook

A long-term personal reference environment for modern C++, robotics
algorithms, and machine learning integration.

This is not a library. It is a place to build things carefully, derive the
mathematics before writing the code, and leave behind documentation good
enough to relearn from years later.

## Layout

```
src/
  common/        Shared types and utilities
  robotics/      Core algorithm modules, each with examples/
    transforms/      Lie groups: SO(3), SE(3), rigid body kinematics
    kalman/          KF, EKF, UKF
    factor_graphs/   Factor graphs, iSAM2-style incremental inference
    tracking/        Multi-object tracking, data association
    planning/        RRT, PRM, graph search, optimization-based planning
    controls/        PID, LQR, MPC, nonlinear control
    trajectory_opt/  Differential flatness, collocation
  patterns/      Design patterns (GoF + Iglberger)
  ml/            ONNX inference, tensor adapters
projects/        Integrated systems: diff_drive_2d, quadrotor, slam_explorer
papers/          Paper reproductions
benchmarks/      Open-dataset evaluations
docs/            Wiki: overview → theory → implementation → examples
data/            Datasets (gitignored)
tools/           Repo scripts
```

## Building

Requires Bazel (see `.bazelversion`) and a C++23-capable compiler.

```bash
bazel build //...
bazel test  //...
```

Useful configurations:

```bash
bazel test //... --config=asan     # AddressSanitizer
bazel test //... --config=ubsan    # UndefinedBehaviorSanitizer
bazel build //... --config=opt     # Optimized
bazel build //... --config=strict  # Warnings as errors
```

## Working principles

- **Derivation before implementation.** Every algorithm gets its mathematics
  written out first, in `docs/`, before any code is committed.
- **No frameworks as black boxes.** Algorithms are implemented from primitives.
  Eigen for linear algebra is the deliberate exception.
- **Classical first, ML second.** The classical method is implemented and
  understood before any learned extension is added, and the two are compared.
- **Documentation is a wiki, not a changelog.** Topics cross-link
  (transforms ↔ kalman ↔ factor_graphs) and read like a textbook.
- **Python is welcome** for visualization, training, and analysis. C++ is the
  production language. The ML bridge is: train in PyTorch → export ONNX →
  infer in C++.

## Progress

See [PROGRESS.md](PROGRESS.md).
