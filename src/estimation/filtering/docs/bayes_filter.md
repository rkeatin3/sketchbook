(bayes-filter)=
# The Bayes filter

The recursion behind every filter in this module: predict the belief through
a motion model, then correct it with a measurement through
{ref}`bayes-rule`. On a finite state space the belief is a vector, and the
result is the histogram (discrete Bayes) filter, implemented here. The Kalman
filter is the same recursion with Gaussian beliefs.

## Intuition

## Prerequisites

- {ref}`discrete-distribution`
- {ref}`bayes-rule`

## Derivation

_To prove:_

- The prediction step, from the law of total probability and the Markov
  assumption on the state.
- The update step, from Bayes' rule and the conditional independence of the
  measurement from the past, given the current state.
- Together, the belief recursion. Name which assumption each step uses, and
  what goes wrong if it fails.
- On a finite state space, prediction is multiplication by a column-stochastic
  transition matrix, and it preserves normalization.
- Deterministic motion on a cycle is a permutation (a circular shift).

{cite:t}`thrun2005` writes the normalizer as $\eta$, which ROB 530 lecture
note 1 uses for the information vector. Settle the symbol in {ref}`notation`
before writing the derivation.

## Numerical considerations

## Implementation

Questions to settle:

- The belief is a distribution from {ref}`discrete-distribution`. Is the
  number of cells a template parameter?
- Prediction with a dense $N \times N$ transition matrix, or with a
  convolution kernel when motion is shift-invariant? What does each cost, and
  which handles the wraparound of a circular world?
- How are the motion model (with its control input) and the measurement
  model passed in?
- Which parts become the estimator interface that the Kalman filter later
  shares (see the module roadmap), and which stay specific to grids?

Runnable target: the circular world from the Exercises, in `examples/`.

## Examples

- ROB 530 `Markov_localization_1Dexample` in the course's
  [code examples][code] (MATLAB and Python): 1D Markov localization on a
  grid.

## Exercises

:::{exercise} HW 1 §2.B
:label: bayes-filter-ex-hw1-2b
:nonumber:

ROB 530 [Homework 1][hw1], §2.B: one predict–update cycle by hand for a
robot painting an object. Choose and justify the prior.
:::

:::{exercise} HW 1 §2.C
:label: bayes-filter-ex-hw1-2c
:nonumber:

ROB 530 [Homework 1][hw1], §2.C: localization on a circular world with
landmarks. _Coding:_ the main target for this article. Report the final
belief and check it against a hand calculation of the first step.
:::

:::{exercise} Thrun, Ch. 2
:label: bayes-filter-ex-thrun-ch2
:nonumber:

{cite:t}`thrun2005`, Ch. 2 exercises: Bayes filter calculations.
:::

## See also

- {ref}`bayes-rule`: the update step
- {ref}`discrete-distribution`: the belief representation
- {ref}`gaussian-marginal-conditional`: the Gaussian update that the Kalman
  filter uses
- {ref}`gaussian-affine-transform`: the Gaussian prediction step

## References

- {cite:t}`thrun2005`, §2.4 and §4.1: the Bayes filter and the histogram
  filter.
- {cite:t}`sarkka2023`: the Bayesian filtering equations in general state
  spaces.
- {cite:t}`ghaffari2022`: ROB 530 homework 1 and the Markov localization
  example.

[hw1]: https://github.com/UMich-CURLY-teaching/UMich-ROB-530-public/blob/main/homework/homework-01/NA568_HW1_W22.pdf
[code]: https://github.com/UMich-CURLY-teaching/UMich-ROB-530-public/tree/main/code-examples
