(module-behavior)=
# Behavior

How a system decides what to do next: finite state machines, hierarchical
state machines, and behavior trees, each built as a generic engine and
compared on the same toy problem.

**Status:** not started ·
[source](https://github.com/rkeatin3/sketchbook/tree/main/src/robotics/behavior)

## Why it matters

Every robot has a layer above estimation and control that sequences tasks,
reacts to events, and recovers from failure. In most code that layer is a
state machine tangled into the business logic: transitions are decided inside
the actions, so the machine's structure exists only implicitly. This module is
about keeping the decision structure separate and visible, and about when a
behavior tree is the better structure.

## Prerequisites

- Modern C++: `std::variant` and `std::visit`, concepts
- Design patterns: state, composite, and strategy (in
  {doc}`patterns </src/patterns/README>`)

## Roadmap

See the {ref}`behavior-plan` for the steps, decisions, and open questions.

1. A generic finite state machine engine, with structure, guards, actions, and
   context kept separate.
2. A hierarchical state machine: superstates, entry and exit actions, history.
3. A generic behavior tree: tick semantics, composites, decorators, and a
   blackboard.
4. The same toy problem on all three, and a written comparison.

## Articles

```{toctree}
:maxdepth: 1

docs/plan
docs/finite_state_machine
docs/hierarchical_state_machine
docs/behavior_tree
docs/state_machines_vs_behavior_trees
```

## Related modules

- {doc}`Multi-Object Tracking </src/robotics/tracking/README>`: a track's
  lifecycle is a small state machine
- {doc}`Design Patterns </src/patterns/README>`

## References

- {cite}`colledanchise2018`: behavior trees, and how they compare to state
  machines
- {cite}`harel1987`: statecharts, the origin of hierarchical state machines
- {cite}`samek2008`: hierarchical state machines in practice, with a framework
  design to study
- {cite}`iovino2022`: a survey of behavior trees in robotics
