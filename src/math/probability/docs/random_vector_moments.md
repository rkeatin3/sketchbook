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
- The cross-covariance $\operatorname{Cov}(X, Y)$ of two random vectors, how it
  relates to $\operatorname{Cov}(Y, X)$, and the covariance of a sum $X + Y$.
- The mean and covariance of $AX + b$, for any distribution.
  {ref}`gaussian-affine-transform` relies on this.
- Which divisor makes the sample covariance unbiased, for independent,
  identically distributed samples.

## Numerical considerations

## Implementation

## Examples

## Exercises

:::{exercise} HW 1 §1.A
:label: random-vector-moments-ex-hw1-1a
:nonumber:

ROB 530 [Homework 1][hw1], §1.A: linearity of expectation for three
continuous random variables, from the definition in terms of the joint
density, without assuming independence.
:::

## See also

- {ref}`multivariate-gaussian`: a distribution fully described by these two
  moments
- {ref}`gaussian-affine-transform`: how the mean and covariance change under
  $x \mapsto Fx + b$, by the same kind of argument
- {ref}`gaussian-mle`: the same estimates derived as the best Gaussian fit,
  and a different answer to the $n$ vs. $n - 1$ question
- {ref}`gaussian-sampling`: sample statistics are how a sampler is validated
- {ref}`streaming-moments`: the same estimates one sample at a time, and
  merged across data sets
- {ref}`correlation`: the covariance normalized to a scale-free measure

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

[hw1]: https://github.com/UMich-CURLY-teaching/UMich-ROB-530-public/blob/main/homework/homework-01/NA568_HW1_W22.pdf
