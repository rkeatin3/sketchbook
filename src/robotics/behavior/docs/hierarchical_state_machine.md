(hierarchical-state-machine)=
# Hierarchical state machine

A state machine whose states can contain other states. An event that a
substate doesn't handle passes up to its superstate, so behavior shared by
many states is written once. It is the main idea of Harel's statecharts.

## Intuition

## Prerequisites

- {ref}`finite-state-machine`

## Model

_To work out:_

- State explosion: why a flat machine's transition count grows when an
  event applies to many states, and how nesting fixes it.
- How an event is dispatched up the hierarchy, and what happens when no
  state handles it.
- The order of exit and entry actions on a transition between states in
  different branches, and the role of their least common ancestor.
- Shallow and deep history: what each restores when a superstate is
  re-entered.
- Orthogonal regions: what they add, and whether the toy problem needs
  them.

## Implementation

Design questions, from the {ref}`behavior-plan`:

- How is the hierarchy written down: nested types, a parent table, or
  something else?
- Does the engine extend the flat engine, or replace it?
- How are entry and exit actions and history tested without toy-problem
  logic?

## Examples

- The toy problem on this engine: step 4 of the {ref}`behavior-plan`.
- {cite:t}`harel1987`: the original examples, a digital watch among them.
- {cite:t}`samek2008`, Ch. 4: a hierarchical event processor in C and C++.

## Exercises

% TODO: convert to titled {exercise} blocks once sphinx-exercise is enabled
% in docs/conf.py.

1. Redraw the patrol-and-recharge machine with superstates. How many
   transitions does the low-battery interrupt need now?
2. Work out, by hand, the sequence of exit and entry actions for one
   transition between two branches of your diagram.
3. _Coding:_ Test that resuming after a recharge returns to the right
   substate, with shallow and with deep history.

## See also

- {ref}`finite-state-machine`: the flat machine this extends
- {ref}`behavior-tree`: handles the same interrupt with priority instead of
  hierarchy
- {ref}`state-machines-vs-behavior-trees`: the comparison

## References

- {cite:t}`harel1987`: statecharts.
- {cite:t}`samek2008`, Ch. 2 and 4: UML state machine semantics, and an
  implementation.
- {cite:t}`colledanchise2018`, §2.2: hierarchical state machines compared
  with behavior trees.
