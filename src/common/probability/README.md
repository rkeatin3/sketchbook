(module-probability)=
# Probability

Probability tools shared across the estimation modules, starting with the
multivariate Gaussian: sampling, densities, Mahalanobis distance, and
transforms.

**Status:** not started ·
[source](https://github.com/rkeatin3/sketchbook/tree/main/src/common/probability)

## Why it matters

_What problem this solves, and where it shows up in a real system._

## Prerequisites

_Linear algebra background._

## Plan

See {doc}`docs/plan`: decisions so far, the topics in order, and how to validate
them.

## Articles

```{toctree}
:maxdepth: 1

docs/plan
docs/multivariate_gaussian
docs/affine_transform
docs/sampling
docs/mahalanobis_distance
docs/marginal_conditional
docs/monte_carlo_propagation
```

Background in {doc}`/docs/concepts/index`: {ref}`characteristic-function`,
{ref}`cholesky-factorization`, {ref}`chi-squared-distribution`.

## Related modules

- {doc}`Kalman Filtering </src/robotics/kalman/README>`
- {doc}`Multi-Object Tracking </src/robotics/tracking/README>`

## References

_Key texts for this module, cited from `docs/references.bib`._
