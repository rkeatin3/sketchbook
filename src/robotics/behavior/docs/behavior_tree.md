(behavior-tree)=
# Behavior tree

A tree of nodes that is ticked repeatedly. Each tick flows from the root to
the leaves and each node reports Success, Failure, or Running, so priorities
and fallbacks are expressed by the tree's shape rather than by explicit
transitions.

## Intuition

## Prerequisites

- {ref}`finite-state-machine`, for contrast
- The composite pattern, in {doc}`patterns </src/patterns/README>`

## Model

_To work out:_

- Tick semantics: what a tick is, and what each of the three statuses
  means to a node's parent.
- The control flow nodes: Sequence, Fallback (Selector), and Parallel, and
  what each returns for each combination of its children's statuses.
- Decorators (invert, retry, timeout), and conditions versus actions as
  leaves.
- Reactivity: what happens to a Running action when a higher-priority
  branch's condition changes on the next tick, and how the action is
  stopped.
- Where memory lives: a node that remembers which child was running, and
  the blackboard. What each costs in reactivity.
- Why a behavior tree is modular in a way a state machine isn't: what a
  subtree needs to know about its parent.

## Implementation

Design questions, from the {ref}`behavior-plan`:

- Dynamic polymorphism, type erasure, or a tree built from templates at
  compile time?
- How does an action that takes many ticks keep its progress, and how is it
  halted?
- Typed or untyped blackboard, and who may write to it?
- How are the control flow nodes tested without any toy-problem leaves?

## Examples

- The toy problem on this engine: step 6 of the {ref}`behavior-plan`.
- [BehaviorTree.CPP](https://www.behaviortree.dev/): the library used by
  Nav2. A design to study, not to use.
- {cite:t}`colledanchise2018`, §1.4–1.5: behavior trees for Pac-Man and for
  a mobile manipulator, built from scratch.

## Exercises

% TODO: convert to titled {exercise} blocks once sphinx-exercise is enabled
% in docs/conf.py.

1. Draw the patrol-and-recharge problem as a behavior tree. Where does the
   low-battery check go, and why there?
2. Trace two ticks of your tree by hand: one where the battery is fine, then
   one where it has just run low while the agent is investigating.
3. _Coding:_ Test the Sequence and Fallback nodes with stub children that
   return scripted statuses.
4. _Coding:_ Make "go to a location" a subtree and reuse it for patrolling
   and for recharging.

## See also

- {ref}`finite-state-machine` and {ref}`hierarchical-state-machine`: the
  alternatives
- {ref}`state-machines-vs-behavior-trees`: the comparison

## References

- {cite:t}`colledanchise2018`, Ch. 1 and 3: the classical formulation, and
  design principles (§3.6 on memory nodes).
- {cite:t}`iovino2022`: how behavior trees are used in robotics, and their
  variations.
