(probability-plan)=
# Gaussian plan

The plan for the Gaussian work in tracking phase 0 (see {ref}`tracking-roadmap`).
It lists topics, decisions made so far, and questions to work through. The
derivations and the code are left to be worked out.

## Goal

A fixed-dimension multivariate Gaussian type that the simulator, the Kalman
filters, gating, and the evaluation metrics can all share. Each topic below
gets an article and its own tests.

## Decisions so far

- **A class with methods** (e.g. `Gaussian::Sample`). Which operations end up
  as members and which as free functions is decided as the work goes.
- **Covariance form first.** The information form may come later behind a
  strategy, so the public interface shouldn't assume how the parameters are
  stored.
- **Validate the invariant.** Check that $\Sigma$ is symmetric positive
  semidefinite on construction, and again in any operation that could break it.
- **No caching** of factorizations for now.
- **Fixed dimensions**, known at compile time.
- **Header-only**, since the class is templated on its dimension.
- **The caller owns the RNG.** `Sample` takes a generator by reference,
  constrained by `std::uniform_random_bit_generator`.

## API

What `Gaussian<N>` offers or will offer, and the step each belongs to. Whether
the planned operations are members or free functions is still open (see Open
questions). Signatures are sketches.

| Operation | Purpose | Step | Status |
|---|---|---|---|
| Constructor | Validates $\Sigma$; throws if invalid | 1 | Done |
| `Mean()`, `Covariance()` | Accessors | — | Done |
| `Fit(samples)` | Sample mean and covariance | 0, 5 | Done |
| `Sample(rng)` | One draw | 3 | Done |
| `SampleN(rng, n)` | $n$ draws, factoring $\Sigma$ once | 3 | Done |
| `Pdf(x)` | Density | 4 | Done |
| `std::formatter` | `std::format` and test output | — | Done |
| `LogPdf(x)` | Log-density, stable in high dimensions | 4 | Planned |
| `SquaredMahalanobis(x)` | Gating, NEES/NIS, ellipses | 6 | Planned |
| `Transform(F, b)` | Affine map; returns `Gaussian<M>` for an $M \times N$ matrix $F$ | 2 | Planned |
| `Marginal<Offset, K>()` | Marginal of $K$ consecutive components; returns `Gaussian<K>` | 7 | Planned |
| `Condition<Offset, K>(y)` | Conditional given observed components $y$; returns `Gaussian<N - K>` | 7 | Planned |
| `Product(other)` | Product of two densities over the same variable, renormalized (fusion) | 8 | Planned |

## Articles

Articles with code sit in this module's `docs/`. Pure math goes in the wiki's
`docs/concepts/`. Each article's References section says where to start
reading for that topic.

| Article | Covers |
|---|---|
| {ref}`random-vector-moments` | Expectation of vectors and matrices, the covariance identity, and sample estimates (`Fit`); not Gaussian-specific |
| {ref}`multivariate-gaussian` | Definition, parameterizations, the PSD invariant, rank-deficient cases, evaluating the log-pdf, how the class represents it |
| {ref}`gaussian-mle` | Maximum-likelihood mean and covariance; why `Fit` is the best Gaussian fit |
| {ref}`gaussian-affine-transform` | Moments and closure; sums of independent Gaussians as a special case |
| {ref}`gaussian-sampling` | The factorization, choosing $A$, RNG design, validation |
| {ref}`mahalanobis-distance` | Definition, its distribution, and its uses: gating, NEES/NIS, ellipses |
| {ref}`gaussian-marginal-conditional` | The partitioned results, and the link to the Kalman update |
| {ref}`gaussian-product` | Products of densities, the information form, and fusion |
| {ref}`monte-carlo-propagation` | Pushing samples through $g(x)$; the polar "banana" |
| {ref}`characteristic-function` | The tool behind most of the closure proofs (concept) |
| {ref}`cholesky-factorization` | Existence, the algorithm, stability (concept; Eigen computes it) |
| {ref}`chi-squared-distribution` | Needed by the Mahalanobis article (concept) |

### Proofs

Proofs use the `{prf:theorem}` and `{prf:proof}` directives. Prove fully the
results the code depends on, and the properties the filters lean on. Cite the
rest. Each article's Derivation section lists its results under "To prove".

