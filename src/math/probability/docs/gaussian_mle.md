(gaussian-mle)=
# Fitting a Gaussian by maximum likelihood

The mean and covariance that make a set of independent samples most likely
under a Gaussian model, and how that answer relates to the sample estimates
in {ref}`random-vector-moments`. This is the math behind `Gaussian::Fit`.

## Intuition

## Prerequisites

- {ref}`multivariate-gaussian`: the log-pdf being maximized
- {ref}`random-vector-moments`: the sample estimates, and the $n$ vs. $n - 1$
  question
- Independent, identically distributed samples, and the likelihood of a data
  set
- Matrix calculus: derivatives of a scalar function with respect to a vector
  and with respect to a matrix

## Derivation

_To prove:_

- The maximum-likelihood mean and covariance, from the stationary conditions.
- The stationary point is a maximum.
- How the maximum-likelihood divisor relates to the unbiased one in
  {ref}`random-vector-moments`.

## Numerical considerations

## Implementation

## Examples

## See also

- {ref}`random-vector-moments`: the same estimates without assuming a
  Gaussian, and the bias argument for $n - 1$
- {ref}`multivariate-gaussian`: the density and its log
- {ref}`monte-carlo-propagation`: fits a Gaussian to propagated samples

## References

- {cite:t}`murphy2022`, §4.2: maximum likelihood estimation, including the
  multivariate Gaussian case. The main starting point.
- {cite:t}`bishop2006`, §2.3.4: maximum likelihood for the Gaussian, and the
  bias of the covariance estimate. §1.2.4 covers the scalar case first.
- {cite:t}`petersen2012`, §2: derivatives with respect to vectors and matrices,
  for looking up the identities the derivation needs.
