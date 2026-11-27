(module-patterns)=
# Design Patterns

Patterns from Gamma et al.'s *Design Patterns* and Iglberger's *C++ Software
Design*, implemented in modern C++. Where possible, each one is motivated by a real need in the robotics
modules rather than a toy example. The point is to show how modern C++ changes
the classical formulations: type erasure, `std::variant` with `std::visit`, and
concepts replace much of the inheritance-heavy design.

Each pattern gets one article, `src/patterns/<pattern>/README.md`, covering the
problem it solves, the classical formulation, the modern C++ formulation, the
trade-offs, and where it appears in this repository.

`strategy`, `crtp`, and `type_erasure` are the natural starting points, since
they recur throughout the robotics modules. In particular, the swappable
components of the {doc}`tracker </src/robotics/tracking/README>` exercise all
three.

Several others have a natural home too:

- `state` for a track's lifecycle (tentative, confirmed, deleted). The
  classical polymorphic form is the baseline, and a closed set of states is
  where `std::variant` and `std::visit` offer the modern alternative.
- `prototype` where hypotheses are polymorphic, such as trackers that keep a
  different motion model per hypothesis. Plain particles are value types,
  copied without any `clone()`, which is the contrast to draw with value
  semantics and type erasure.
- `adapter` for sensor and dataset interfaces.
- `iterator` for custom ranges: conforming iterators, views, and
  `std::generator`.
- `external_polymorphism` as the stepping stone to `type_erasure`.

The rest are catalogue entries with no robotics use planned yet, so an empty
"Used in" cell for them isn't a to-do.

The table is ordered by how often each pattern is expected to recur here, a
guess to revisit as the "Used in" column fills in.

| Pattern | Status | Used in |
|---|---|---|
| strategy | — | |
| crtp | — | |
| type_erasure | — | |
| external_polymorphism | — | |
| visitor | — | |
| observer | — | |
| decorator | — | |
| adapter | — | |
| bridge | — | |
| prototype | — | |
| state | — | |
| iterator | — | |
| builder | — | |
| factory | — | |
| template_method | — | |
| policy_based | — | |
| command | — | |
| composite | — | |
| facade | — | |
| chain_of_responsibility | — | |
| proxy | — | |
| memento | — | |
| mediator | — | |
| flyweight | — | |
| singleton | — | |

```{toctree}
:maxdepth: 1
```
