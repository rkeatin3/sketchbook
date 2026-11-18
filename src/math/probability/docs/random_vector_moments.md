(random-vector-moments)=
# Mean and covariance of random vectors

The expectation of a random vector or matrix, the covariance matrix and its
equivalent forms, and how to estimate both from samples accurately. Nothing
here assumes a Gaussian.

## Intuition

## Prerequisites

- Expectation of a scalar random variable, and its linearity
- Linear algebra: transposes and outer products

## Derivation

_To prove:_

- Expectation of a random vector or matrix is linear: $E[AX + b]$ and $E[AXB]$
  for constant $A$, $B$, $b$.
- The covariance identity $E[(X-\mu)(X-\mu)^\top] = E[XX^\top] - \mu\mu^\top$.
- The mean and covariance of $AX + b$, for any distribution.
  {ref}`gaussian-affine-transform` relies on this.
- Which divisor makes the sample covariance unbiased.

## Numerical considerations

## Implementation

## Examples

## See also

- {ref}`multivariate-gaussian`: a distribution fully described by these two
  moments
- {ref}`gaussian-affine-transform`: how the mean and covariance change under
  $x \mapsto Fx + b$, by the same kind of argument
- {ref}`gaussian-mle`: the same estimates derived as the best Gaussian fit,
  and a different answer to the $n$ vs. $n - 1$ question
- {ref}`gaussian-sampling`: sample statistics are how a sampler is validated

## References

- {cite:t}`murphy2022`, Ch. 3: covariance and correlation of random vectors.
- {cite:t}`blitzstein2019`, Ch. 7: covariance and correlation, built up from
  the scalar case.
- {cite:t}`welford1962`: the one-pass update for sums of squares and products
  that avoids catastrophic cancellation.
- {cite:t}`chan1983`: a comparison of algorithms for the sample variance, with
  error analysis of the one-pass and two-pass forms.
- Wikipedia, [Algorithms for calculating variance](https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance):
  the naive one-pass formula and why it fails, the two-pass algorithm, and
  Welford's method, including the covariance versions. The free route to the
  two papers above, which are paywalled.
