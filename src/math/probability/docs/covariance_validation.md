(covariance-validation)=
# Valid covariance matrices

Which matrices can be covariances, and how to check one in floating point.
`Gaussian<N>` validates its covariance on construction, and the filters must
keep it valid after every step.

## Intuition

## Prerequisites

- {ref}`random-vector-moments`
- Linear algebra: eigenvalues of symmetric matrices, principal minors

## Derivation

_To prove:_

- Every covariance matrix is symmetric positive semidefinite.
- Conversely, every symmetric positive semidefinite matrix is the covariance
  of some random vector.
- For a symmetric matrix, these are equivalent: positive semidefinite, all
  eigenvalues nonnegative, all principal minors nonnegative. Why checking only
  the *leading* principal minors works for positive definite but not for
  semidefinite matrices.
- The $2 \times 2$ case as conditions on the diagonal and the determinant.
- Positive definite if and only if a Cholesky factor with a positive diagonal
  exists, and then it's unique (from {ref}`cholesky-factorization`).

## Numerical considerations

## Implementation

This is where the plan's open questions about validation get settled (see
{ref}`probability-plan`, step 1):

- `Gaussian<N>` requires symmetric positive *semi*definite, so singular
  covariances are valid. Which test accepts those and rejects indefinite
  matrices, with which tolerances: an exact symmetry check or a relative one;
  Cholesky (`LLT`), `LDLT`, or the smallest eigenvalue?
- Which operations need positive definite, and how does each handle a
  singular covariance?
- Every operation that produces a new covariance re-checks it. Where does
  that check live so it's hard to forget?
- `Eigen::LLT` reads only the lower triangle. What does that mean for a
  nonsymmetric input?
- Report failures with an exception, an assert, or `std::expected`?
- A free function the constructor calls, so the filters can reuse it after an
  update?

## Examples

## Exercises

:::{exercise}
:label: covariance-validation-ex-hw1-1b

ROB 530 [Homework 1][hw1], §1.B: which of five matrices are valid
covariances, and why the others aren't.
:::

:::{exercise}
:label: covariance-validation-ex-hw1-5

ROB 530 [Homework 1][hw1], §5: which matrices have a unique Cholesky
factor. Compute the ones that do by hand.
:::

:::{exercise}
:label: covariance-validation-ex-coding

_Coding:_ the matrices from both problems as test cases for the
validation function, plus a singular positive semidefinite matrix and one
that is nonsymmetric by $10^{-12}$.
:::

## See also

- {ref}`cholesky-factorization`: the factorization most checks rely on
- {ref}`multivariate-gaussian`: the density needs $\Sigma$ to be positive
  definite
- {ref}`correlation`: the correlation matrix of a valid covariance is valid

## References

- {cite:t}`trefethen1997`, Lecture 23: Cholesky as a test for positive
  definiteness.
- {cite:t}`ghaffari2022`, lecture note 1, §2: symmetric positive
  semidefinite covariances and the Cholesky factor.
- Eigen, [Linear algebra and decompositions](https://eigen.tuxfamily.org/dox/group__TutorialLinearAlgebra.html):
  `LLT`, `LDLT`, and `SelfAdjointEigenSolver`.

[hw1]: https://github.com/UMich-CURLY-teaching/UMich-ROB-530-public/blob/main/homework/homework-01/NA568_HW1_W22.pdf
