(multivariate-gaussian)=
# Multivariate Gaussian

The multivariate normal distribution $\mathcal{N}(x;\, \mu, \Sigma)$: its
definition, the ways to parameterize it, how to evaluate its density
accurately, and how the `Gaussian` class represents it.

## Intuition

## Prerequisites

- {ref}`random-vector-moments`
- Linear algebra: symmetric and positive (semi)definite matrices
- {ref}`cholesky-factorization`, for evaluating the density

## Derivation

_To prove:_

- The density integrates to 1: where the normalizing constant comes from.
- The parameters are the moments: the mean and covariance of
  $x \sim \mathcal{N}(\mu, \Sigma)$ are $\mu$ and $\Sigma$.
- Uncorrelated implies independent for *jointly* Gaussian variables. Then a
  counterexample: two variables that are each Gaussian and uncorrelated, but
  dependent.
- Why $\Sigma$ must be symmetric positive semidefinite, and what happens to the
  density when it's singular. Where does a Gaussian with singular $\Sigma$
  live, and how can it be described without a density?
- The log-density, and why evaluate it instead of the density.
- The log-determinant from a Cholesky factor of $\Sigma$.
- The quadratic form $(x - \mu)^\top \Sigma^{-1} (x - \mu)$ without forming
  $\Sigma^{-1}$.

## Numerical considerations

## Implementation

Questions to settle:

- `Pdf` and `LogPdf` for a singular $\Sigma$: refuse, or evaluate on the
  subspace the distribution lives in?
- Which factorization serves both the log-determinant and the quadratic form,
  and still works when $\Sigma$ is only semidefinite?

## Examples

## Exercises

:::{exercise}
:label: multivariate-gaussian-ex-note1-p2

ROB 530 [lecture note 1][note1], Problem 2: uncorrelated jointly Gaussian
vectors are independent.
:::

## See also

- {ref}`gaussian-affine-transform`: the operation everything else builds on
- {ref}`gaussian-sampling`: drawing samples
- {ref}`gaussian-mle`: fitting the parameters to samples
- {ref}`gaussian-product`: multiplying densities, and the information form
- {ref}`mahalanobis-distance`: the quadratic form in the density's exponent
- {ref}`gaussian-marginal-conditional`: splitting a joint Gaussian
- {ref}`covariance-validation`: which $\Sigma$ are allowed, and how the
  constructor checks
- {ref}`correlation`: uncorrelated vs. independent outside the Gaussian case

## References

- {cite:t}`murphy2022`, §3.2: the definition, the density, and the shape of
  the contours. The main starting point.
- {cite:t}`barfoot2024`, Ch. 2: Gaussian densities in estimation notation.
- {cite:t}`bishop2006`, §2.3: the classic treatment, including the geometry
  of the eigendecomposition of $\Sigma$.
- {cite:t}`barshalom2001`, Ch. 1: the probability review behind the tracking
  chapters.
- {cite:t}`petersen2012`, §8: identities, for checking results.

[note1]: https://github.com/UMich-CURLY-teaching/UMich-ROB-530-public/blob/main/lecture-notes/01_Probability.pdf
