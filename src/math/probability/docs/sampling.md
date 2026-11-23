(gaussian-sampling)=
# Sampling from a Gaussian

Drawing samples from $\mathcal{N}(\mu, \Sigma)$ by transforming draws from a
standard normal, and how the RNG is supplied so that every draw can be
replayed.

## Intuition

## Prerequisites

- {ref}`gaussian-affine-transform`
- {ref}`cholesky-factorization`

## Derivation

_To prove:_

- Corollary of {ref}`gaussian-affine-transform`: the distribution of $Az + b$
  for $z \sim \mathcal{N}(0, I)$.
- Which matrices $A$ produce a given $\Sigma$, and why the Cholesky factor is
  one of them.
- Which of those matrices still exist when $\Sigma$ is singular.

## Numerical considerations

## Implementation

Questions to settle:

- Which factorization, so that singular positive semidefinite covariances can
  be sampled too?
- `std::normal_distribution` isn't specified bit-for-bit across standard
  libraries. What does that mean for fixed-seed tests: which assertions are
  portable, and which pin one library's output?

## Examples

## Exercises

## See also

- {ref}`multivariate-gaussian`: the distribution being sampled
- {ref}`random-vector-moments`: sample moments are how a sampler is validated
- {ref}`mahalanobis-distance`: the distribution of sample distances is a test
  of the sampler
- {ref}`monte-carlo-propagation`: samples pushed through a nonlinear function

## References

- {cite:t}`murphy2022`, §3.2: the multivariate normal; the sampling recipe
  follows from its affine-transform property.
- {cite:t}`bishop2006`, §11.1.1: sampling from standard distributions,
  including the multivariate Gaussian via a factor of $\Sigma$.
- {cite:t}`trefethen1997`, Lecture 23: the Cholesky factorization that
  supplies the factor.
- {cite:t}`devroye1986`: generating normal variates from uniforms
  (Box–Muller, the polar method). Only needed for a portable, hand-written
  normal generator.
- cppreference, [Pseudo-random number generation](https://en.cppreference.com/w/cpp/numeric/random):
  engines, distributions, and the `std::uniform_random_bit_generator` concept.
