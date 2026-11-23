(correlation)=
# Correlation and independence

The correlation coefficient as a scale-free measure of linear dependence, why
it's bounded by one, and why zero correlation doesn't mean independence.

## Intuition

## Prerequisites

- {ref}`random-vector-moments`
- {ref}`discrete-distribution`: independence

## Derivation

_To prove:_

- The Cauchy–Schwarz inequality for expectations,
  $E[XY]^2 \le E[X^2]\, E[Y^2]$.
- $|\rho_{XY}| \le 1$ for $X$ and $Y$ with nonzero variances, with equality
  exactly when $Y$ is an affine function of $X$ (with probability one).
- Independent implies uncorrelated.
- Uncorrelated does not imply independent: $X \sim \mathcal{N}(0, 1)$ and
  $Y = X^2$. Which property of the distribution of $X$ makes the example
  work, and which other distributions would do?
- The correlation matrix $D^{-1/2} \Sigma D^{-1/2}$, with $D$ the diagonal of
  $\Sigma$, is symmetric positive semidefinite with ones on the diagonal.

The converse for *jointly* Gaussian variables is in
{ref}`multivariate-gaussian`.

## Numerical considerations

## Implementation

Questions to settle:

- Computing a correlation matrix from a covariance: what happens when a
  variance is zero? (The same degenerate case as in the bound above.)
- Should rounding be allowed to push a coefficient past $\pm 1$, or should the
  result be clamped?
- How does a test show dependence for the $X, X^2$ pair, when the sample
  correlation is near zero? Which statistic of the samples does detect it?

## Examples

## Exercises

:::{exercise} Note 1, Problem 1
:label: correlation-ex-note1-p1
:nonumber:

ROB 530 [lecture note 1][note1], Problem 1: the $X$, $X^2$ pair.
:::

:::{exercise} Coding
:label: correlation-ex-coding
:nonumber:

Sample the pair and show, with a fixed seed, that the sample
correlation is near zero while the samples are clearly dependent.
:::

## See also

- {ref}`random-vector-moments`: the covariance this normalizes
- {ref}`multivariate-gaussian`: where uncorrelated does imply independent
- {ref}`covariance-validation`: the correlation matrix inherits positive
  semidefiniteness

## References

- {cite:t}`blitzstein2019`, §7.3: covariance and correlation, and the
  $X$, $X^2$ example.
- {cite:t}`ghaffari2022`, lecture note 1, §2: Remarks 1 and 2 on correlation
  and independence.
- {cite:t}`murphy2022`, §3.1: the correlation coefficient and correlation
  matrix.

[note1]: https://github.com/UMich-CURLY-teaching/UMich-ROB-530-public/blob/main/lecture-notes/01_Probability.pdf
