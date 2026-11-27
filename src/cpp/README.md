(area-cpp)=
# Modern C++

The language itself as a subject: what each newer feature is for, the idioms
experienced C++ programmers reach for, and which older idioms the newer
standards replace. Each topic gets a short article and a small, tested
experiment, and links to the places in this repository that use it, since
seeing a feature in real code is what makes it stick.

- {ref}`module-cpp-features`: language and library features, by standard
  (C++20, C++23, and C++26 to watch).
- {ref}`module-cpp-idioms`: idioms, older and newer, and what replaces the
  older ones.

Both hubs keep an inventory with a "Used in" column. An empty cell is
something still to learn; a filled one points to a worked example. The
{doc}`patterns </src/patterns/README>` area covers the larger-scale designs
(CRTP, type erasure, policy-based design) that many of these idioms build on.

Reviews check changes against both inventories: see
`.claude/skills/review/criteria.md`.

```{toctree}
:maxdepth: 1

features/README
idioms/README
```
