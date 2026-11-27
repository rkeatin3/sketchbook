(finite-state-machine)=
# Finite state machine

A system that is always in exactly one of a finite set of states, and moves
between them in response to events. It makes a system's modes and the legal
moves between them explicit.

## Intuition

## Prerequisites

- `std::variant` and `std::visit`
- The state pattern, in {doc}`patterns </src/patterns/README>`

## Model

_To work out:_

- The formal definition: what the parts of a finite state machine are, and
  what makes one deterministic.
- The difference between a Mealy and a Moore machine, and which one the
  toy problem's actions suggest.
- The four concerns an implementation has to represent: structure,
  guards, actions, and data. Which of them a typical `switch`-on-an-enum
  implementation mixes together, and what that costs when a state or an event
  is added.
- Why the textbook state pattern, where each state object picks its
  successor, scatters the structure.
- What it means for a machine to be complete (every state has an answer for
  every event), and how an engine could check it.

## Implementation

Design questions, from the {ref}`behavior-plan`:

- How is the structure written down so it can be read in one place?
- How are guards and actions attached to transitions without the engine
  knowing what they do?
- Can an invalid transition, or an unhandled (state, event) pair, be caught
  at compile time?
- How do the engine's tests check it without any toy-problem logic?

## Examples

- The toy problem on this engine: step 2 of the {ref}`behavior-plan`.
- [Boost.SML](https://boost-ext.github.io/sml/): a transition-table design to
  study, not to use.
- {cite:t}`samek2008`, Ch. 3 and 5: standard state machine implementations
  and state patterns in C and C++, with their trade-offs.

## Exercises

% TODO: convert to titled {exercise} blocks once sphinx-exercise is enabled
% in docs/conf.py.

1. Draw the patrol-and-recharge problem as a flat state machine. Count the
   transitions the low-battery interrupt needs.
2. _Coding:_ Write the engine's tests first, against a machine with three
   states and no business logic.
3. _Coding:_ Add a new state to the toy problem, and list every file the
   change touches. A well-separated design keeps that list short.

## See also

- {ref}`hierarchical-state-machine`: what flat machines lack when an event
  applies to many states
- {ref}`behavior-tree`: the alternative structure
- {ref}`state-machines-vs-behavior-trees`: the comparison

## References

- {cite:t}`samek2008`, Ch. 3 and 5: implementation techniques.
- {cite:t}`colledanchise2018`, §1.2 and §2.1: the case against finite state
  machines, from the behavior tree side.
