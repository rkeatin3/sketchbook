(gaussian-marginal-conditional)=
# Marginalizing and conditioning Gaussians

Splitting a joint Gaussian over $(x, y)$ into the marginal of $x$ and the
conditional $p(x \mid y)$, and how conditioning relates to the Kalman update.

## Intuition

## Prerequisites

- {ref}`multivariate-gaussian`
- {ref}`gaussian-affine-transform`

## Derivation

_To prove:_

- The marginal of a joint Gaussian is Gaussian, and its parameters.
- The conditional $p(x \mid y)$ is Gaussian, and its parameters. What does it
  require of the covariance of $y$?
- How the conditional covariance compares with the marginal one, and what it
  depends on.
- The Kalman update as conditioning a joint Gaussian over state and
  measurement.

## Numerical considerations

## Implementation

Questions to settle:

- Conditioning when the observed block's covariance is singular.
- Re-checking that the conditional covariance is still symmetric positive
  semidefinite after the computation.

## Examples

## Exercises

:::{exercise} HW 1 §4
:label: gaussian-marginal-conditional-ex-hw1-4
:nonumber:

ROB 530 [Homework 1][hw1], §4: how the conditional variance compares with
the marginal one, and what it depends on.
:::

:::{exercise} Coding
:label: gaussian-marginal-conditional-ex-coding
:nonumber:

Reproduce the marginals and the conditional
$p(x_1 \mid x_2 = 0.9)$ in ROB 530 [lecture note 1][note1], Example 2,
with `Marginal` and `Condition`.
:::

## See also

- {ref}`gaussian-product`: the same update, written as a product of prior
  and likelihood densities
- {doc}`Filtering </src/estimation/filtering/README>`: the update step is
  conditioning on a measurement

## References

- {cite:t}`bishop2006`, §2.3.1–2.3.3: conditional and marginal Gaussians,
  and Bayes' theorem for linear Gaussian models. The classic derivation by
  completing the square.
- {cite:t}`murphy2022`, §3.2–3.3: the same results, and linear Gaussian
  systems.
- {cite:t}`barfoot2024`, Ch. 2: the derivation via Schur complements, in
  estimation notation.
- {cite:t}`barshalom2001`, Ch. 1: conditioning of jointly Gaussian vectors,
  which is the basis of its Kalman filter derivation.
- {cite:t}`sarkka2023`: Gaussian conditioning as used in Bayesian filtering.

[hw1]: https://github.com/UMich-CURLY-teaching/UMich-ROB-530-public/blob/main/homework/homework-01/NA568_HW1_W22.pdf
[note1]: https://github.com/UMich-CURLY-teaching/UMich-ROB-530-public/blob/main/lecture-notes/01_Probability.pdf
