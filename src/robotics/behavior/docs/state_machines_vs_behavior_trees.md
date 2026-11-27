(state-machines-vs-behavior-trees)=
# State machines vs. behavior trees

The same toy problems implemented on a flat state machine, a hierarchical
state machine, and a behavior tree, and what the comparison shows about when
to use each.

## Intuition

## Prerequisites

- {ref}`finite-state-machine`
- {ref}`hierarchical-state-machine`
- {ref}`behavior-tree`

## The toy problems

See the {ref}`behavior-plan` for the patrol-and-recharge problem and the
contrast problem. The patrol-and-recharge world, actions, and conditions are
written once (step 0), with no decision logic, and each engine drives them.

## Comparison

_To work out, from the implementations:_

- Expressiveness: what {cite:t}`colledanchise2018` claim about how behavior
  trees relate to state machines and other structures (§2.1–2.2, Ch. 6), and
  under what assumptions.
- Adding a behavior: what changes in each implementation when a new task
  or a new interrupt is added?
- Reactivity: how each handles the low-battery interrupt.
- History: how each resumes what it was doing after the recharge.
- Retries and fallback: how each handles "give up after three tries".
- Reuse: how each reuses "go to a location".
- Readability: which is easier to follow for each toy problem, and why.
- Testing: how each engine and each client is tested.
- When to use which, as a short list of rules of thumb.

## Implementation

The comparison's evidence, in `examples/`: one target per toy problem and
structure.

## Examples

- {cite:t}`colledanchise2018`, Ch. 2: behavior trees compared with state
  machines, subsumption, and decision trees, with advantages and
  disadvantages (§2.6).

## Exercises

% TODO: convert to titled {exercise} blocks once sphinx-exercise is enabled
% in docs/conf.py.

1. _Coding:_ Add a new interrupt to the toy problem (an obstacle, a call for
   help) in all three implementations, and record what changed in each.
2. _Coding:_ Implement the contrast problem on all three structures.

## See also

- {ref}`finite-state-machine`, {ref}`hierarchical-state-machine`, and
  {ref}`behavior-tree`
- {ref}`behavior-plan`

## References

- {cite:t}`colledanchise2018`, Ch. 2 and 6: the comparison, informal and
  formal.
- {cite:t}`iovino2022`: where behavior trees are used in practice, and why.
