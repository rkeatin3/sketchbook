(tracking-roadmap)=
# Tracking roadmap

The plan for the multi-object tracking work: what to build, in what order, and
what to read along the way. This page lists topics and open questions. The
derivations and the design decisions are left to be worked out.

## Goal

A multi-object tracker whose core pieces can be swapped, so different
approaches can be compared on the same data:

- **Data association:** greedy, global nearest neighbor (GNN), probabilistic
  (JPDA)
- **Estimator:** Kalman-family filters, and later a factor graph (fixed-lag
  smoothing)
- **Tracking method:** single-hypothesis, multi-hypothesis (MHT), random
  finite sets (PHD, LMB, PMBM)
- **Motion models:** constant velocity, coordinated turn, and mixtures (IMM)
- **Measurement models:** one per sensor type (radar range/bearing/range-rate,
  camera bearing, lidar boxes)

### The pieces aren't independent

Treating these as independent plug-ins breaks down in places. Working out
where it breaks is part of the exercise:

- **The tracking method sits above the other choices.** GNN commits to one
  association per scan, JPDA averages over associations, MHT keeps a tree of
  association hypotheses, and RFS filters mostly fold association and track
  management into the filter itself. "Swap the association" means something
  different under each.
- **The estimator constrains association.** A recursive filter commits to its
  associations, while a fixed-lag smoother can revisit them. JPDA needs an
  estimator that accepts a probability-weighted update.
- **IMM is partly a motion model and partly an estimator.**

Open design questions:

- What is the smallest interface the association layer needs from the
  estimator?
- Which choices should be swappable at compile time (concepts, policies) and
  which at runtime (type erasure, `std::variant`)? This is where the
  `strategy`, `policy_based`, and `type_erasure` patterns get used for real.

### Other concerns to cover eventually

- Gating, kept separate from association
- Track management: initiation, confirmation, deletion
- Clutter and detection-probability models
- Asynchronous and out-of-sequence measurements
- Coordinate frames, sensor extrinsics, and ego-motion compensation
- Fusion architecture: central measurement fusion vs. track-to-track fusion
  (and what to do about unknown cross-correlation)
- Point targets vs. extended targets
- Evaluation: filter consistency (NEES, NIS), multi-target error (OSPA,
  GOSPA), and the MOT benchmark metrics (MOTA, HOTA)

## Phases

Each phase adds one main idea. Start in 2D with synthetic data.

0. **Foundations and simulator.** Gaussian sampling, Mahalanobis distance, and
   a 2D scenario simulator with known ground truth, configurable motion and
   measurement noise, missed detections, and clutter. Probably partly in
   `src/common/`, since kalman and factor_graphs use the same tools.
1. **Linear Kalman filter** with a constant-velocity model, validated with
   NEES/NIS against the simulator.
2. **Nonlinear measurements:** EKF and UKF with a polar (radar-like)
   measurement model.
3. **Gating and GNN,** including a hand-written assignment solver (Hungarian
   or auction).
4. **Track management.**
5. **Probabilistic and multi-hypothesis association:** JPDA, then MHT.
6. **Random finite sets:** Poisson point processes, then GM-PHD, then LMB or
   PMBM.
7. **3D and real sensors:** SO(3)/SE(3) from `transforms`, ego-motion, and a
   factor-graph estimator.
8. **Real data,** and later learned detectors feeding the tracker.

### Transforms

SE(2) is enough for phases 0–6. SO(3)/SE(3), with exp/log and the Jacobians,
is needed before 3D sensor fusion and factor graphs.

### Simulator questions to work through

- Sampling from $\mathcal{N}(\mu, \Sigma)$: if $z \sim \mathcal{N}(0, I)$,
  what are the mean and covariance of $Az + b$? Which $A$ gives the $\Sigma$
  you want, and which factorization produces it cheaply?
- What is the rank of the process noise covariance from a discretized
  white-noise-acceleration model, and what does that mean for the
  factorization, or for whether you need to sample in the full state space at
  all?
- Where does measurement noise enter? Adding Gaussian noise in sensor
  coordinates (range, bearing) has consequences in Cartesian space.
- Validate with matched models first, then mismatch them deliberately (e.g.
  the target maneuvers while the filter assumes constant velocity).
- Make the RNG seeded and explicit, so any failing scenario can be replayed.

### Visualization

Figures to aim for: covariance ellipses over time, NEES/NIS against their
$\chi^2$ bounds, the effect of chosen $Q$ and $R$ values (e.g. lag from a very
small $Q$), and tracks forming and dying in clutter.

## Reading

- Bar-Shalom, Li, Kirubarajan, *Estimation with Applications to Tracking and
  Navigation*: the classical foundation
- Blackman & Popoli, *Design and Analysis of Modern Tracking Systems*: GNN,
  MHT, practical engineering
- Särkkä & Svensson, *Bayesian Filtering and Smoothing* (2nd ed., free PDF):
  KF, EKF, UKF, and smoothers
- Chalmers, *Multi-Object Tracking for Automotive Systems* (edX): follows
  roughly phases 3–6 of this roadmap
- Mahler, *Statistical Multisource-Multitarget Information Fusion*: RFS
  theory (dense; use as a reference)
- Solà et al., "A micro Lie theory for state estimation in robotics", and
  Barfoot, *State Estimation for Robotics* (2nd ed., free): transforms
- Dellaert & Kaess, *Factor Graphs for Robot Perception*
- Stone Soup (Python tracking framework): for comparing designs and as a test
  oracle

## Datasets

Datasets that ship ready-made detections from several sensor types are rare.
The closest:

- **nuScenes:** camera, lidar, and radar (point detections with Doppler).
  Public detector outputs exist from the tracking challenge baselines and
  CenterPoint. The best fit.
- **MAN TruckScenes:** 4D radar, lidar, and camera, in nuScenes format
- **View-of-Delft:** 4D radar, lidar, and camera
- **RadarScenes:** labeled point-level radar detections; good for radar-only
  and extended-target work
- **aiMotive:** long-range radar, lidar, and camera
- **KITTI tracking:** lidar and camera, with public PointRCNN detections
  (AB3DMOT); old but a common baseline
- **MOTChallenge:** camera only, but the standard public-detections benchmark

Raw sensor data in nuScenes and TruckScenes allows swapping in learned
detectors later.
