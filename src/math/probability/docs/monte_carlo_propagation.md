(monte-carlo-propagation)=
# Monte Carlo propagation

Estimating the distribution of $g(x)$ for a nonlinear $g$ by pushing samples
through it and fitting a Gaussian to the result. The reference that
linearization and the unscented transform are tested against.

## Intuition

## Prerequisites

- {ref}`gaussian-sampling`
- {ref}`gaussian-affine-transform`

## Derivation

_To prove:_

- Why the fitted mean and covariance converge to the true moments of $g(x)$ as
  the sample count grows (cite the law of large numbers).

## Numerical considerations

## Implementation

## Examples

## See also

- {doc}`Filtering </src/estimation/filtering/README>`: the EKF and UKF
  approximate this same propagation

## References

- {cite:t}`sarkka2023`: Gaussian approximations of nonlinear transforms,
  including Monte Carlo, linearization, and the unscented transform.
- {cite:t}`barshalom2001`: the polar-to-Cartesian measurement conversion
  problem, which is the "banana" example.
