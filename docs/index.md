# sketchbook

A personal reference wiki for robotics and modern C++. Start anywhere and
follow the links, or use the search box, the {doc}`glossary`, or the
{ref}`genindex`.

## Robotics

| Module | Topic | Builds on |
|---|---|---|
| {doc}`transforms </src/robotics/transforms/README>` | Lie groups, SO(3), SE(3), rigid body kinematics | linear algebra |
| {doc}`kalman </src/robotics/kalman/README>` | KF, EKF, UKF | transforms, probability |
| {doc}`factor_graphs </src/robotics/factor_graphs/README>` | Factor graphs, SLAM, incremental smoothing | transforms, kalman |
| {doc}`tracking </src/robotics/tracking/README>` | Multi-object tracking, data association | kalman |

## Software

| Module | Topic |
|---|---|
| {doc}`patterns </src/patterns/README>` | Design patterns, and how modern C++ changes them |
| {doc}`containers </src/utilities/containers/README>` | Data structures from scratch: ring buffer, … |
| {doc}`concurrency </src/utilities/concurrency/README>` | Thread pool, synchronization, the memory model |

```{toctree}
:hidden:
:caption: Robotics

/src/robotics/transforms/README
/src/robotics/kalman/README
/src/robotics/factor_graphs/README
/src/robotics/tracking/README
```

```{toctree}
:hidden:
:caption: Foundations

concepts/index
```

```{toctree}
:hidden:
:caption: Software

/src/patterns/README
/src/utilities/README
```

```{toctree}
:hidden:
:caption: Reference

conventions/index
glossary
bibliography
/papers/README
```
