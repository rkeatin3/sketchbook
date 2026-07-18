# benchmarks/

Evaluations against open datasets. The purpose is honest measurement: an
implementation is not finished until it has been run against data someone else
collected.

## Targets

**Robotics systems** — KITTI (odometry), EuRoC MAV (visual-inertial SLAM)

**Nonlinear system identification** — from
[nonlinearbenchmark.org](https://www.nonlinearbenchmark.org): Silverbox,
Coupled Electric Drives, NanoDrone

Datasets are fetched into `//data` by `tools/fetch_datasets.sh` and are not
committed.