| Result | Article | Depth |
|---|---|---|
| Linearity of expectation for vectors and matrices; the covariance identity | {ref}`random-vector-moments` | Prove |
| Mean and covariance of $AX + b$, for any distribution | {ref}`random-vector-moments` | Prove |
| The divisor that makes the sample covariance unbiased | {ref}`random-vector-moments` | Prove |
| The density integrates to 1 (the normalizing constant `Pdf` uses) | {ref}`multivariate-gaussian` | Prove |
| The parameters are the mean and covariance | {ref}`multivariate-gaussian` | Prove |
| Uncorrelated implies independent for jointly Gaussian variables, and a counterexample otherwise | {ref}`multivariate-gaussian` | Prove |
| Maximum-likelihood mean and covariance | {ref}`gaussian-mle` | Prove |
| Characteristic function of a Gaussian and of an affine map | {ref}`characteristic-function` | Prove |
| A characteristic function determines its distribution | {ref}`characteristic-function` | Cite |
| Closure under affine maps | {ref}`gaussian-affine-transform` | Prove |
| Sums of independent Gaussians (how process noise enters prediction) | {ref}`gaussian-affine-transform` | Prove (corollary) |
| The distribution of $Az + b$, $z \sim \mathcal{N}(0, I)$ (what `Sample` relies on) | {ref}`gaussian-sampling` | Prove (corollary) |
| Existence of the Cholesky factorization | {ref}`cholesky-factorization` | Cite, or prove |
| Sum of squared standard normals | {ref}`chi-squared-distribution` | Cite |
| Distribution of the squared Mahalanobis distance | {ref}`mahalanobis-distance` | Prove |
| Marginals and conditionals of a joint Gaussian | {ref}`gaussian-marginal-conditional` | Prove |
| Products of Gaussian densities | {ref}`gaussian-product` | Prove |
| Convergence of Monte Carlo moment estimates | {ref}`monte-carlo-propagation` | Cite |

## Steps

### 0. Mean and covariance

- Expectation of a random vector or matrix is defined entry by entry. Why does
  that make every scalar rule (linearity, pulling out constants) carry over,
  and where does the order of factors start to matter?
- Show $E[(X-\mu)(X-\mu)^\top] = E[XX^\top] - \mu\mu^\top$.
- Estimating from samples: what should `Fit` divide by, $n$ or $n - 1$, and
  why do texts disagree?
- The identity suggests a one-pass algorithm. When does it lose precision, and
  what do the two-pass and Welford methods do instead?

### 1. Representation

- What do "symmetric" and "positive semidefinite" mean numerically? Which
  tolerances apply, and how do you check each property?
- Which operations could produce an invalid $\Sigma$, and so need to re-check?

### 2. Affine transforms

- What are the mean and covariance of $Fx + b$ for a (possibly non-square) $F$?
- That gives the moments. Why is the result still *Gaussian*? This takes a real
  tool (see {ref}`characteristic-function`); the moments alone don't fix the
  shape.
- What happens to the result's rank when $F$ has more rows than columns?

### 3. Sampling

- If $z \sim \mathcal{N}(0, I)$, what are the mean and covariance of $Az + b$?
  Which $A$ gives the $\Sigma$ you want, and which factorization produces it
  cheaply?
- How do you get $z$? `std::normal_distribution` isn't specified bit-for-bit
  across standard libraries. Does that matter here?

### 4. Log-likelihood

- Why use the log-pdf rather than the pdf?
- How do you compute the log-determinant and the quadratic form without
  forming $\Sigma^{-1}$?

### 5. Fitting by maximum likelihood

- What is the likelihood of $n$ independent samples, and why maximize its log
  instead?
- Setting the derivatives to zero needs derivatives with respect to a vector
  and a matrix. $\Sigma$ is symmetric positive definite, so does the
  unconstrained optimum respect that, or does it need enforcing?
- Is the stationary point actually a maximum?
- Which divisor does the maximum-likelihood $\Sigma$ use, and how does that
  square with the answer from step 0? Which one should `Fit` use?

### 6. Mahalanobis distance

- What distribution does the squared Mahalanobis distance of a sample follow,
  and why?
- How does that one result support gating, NEES/NIS, and covariance ellipses?

### 7. Marginalizing and conditioning

- Given a joint Gaussian over $(x, y)$, what are the marginal of $x$ and the
  conditional $p(x \mid y)$?
