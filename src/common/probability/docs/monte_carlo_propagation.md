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

## Numerical considerations

## Implementation

## Examples

## See also

- {doc}`Kalman Filtering </src/robotics/kalman/README>`: the EKF and UKF
  approximate this same propagation

## References

- {cite:t}`sarkka2023`: Gaussian approximations of nonlinear transforms,
  including Monte Carlo, linearization, and the unscented transform.
- {cite:t}`barshalom2001`: the polar-to-Cartesian measurement conversion
  problem, which is the "banana" example.
