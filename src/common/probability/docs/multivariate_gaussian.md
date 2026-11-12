(multivariate-gaussian)=
# Multivariate Gaussian

The multivariate normal distribution $\mathcal{N}(x;\, \mu, \Sigma)$: its
definition, the ways to parameterize it, how to evaluate its density
accurately, and how the `Gaussian` class represents it.

## Intuition

## Prerequisites

- Linear algebra: symmetric and positive (semi)definite matrices
- {ref}`cholesky-factorization`, for evaluating the density

## Derivation

## Numerical considerations

## Implementation

## Examples

## See also

- {ref}`gaussian-affine-transform`: the operation everything else builds on
- {ref}`gaussian-sampling`: drawing samples
- {ref}`mahalanobis-distance`: the quadratic form in the density's exponent
- {ref}`gaussian-marginal-conditional`: splitting a joint Gaussian

## References

- {cite:t}`murphy2022`, §3.2: the definition, the density, and the shape of
  the contours. The main starting point.
- {cite:t}`barfoot2024`, Ch. 2: Gaussian densities in estimation notation.
- {cite:t}`bishop2006`, §2.3: the classic treatment, including the geometry
  of the eigendecomposition of $\Sigma$.
- {cite:t}`barshalom2001`, Ch. 1: the probability review behind the tracking
  chapters.
- {cite:t}`petersen2012`, §8: identities, for checking results.
