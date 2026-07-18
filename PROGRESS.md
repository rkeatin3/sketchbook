# Progress

Running log of what is done and what is next. Updated as work lands, not
retroactively.

## Status legend

`—` not started  ·  `~` in progress  ·  `x` complete

## Infrastructure

- [x] Repository scaffolded (Bazel + bzlmod, C++23)
- [x] clang-format / clang-tidy configured
- [x] `//src/common:types` seed target compiling and tested
- [ ] CI (build + test on push)
- [ ] `compile_commands.json` generation for editor tooling
- [ ] `tools/fetch_datasets.sh` implemented

## Robotics modules

| Module | Theory doc | Implementation | Tests | Examples |
|---|---|---|---|---|
| transforms      | — | — | — | — |
| kalman          | — | — | — | — |
| factor_graphs   | — | — | — | — |
| tracking        | — | — | — | — |
| planning        | — | — | — | — |
| controls        | — | — | — | — |
| trajectory_opt  | — | — | — | — |

## Design patterns

None started. Order is flexible; `strategy`, `crtp`, and `type_erasure` are
the natural entry points since they recur throughout the robotics modules.

## Projects

| Project | Status | Depends on |
|---|---|---|
| diff_drive_2d | — | transforms, controls |
| quadrotor     | — | transforms, controls, trajectory_opt |
| slam_explorer | — | transforms, factor_graphs, planning |

## Next up

1. `transforms`: derive SO(3) exp/log, implement, test against Eigen's
   `AngleAxis` as an oracle.
2. `transforms`: SE(3), adjoints, and the left/right Jacobians needed later
   by the EKF and factor graph modules.
3. Seed `papers/README.md` from accumulated email links.
