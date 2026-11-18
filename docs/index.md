# sketchbook

A personal reference wiki for robotics and modern C++. Start anywhere and
follow the links, or use the search box, the {doc}`glossary`, or the
{ref}`genindex`.

## Math

| Module | Topic | Builds on |
|---|---|---|
| {doc}`probability </src/math/probability/README>` | Multivariate Gaussians: sampling, Mahalanobis distance, transforms | linear algebra |
| {doc}`lie_groups </src/math/lie_groups/README>` | Lie groups, SO(3), SE(3), rigid body kinematics | linear algebra |

Background with no code of its own is in {doc}`concepts/index`.

## Estimation

| Module | Topic | Builds on |
|---|---|---|
| {doc}`filtering </src/estimation/filtering/README>` | Bayes, histogram, Kalman-family, and particle filters | probability, lie_groups |
| {doc}`factor_graphs </src/estimation/factor_graphs/README>` | Factor graphs, SLAM, incremental smoothing | lie_groups, filtering |

## Robotics

| Module | Topic | Builds on |
|---|---|---|
| {doc}`tracking </src/robotics/tracking/README>` | Multi-object tracking, data association | filtering |

## Software

| Module | Topic |
|---|---|
| {doc}`patterns </src/patterns/README>` | Design patterns, and how modern C++ changes them |
| {doc}`containers </src/utilities/containers/README>` | Data structures from scratch: ring buffer, … |
| {doc}`concurrency </src/utilities/concurrency/README>` | Thread pool, synchronization, the memory model |

```{toctree}
:hidden:
:caption: Math

/src/math/probability/README
/src/math/lie_groups/README
concepts/index
```

```{toctree}
:hidden:
:caption: Estimation

/src/estimation/filtering/README
/src/estimation/factor_graphs/README
```

```{toctree}
:hidden:
:caption: Robotics

/src/robotics/tracking/README
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
