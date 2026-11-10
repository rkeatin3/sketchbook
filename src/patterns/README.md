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

| Pattern | Status | Used in |
|---|---|---|
| strategy | — | |
| crtp | — | |
| type_erasure | — | |
| visitor | — | |
| observer | — | |
| decorator | — | |
| builder | — | |
| factory | — | |
| template_method | — | |
| policy_based | — | |
| command | — | |
| composite | — | |
| singleton | — | |

```{toctree}
:maxdepth: 1
```
