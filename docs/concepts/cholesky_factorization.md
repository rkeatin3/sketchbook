(cholesky-factorization)=
# Cholesky factorization

Factoring a symmetric positive definite matrix as $\Sigma = LL^\top$ with $L$
lower triangular: when it exists, how it's computed, and why it's numerically
stable. Eigen provides the implementation.

## Intuition

## Prerequisites

- Linear algebra: symmetric and positive definite matrices, triangular solves

## Derivation

## Numerical considerations

## Examples

## See also

- {ref}`gaussian-sampling`: a factor of $\Sigma$ turns standard normal draws
  into the target distribution
- {ref}`multivariate-gaussian`: the log-determinant and quadratic form via
  the factor
- {ref}`mahalanobis-distance`: a triangular solve instead of an inverse

## References

- {cite:t}`trefethen1997`, Lecture 23: existence for symmetric positive
  definite matrices, the algorithm, and why it's backward stable without
  pivoting.
- Eigen, [Linear algebra and decompositions](https://eigen.tuxfamily.org/dox/group__TutorialLinearAlgebra.html):
  `LLT` and `LDLT`, and which one to use when $\Sigma$ may be only
  semidefinite.