- Write the state and the measurement as one joint Gaussian. How does
  conditioning on the measurement relate to the Kalman update?
- With fixed dimensions, how does the API name the partition? Is "a block of
  consecutive components" enough, or do callers need arbitrary index sets
  (and then, can those still be compile-time)?

### 8. Products of Gaussian densities

- Why is the product of two Gaussian densities in $x$ proportional to a
  Gaussian, and what are its parameters?
- Why is the result simpler to state in information form?
- The normalizing constant you dropped: what is it, and where does it matter
  (hint: data association)?
- How does fusing two independent estimates of the same state relate to the
  Kalman update?

### 9. Rank-deficient covariances

- Which of the operations above still make sense when $\Sigma$ is positive
  semidefinite but singular?
- Which factorizations still work, and which fail?
- Tie this to the roadmap question about the rank of the discretized
  white-noise-acceleration process noise.

### 10. Monte Carlo propagation through nonlinear functions

- Push samples through $g(x)$ and fit a Gaussian to the result. How many
  samples does it take for the fit to settle?
- Use polar to Cartesian (the "banana") as the running example. This becomes
  the reference that linearization and the unscented transform are tested
  against in phase 3.

## Validation

- The sample mean and covariance converge to $\mu$ and $\Sigma$. What rate
  should you expect, and how do you turn that into a test tolerance that
  doesn't flake?
- Squared Mahalanobis distances of samples follow the distribution from step
  6: NEES in miniature.
- Affine transforms checked against transformed samples.
- Fixed seeds throughout.

## Figures

Sample clouds with covariance ellipses, and the banana (later compared against
linearization and the unscented transform). How to generate them is decided
when the first one is due.

## Reading

All of these are in `docs/references.bib` and cited from the articles' References
sections, with a pointer to the relevant part.

- Bar-Shalom, Li, Kirubarajan, *Estimation with Applications to Tracking and
  Navigation*, Ch. 1 (owned): its review of probability covers Gaussian
  random vectors, conditioning of jointly Gaussian vectors, and the chi-squared
  distribution, in the notation the later tracking chapters use.
- Murphy, *Probabilistic Machine Learning: An Introduction*, Ch. 3 (free
  online): the multivariate normal, linear Gaussian systems, marginals and
  conditionals. The main starting point.
- Barfoot, *State Estimation for Robotics*, 2nd ed., Ch. 2 (free PDF): a
  probability primer aimed at estimation, with joint, marginal, and conditional
  Gaussians via Schur complements, linear transforms, and Mahalanobis distance.
- Bishop, *Pattern Recognition and Machine Learning*, §2.3 and §11.1.1 (free
  PDF): the classic treatment of Gaussian properties, and sampling from
  standard distributions.
- Trefethen & Bau, *Numerical Linear Algebra*, Lecture 23: Cholesky
  factorization, why it exists for symmetric positive definite matrices, and
  why it's stable.
- Blitzstein & Hwang, *Introduction to Probability*, 2nd ed. (free to read
  online, not downloadable):
  moment-generating functions and the multivariate normal (§7.5). The gentlest
  route to proving closure under affine maps.
- Devroye, *Non-Uniform Random Variate Generation* (free): only if you write
  your own uniform-to-normal step (Box–Muller, the polar method).
- Petersen & Pedersen, *The Matrix Cookbook*, §8 (free): Gaussian identities,
  for checking rather than learning.

For sampling: start with Murphy §3.2 or Barfoot §2.2 for the claims, then
Trefethen & Bau for the factorization. Bar-Shalom Ch. 1 is the natural
companion for the Mahalanobis, chi-squared, and conditioning articles.

## Deferred

- Information form (and the strategy that selects it)
- Caching the factorization
- Dynamic dimensions
- Gaussian mixtures (IMM, GM-PHD)
- Linearization and the unscented transform (phase 3)
- Entropy and KL divergence (for mixture reduction, later)
- Principal component analysis (the eigendecomposition of $\Sigma$; ties into
  covariance ellipses)

## Open questions

- Member vs. free functions, especially for transforms and conditioning.
- Does the constructor's check match the decision? `Eigen::LLT` succeeds only
  for positive *definite* matrices, so it rejects singular PSD covariances
  (step 9), and it reads only the lower triangle, so it never checks symmetry.
- How should validation failures be reported: an exception (current), an
  assert, or a factory returning `std::expected`?
