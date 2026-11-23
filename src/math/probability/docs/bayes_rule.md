(bayes-rule)=
# Bayes' rule

Turning a model of how data depends on a hypothesis, $p(z \mid x)$, into a
belief about the hypothesis given the data, $p(x \mid z)$. Every update step in
the {ref}`bayes-filter` and the Kalman family applies this rule.

## Intuition

## Prerequisites

- {ref}`discrete-distribution`

## Derivation

_To prove:_

- The law of total probability, from marginalization and the chain rule.
- Bayes' rule, and its form with every term also conditioned on a third
  variable, $p(x \mid z, u)$.
- The evidence $p(z)$ is only a normalizer: normalizing
  likelihood × prior gives the same posterior, so the evidence never needs
  to be computed on its own.
- Two measurements that are conditionally independent given $x$ can be
  processed one at a time, in either order, and give the same posterior as
  processing both together.
- A zero prior stays zero after any update.

## Numerical considerations

## Implementation

Questions to settle:

- An update is an elementwise product followed by normalization. Where does
  the likelihood vector come from, given a sensor model stored as a table
  $p(z \mid x)$?
- What should happen when every entry of the product is zero (the measurement
  is impossible under the prior)?
- Is the update a free function on distributions, or a member?

## Examples

ROB 530 [lecture note 1][note1], Example 1: a diagnostic test, worked in full.

## Exercises

:::{exercise}
:label: bayes-rule-ex-hw1-2a

ROB 530 [Homework 1][hw1], §2.A: a diagnostic test, then which error rate
is worth reducing.
:::

:::{exercise}
:label: bayes-rule-ex-hw1-3

ROB 530 [Homework 1][hw1], §3: a three-outcome prior updated by one
observation.
:::

:::{exercise}
:label: bayes-rule-ex-coding

_Coding:_ redo {ref}`bayes-rule-ex-hw1-2a` and {ref}`bayes-rule-ex-hw1-3`
with the update from the Implementation section, and check the results
against the hand calculations in a test.
:::

:::{exercise}
:label: bayes-rule-ex-coding-2

_Coding:_ check the sequential-update result numerically: two
measurements in either order, and both together.
:::

## See also

- {ref}`discrete-distribution`: the rules this one is built from
- {ref}`bayes-filter`: Bayes' rule is its update step
- {ref}`gaussian-product`: the update for Gaussian prior and likelihood, as a
  product of densities

## References

- {cite:t}`blitzstein2019`, Ch. 2: Bayes' rule, the law of total
  probability, and conditioning on extra information.
- {cite:t}`thrun2005`, §2.2–2.3: Bayes' rule with the normalizer
  $\eta$, and the robot-state example that leads into the Bayes filter.
- {cite:t}`ghaffari2022`, lecture note 1, §2: the posterior, likelihood,
  prior, and evidence.

[note1]: https://github.com/UMich-CURLY-teaching/UMich-ROB-530-public/blob/main/lecture-notes/01_Probability.pdf
[hw1]: https://github.com/UMich-CURLY-teaching/UMich-ROB-530-public/blob/main/homework/homework-01/NA568_HW1_W22.pdf
