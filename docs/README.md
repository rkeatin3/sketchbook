# Documentation

A wiki, not a book. Start anywhere and follow the links.

## Robotics

| Module | Topic | Prerequisites |
|---|---|---|
| [transforms](robotics/transforms/overview.md) | Lie groups, SO(3), SE(3), rigid body kinematics | linear algebra |
| [kalman](robotics/kalman/overview.md) | KF, EKF, UKF | transforms, probability |
| [factor_graphs](robotics/factor_graphs/overview.md) | Factor graphs, SLAM, iSAM2 | transforms, kalman |
| [tracking](robotics/tracking/overview.md) | Multi-object tracking, data association | kalman |
| [planning](robotics/planning/overview.md) | RRT, PRM, graph search | transforms |
| [controls](robotics/controls/overview.md) | PID, LQR, MPC, nonlinear control | linear algebra, ODEs |
| [trajectory_opt](robotics/trajectory_opt/overview.md) | Differential flatness, collocation | controls, planning |

## Design patterns

See [patterns/README.md](patterns/README.md).

## Page structure

Every module has four pages:

- **overview** — what and why, plus its place in the dependency graph
- **theory** — the full derivation
- **implementation** — design decisions and numerical concerns
- **examples** — worked examples
