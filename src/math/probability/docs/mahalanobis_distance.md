(mahalanobis-distance)=
# Mahalanobis distance

Distance from the mean measured in units of the covariance, the distribution it
follows, and its uses in gating, filter consistency tests (NEES, NIS), and
covariance ellipses.

## Intuition

## Prerequisites

- {ref}`multivariate-gaussian`
- {ref}`chi-squared-distribution`

## Derivation

_To prove:_

- The distribution of the squared Mahalanobis distance of a sample from its own
  Gaussian, including its parameter.
- The shape of its level sets, and how they relate to the eigendecomposition of
  $\Sigma$.

## Numerical considerations

## Implementation

## Examples

## See also

- {ref}`multivariate-gaussian`: the same quadratic form appears in the density
- {ref}`gaussian-sampling`: the distance distribution validates a sampler

## References

- {cite:t}`murphy2022`, §3.2: Mahalanobis distance and the elliptical
  contours of the density.
- {cite:t}`barshalom2001`, Ch. 1: the chi-squared distribution of the
  distance. The later chapters use it for filter consistency (NEES, NIS) and
  validation gates.
- {cite:t}`barfoot2024`, Ch. 2: the same result in estimation notation.
