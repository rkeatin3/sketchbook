(module-probability)=
# Probability

Probability tools shared across the estimation modules: discrete
distributions and Bayes' rule, moments and their estimates, and the
multivariate Gaussian (sampling, densities, Mahalanobis distance, and
transforms).

**Status:** not started ·
[source](https://github.com/rkeatin3/sketchbook/tree/main/src/math/probability)

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
docs/discrete_distribution
docs/bayes_rule
docs/random_vector_moments
docs/correlation
docs/streaming_moments
docs/covariance_validation
docs/multivariate_gaussian
docs/gaussian_mle
docs/affine_transform
docs/sampling
docs/mahalanobis_distance
docs/marginal_conditional
docs/gaussian_product
docs/monte_carlo_propagation
```

Background in {doc}`/docs/concepts/index`: {ref}`characteristic-function`,
{ref}`cholesky-factorization`, {ref}`chi-squared-distribution`.

## Related modules

- {doc}`Filtering </src/estimation/filtering/README>`
- {doc}`Multi-Object Tracking </src/robotics/tracking/README>`

## References

_Key texts for this module, cited from `docs/references.bib`._
