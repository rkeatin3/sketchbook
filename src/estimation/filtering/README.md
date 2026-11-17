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

These steps are phases 1–3 of the {ref}`tracking-roadmap`, which uses the
filters as its estimators. Each step gets its own write-up.

1. **The Bayes filter and a histogram filter.** The general predict–update
   recursion, implemented on a grid (e.g. 1D or 2D localization with a
   multimodal belief). Sets up the Kalman filter as the recursion's Gaussian
   special case, and gives the estimator interface a non-Gaussian
   implementation to design around.
2. **Linear Kalman filter** with a constant-velocity model, validated with
   NEES/NIS against the tracking simulator.
3. **Nonlinear measurements:** EKF, UKF, and a particle filter with a polar
   (radar-like) measurement model. The particle filter is the reference where
   the Gaussian filters struggle.

The estimator interface that tracking swaps implementations through is defined
in `src/estimation/`, not in tracking. Three filters with very different belief
representations are the evidence for what that interface needs.

## Articles

```{toctree}
:maxdepth: 1
```

## Related modules

- {doc}`Multi-Object Tracking </src/robotics/tracking/README>`
- {doc}`Factor Graphs </src/estimation/factor_graphs/README>`

## References

_Key texts for this module, cited from `docs/references.bib`._
