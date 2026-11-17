(module-filtering)=
# Filtering

Recursive Bayesian state estimation: the Bayes filter and its implementations,
which differ in how they represent the belief. Histogram filters use a grid,
the Kalman family (KF, EKF, UKF) uses a Gaussian, and particle filters use
samples.

**Status:** not started ·
[source](https://github.com/rkeatin3/sketchbook/tree/main/src/estimation/filtering)

## Why it matters

_What problem this solves, and where it shows up in a real system._

## Prerequisites

- Probability: multivariate Gaussians
- {doc}`Lie Groups </src/math/lie_groups/README>` (for 3D states)

## Roadmap

_The planned articles, in the order they build on each other._

## Articles

```{toctree}
:maxdepth: 1
```

## Related modules

- {doc}`Multi-Object Tracking </src/robotics/tracking/README>`
- {doc}`Factor Graphs </src/estimation/factor_graphs/README>`

## References

_Key texts for this module, cited from `docs/references.bib`._
