(behavior-plan)=
# Behavior plan

The plan for the behavior module: three decision-making structures, each as a
generic engine, compared on the same toy problems. It lists topics, decisions
made so far, and questions to work through. The designs and the code are left
to be worked out.

## Goal

Implementations of finite state machines, hierarchical state machines, and
behavior trees where the decision structure is separate from the business
logic, and a comparison that shows when each structure is the right one.

The test of the separation: the machine (or tree) can be tested without the
business logic, by feeding it events or ticks and checking what it does, and
the business logic can be tested without the machine.

## Decisions so far

- **Generic engines.** Each structure is an engine that knows nothing about
  any one problem. The toy problems are clients of the engines, in
  `examples/`.
- **The same toy problem on all three**, so the comparison is about structure
  and not about different problems.
- **Self-contained.** The toy problems run in their own minimal world with
  console output, so they don't wait on the tracking simulator.
- **One world per toy problem, shared.** Each toy problem's world, actions,
  and conditions are their own library target in `examples/`, which every
  engine's example for that problem depends on, not code copied into each
  example.
- **New vocabulary goes in the glossary.** Terms like tick, blackboard,
  guard, superstate, and history are introduced with `{term}` and added to
  the {doc}`glossary </docs/glossary>` as the articles are written.

## Toy problems

**Primary: patrol and recharge.** An agent in a small grid world patrols a
loop of waypoints, investigates when it detects something, and heads to a
charger when its battery runs low, then resumes what it was doing. It has the
features the structures handle differently:

- an interrupt with priority over everything (low battery)
- resuming after the interrupt (history)
- a task with retries and a fallback (investigate, give up after a few tries)
- subtasks that recur in several places (go to a location)

Any setting with these features works as well; a game character guarding an
area is the same problem.

**Contrast: a problem that favors a state machine.** Explicit modes with a
strict lifecycle, where history matters and there's little to react to.
Candidates are in Open questions.

## Articles

| Article | Covers |
|---|---|
| {ref}`finite-state-machine` | The formal model, why implementations tangle, and a generic engine that keeps the concerns separate |
| {ref}`hierarchical-state-machine` | Superstates, entry and exit order, history, and state explosion |
| {ref}`behavior-tree` | Tick semantics, node statuses, composites and decorators, the blackboard |
| {ref}`state-machines-vs-behavior-trees` | The toy problems on all three, and when to use which |

## Steps

| Step | Work | Article |
|---|---|---|
| 0 | The toy problem's world, actions, and conditions, with no decision logic | {ref}`state-machines-vs-behavior-trees` |
| 1 | The finite state machine engine and its tests | {ref}`finite-state-machine` |
| 2 | The toy problem on the finite state machine | {ref}`finite-state-machine` |
| 3 | Hierarchy: superstates, entry and exit, history | {ref}`hierarchical-state-machine` |
| 4 | The toy problem on the hierarchical machine | {ref}`hierarchical-state-machine` |
| 5 | The behavior tree engine and its tests | {ref}`behavior-tree` |
| 6 | The toy problem on the behavior tree | {ref}`behavior-tree` |
| 7 | The contrast problem on all three structures, like the primary problem | {ref}`state-machines-vs-behavior-trees` |
| 8 | The comparison write-up | {ref}`state-machines-vs-behavior-trees` |

Step 0 comes first because it fixes the business logic that every engine
drives, which is what makes the separation testable.

## Open questions

- **How a state machine engine represents the structure.** A transition table
  as data, states as types in a `std::variant` with handlers per (state,
  event) pair, or something else? What does each make easy to read, to check
  at compile time, and to test?
- **How states carry data.** Shared context for all states, or data that
  exists only while its state is active? What does each prevent?
- **Where guards and actions live,** and what they're allowed to touch.
- **Events and ticks.** A state machine reacts to events; a behavior tree is
  ticked. How does each engine get its inputs, and how does the toy problem's
  world drive both the same way?
- **Behavior tree nodes.** Dynamic polymorphism, type erasure, or a static
  tree built from templates? What does each cost in readability and in
  building a tree at run time?
- **The blackboard.** Typed or untyped, global or scoped to a subtree?
- **The contrast problem.** A track's lifecycle in the tracker (tentative,
  confirmed, coasting, deleted), a connection protocol, or another?
- **Visualization.** Printing the active state or the tick path is enough for
  the console. Is a diagram export (Graphviz) worth adding?
