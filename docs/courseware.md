(courseware)=
# Courseware

Free courses and open textbooks to pair with the modules in this wiki, and a
rough plan for using them. The repository stays the main effort. Courseware is
a check on understanding and a source of problems, not a substitute for
deriving things first.

Availability was checked on 2026-11-22. Course sites move; if a link has died,
search for the course name.

## Ground rules

1. **Attempt first.** Try the derivation or the problem before watching the
   lecture or reading the chapter, then compare. A lecture that hands over the
   derivation up front removes the work this repository exists to do.
2. **Every unit of courseware leaves an artifact:** an article, a test, or an
   example in the matching module. If it left nothing, it was consumption.
3. **One anchor at a time.** At most one course with real problem sets is in
   progress, plus lighter supplements (a text, a few lectures).
4. **Skim what is already known.** Estimation and perception material gets
   fast playback; the time goes to the homeworks and to whatever is surprising.
5. **Courses supply problems; the repository supplies the write-up.** Course
   homeworks are the practice problems. Results are written up in the module's
   articles, in my own words.
6. **Cite what was used.** When a result comes from a book or course notes, add
   it to `docs/references.bib` and cite it in the article.
7. **Keep the status table below and
   [PROGRESS.md](https://github.com/rkeatin3/sketchbook/blob/main/PROGRESS.md)
   current.**

## Estimation and perception

**Michigan ROB 530, Mobile Robotics: Methods and Algorithms.**
[Course site](https://curly.engin.umich.edu/teaching) ·
[public materials](https://github.com/UMich-CURLY-teaching/UMich-ROB-530-public)

- Format: recorded lectures (Winter 2022), slides, notes, example code, and
  homeworks. Programming in MATLAB, Python, Julia, or C++.
- Covers: probabilistic and geometric methods for mobile robots. The homeworks
  run from preliminaries through Kalman filtering and nonlinear filtering to
  Lie groups and the invariant EKF.
- Pairs with: probability, {doc}`filtering </src/estimation/filtering/README>`,
  {doc}`lie_groups </src/math/lie_groups/README>`.
- Role: the first anchor. Its companion text is Barfoot, *State Estimation for
  Robotics*.

**Stachniss lectures (University of Bonn).**
[Mobile robotics online course](https://www.ipb.uni-bonn.de/online-training-robotics/) ·
[Mobile Sensing and Robotics 2](https://www.ipb.uni-bonn.de/msr2-2021) ·
[Robot Mapping](https://www.ipb.uni-bonn.de/robot-mapping/)

- Format: YouTube lectures, slides, exercises, and short "5 Minutes with
  Cyrill" explainers.
- Covers: the Bayes filter, occupancy grids, least squares, pose-graph and
  landmark SLAM, robust least squares, bundle adjustment, camera geometry.
- Pairs with: {doc}`filtering </src/estimation/filtering/README>`,
  {doc}`factor_graphs </src/estimation/factor_graphs/README>`.
- Role: supplement. Use the short explainers for refreshers and the graph-SLAM
  lectures during the factor graph work.

**MIT 16.485, Visual Navigation for Autonomous Vehicles (Carlone).**
[OCW](https://ocw.mit.edu/courses/16-485-visual-navigation-for-autonomous-vehicles-vnav-fall-2020/)

- Format: slides and notes (Fall 2020) with labs. Whether lecture videos exist
  is unchecked.
- Covers: visual and visual-inertial odometry, place recognition, SLAM
  formulations and sparsity, factor graphs and marginalization.
- Pairs with: {doc}`factor_graphs </src/estimation/factor_graphs/README>`.
- Role: supplement during the factor graph work. It also recommends Barfoot.

**Georgia Tech Advanced Mobile Robotics (Dellaert).**
[Spring 2026 schedule](https://dellaert.github.io/26S-AMR/schedule.html)

- Format: public schedule with slides. Videos are unchecked. A Georgia Tech
  Fall 2026 syllabus also points to the
  [*Introduction to Robotics* book](https://www.roboticsbook.org/intro.html) and
  the [SLAM Handbook](https://github.com/SLAM-Handbook-contributors/slam-handbook-public-release).
- Covers: factor graphs and nonlinear least squares, IMU preintegration, scan
  matching, drone state estimation, continuous-time SLAM.
- Pairs with: {doc}`factor_graphs </src/estimation/factor_graphs/README>`.
- Role: reference for the factor graph work and for later IMU and LiDAR
  projects.

## Mechanics, planning, and control

**Modern Robotics (Lynch and Park, Northwestern).**
[Book and videos](http://modernrobotics.org)

- Format: free preprint PDF, free video lectures, software in Python, MATLAB,
  and Mathematica, and a simulator for the exercises. There is also a Coursera
  specialization (linked from the book site) that is listed as free to enroll;
  whether graded work is free is unchecked.
- Covers: configuration space, rigid-body motion with screw theory (twists and
  the product of exponentials), forward, inverse, and velocity kinematics,
  dynamics, trajectory generation, motion planning, robot control, grasping,
  wheeled mobile robots.
- Prerequisites: freshman-level physics, linear algebra, ODEs, and programming.
- Pairs with: {doc}`lie_groups </src/math/lie_groups/README>`. Its screw theory
  is built on Lie groups. It also gives a first pass at the planning and
  controls modules that don't exist yet.
- Role: the low-intensity parallel track for the mechanics and control gap.

**CMU 16-745, Optimal Control and Reinforcement Learning.**
[Course site](https://optimalcontrol.ri.cmu.edu/) ·
[lectures](https://optimalcontrol.ri.cmu.edu/lectures/)

- Format: lecture videos, slides, and code for each lecture. No required
  textbook. Julia. The lecture list varies by year.
- Covers: dynamics and stability, numerical optimization, LQR, convex MPC,
  trajectory optimization, rotations and quaternions in LQR, Kalman filters and
  duality, stochastic optimal control.
- Pairs with: {doc}`filtering </src/estimation/filtering/README>` (the
  estimation-control duality) and the optimization, controls, and trajectory
  optimization modules, once they exist.
- Role: the anchor for the control and optimization phase.

**Underactuated Robotics (Tedrake, MIT 6.832).**
[Notes](https://underactuated.mit.edu/) ·
[OCW 2022](https://ocw.mit.edu/courses/6-832-underactuated-robotics-spring-2022)

- Format: open online notes, YouTube lectures, and an OCW version with lecture
  videos.
- Covers: a computational approach to control design built on optimization and
  machine learning, with legged, flying, and manipulation examples.
- Prerequisites: not checked for the current offering. The 2009 syllabus
  assumed basic kinematics and dynamics and comfort with linear algebra and
  ODEs.
- Role: a later destination, after 16-745. Mine it for trajectory optimization
  and nonlinear control.

## Mathematical backbone

**Michigan ROB 501, Mathematics for Robotics (Grizzle).**
[Course page](https://grizzle.robotics.umich.edu/education/rob501)

- Format: free textbook PDF, a Fall 2018 lecture playlist, and a course GitHub
  with handouts and old exams.
- Covers: proof technique, abstract vector spaces, inner products, convergence,
  probability, estimation, and optimization.
- Role: remedial and theory backbone, used on demand rather than front to
  back. Its prerequisite course, ROB 101 (computational linear algebra), is
  also online.

## Gaps

- **Tracking.** None of the courses above covers multi-object tracking. It
  stays self-guided from texts and papers; see {ref}`tracking-roadmap`.
- **Optimization.** Boyd and Vandenberghe's *Convex Optimization* and the
  Stanford lectures are the likely fit for an optimization module. Unchecked.
- **Lie theory reading.** Solà, Deray, and Atchuthan, *A micro Lie theory for
  state estimation in robotics*, is the short reference to read alongside
  Phase 2.

## Plan

The phases follow the order of modules in
[PROGRESS.md](https://github.com/rkeatin3/sketchbook/blob/main/PROGRESS.md).
They overlap on purpose; the control track runs lightly alongside the others.

### Phase 1: probability and filtering

- Anchor: ROB 530 homeworks on preliminaries, Kalman filtering, and nonlinear
  filtering.
- Supplements: Stachniss on the Bayes filter and least squares; ROB 501 as
  needed.
- Repository: the probability articles are finished, and the Kalman-family
  filters are implemented with consistency tests.
- Move on when: the three homeworks have been attempted and their results are
  written up.

### Phase 2: Lie groups

- Anchor: the ROB 530 homework on Lie groups and the invariant EKF, alongside
  the {doc}`lie_groups </src/math/lie_groups/README>` module.
- Supplements: Solà's micro Lie theory; the rigid-body motion and kinematics
  chapters of Modern Robotics, which start the light control track.
- Repository: SO(3) and SE(3) with exp, log, and Jacobians, tested against
  independent oracles.
- Move on when: the invariant EKF homework is done and the module's articles
  are written.

### Phase 3: factor graphs and SLAM

- Anchor: Stachniss's graph-SLAM and robust least squares lectures, with
  16.485 SLAM I and II.
- Supplements: the Dellaert materials; ROB 501 for the optimization math.
- Repository: Gauss-Newton and Levenberg-Marquardt on manifolds, a pose-graph
  example, and an article on robust kernels.
- Move on when: a pose graph optimizes end to end on a toy problem.

### Phase 4: control and optimization

- Anchor: 16-745 in lecture order: optimization, LQR, Kalman duality, MPC,
  trajectory optimization.
- Supplements: the control, planning, and dynamics chapters of Modern Robotics.
- Repository: new modules as they are created. The README currently lists
  planning, controls, and trajectory optimization as "later, maybe".
- Move on when: LQR and a toy MPC run on a simulated system.

### Phase 5: Underactuated Robotics

- Selected chapters on trajectory optimization and nonlinear control, after
  Phase 4.

Tracking work runs through all of these phases and follows its own
{ref}`roadmap <tracking-roadmap>`.

## Review

Revisit this page about once a month. Update the status table, and drop any
course that isn't paying off.

Open questions to settle:

- The weekly time budget for courseware, and the split with repository work.
- Whether the aim is depth of understanding or a portfolio. This decides how
  much of each course's problem sets to do, and how much to spend on articles
  and code instead.

## Status

| Course | Phase | Status |
|---|---|---|
| Michigan ROB 530 | 1, 2 | Not started |
| Stachniss lectures | 1, 3 | Not started |
| MIT 16.485 | 3 | Not started |
| Georgia Tech Advanced Mobile Robotics | 3 | Not started |
| Modern Robotics | 2, 4 | Not started |
| CMU 16-745 | 4 | Not started |
| Underactuated Robotics | 5 | Not started |
| Michigan ROB 501 | on demand | Not started |
