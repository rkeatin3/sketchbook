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

## Numerical considerations

## Implementation

## Examples

## See also

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
