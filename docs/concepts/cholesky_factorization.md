(cholesky-factorization)=
# Cholesky factorization

Factoring a symmetric positive definite matrix as $\Sigma = LL^\top$ with $L$
lower triangular: when it exists, how it's computed, and why it's numerically
stable. Eigen provides the implementation.

## Intuition

## Prerequisites

- Linear algebra: symmetric and positive definite matrices, triangular solves

## Derivation

_To prove:_

- Existence and uniqueness of $\Sigma = LL^\top$ for symmetric positive
  definite $\Sigma$, and the algorithm the proof gives.
- What goes wrong when $\Sigma$ is positive semidefinite but singular.

## Numerical considerations

## Examples

## Exercises

:::{exercise}
:label: cholesky-factorization-ex-hw1-5

ROB 530 [Homework 1][hw1], §5: which matrices have a unique Cholesky
factor. Compute the ones that do by hand.
:::

## See also

- {ref}`gaussian-sampling`: a factor of $\Sigma$ turns standard normal draws
  into the target distribution
- {ref}`multivariate-gaussian`: the log-determinant and quadratic form via
  the factor
- {ref}`mahalanobis-distance`: a triangular solve instead of an inverse
- {ref}`covariance-validation`: the factorization as a test that a matrix is
  a valid covariance

## References

- {cite:t}`trefethen1997`, Lecture 23: existence for symmetric positive
  definite matrices, the algorithm, and why it's backward stable without
  pivoting.
- Eigen, [Linear algebra and decompositions](https://eigen.tuxfamily.org/dox/group__TutorialLinearAlgebra.html):
  `LLT` and `LDLT`, and which one to use when $\Sigma$ may be only
  semidefinite.

[hw1]: https://github.com/UMich-CURLY-teaching/UMich-ROB-530-public/blob/main/homework/homework-01/NA568_HW1_W22.pdf
