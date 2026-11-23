(streaming-moments)=
# Streaming and merged moments

Accumulating a mean and covariance one sample at a time, and combining the
summaries of separate data sets without the raw samples. Sensor statistics,
NEES averages over Monte Carlo runs, and parallel reductions all need one or
both.

## Intuition

## Prerequisites

- {ref}`random-vector-moments`

## Derivation

_To prove:_

- Welford's update: the new mean and the new sum of outer products of
  deviations, from the old ones and one new sample.
- Merging two summaries (count, mean, and that sum of outer products) into the
  summary of the combined data.
- Recovering $\sum_i x_i x_i^\top$ from a count, a mean, and a biased sample
  covariance.
- Merging is associative in exact arithmetic, so the result doesn't depend on
  how the data was split. What changes in floating point?

## Numerical considerations

## Implementation

Questions to settle:

- What state does an accumulator hold, and which of the biased and unbiased
  covariances does it report?
- Should `Gaussian::Fit` be built on the accumulator, or stay two-pass?
- What does merging with an empty summary do, and how about a summary of one
  sample?
- Test oracles: what should merging two halves give, and what should it match
  for any split point and any order? With what tolerance?
- Is the merge accurate when one count is much larger than the other?

## Examples

## Exercises

:::{exercise} HW 1 §1.C
:label: streaming-moments-ex-hw1-1c
:nonumber:

ROB 530 [Homework 1][hw1], §1.C: two data sets known only by count, mean,
and biased covariance. Recover each $\sum x x^\top$, then the combined mean
and covariance.
:::

:::{exercise} Coding
:label: streaming-moments-ex-coding
:nonumber:

The same numbers through the merge, checked against the hand
answer.
:::

:::{exercise} Coding
:label: streaming-moments-ex-coding-2
:nonumber:

Feed values with a large offset (e.g. $10^8 + \epsilon$) into
the naive one-pass formula and into Welford's update, and compare both with
the two-pass result.
:::

## See also

- {ref}`random-vector-moments`: the batch estimates these must agree with
- {ref}`gaussian-mle`: the biased estimate is the maximum-likelihood one
- {ref}`mahalanobis-distance`: NEES and NIS are averaged across runs in this
  way

## References

- {cite:t}`welford1962`: the one-pass update for sums of squares and products
  that avoids catastrophic cancellation.
- {cite:t}`chan1983`: pairwise merging, with error analysis of the one-pass
  and two-pass forms.
- Wikipedia, [Algorithms for calculating variance](https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance):
  the naive formula and why it fails, Welford's method, and the parallel
  (merge) algorithm, including the covariance versions. The free route to the
  two papers above, which are paywalled.

[hw1]: https://github.com/UMich-CURLY-teaching/UMich-ROB-530-public/blob/main/homework/homework-01/NA568_HW1_W22.pdf
