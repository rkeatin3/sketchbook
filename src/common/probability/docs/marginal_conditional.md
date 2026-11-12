(gaussian-marginal-conditional)=
# Marginalizing and conditioning Gaussians

Splitting a joint Gaussian over $(x, y)$ into the marginal of $x$ and the
conditional $p(x \mid y)$, and how conditioning relates to the Kalman update.

## Intuition

## Prerequisites

- {ref}`multivariate-gaussian`
- {ref}`gaussian-affine-transform`

## Derivation

## Numerical considerations

## Implementation

## Examples

## See also

- {doc}`Kalman Filtering </src/robotics/kalman/README>`: the update step is
  conditioning on a measurement

## References

- {cite:t}`bishop2006`, §2.3.1–2.3.3: conditional and marginal Gaussians,
  and Bayes' theorem for linear Gaussian models. The classic derivation by
  completing the square.
- {cite:t}`murphy2022`, §3.2–3.3: the same results, and linear Gaussian
  systems.
- {cite:t}`barfoot2024`, Ch. 2: the derivation via Schur complements, in
  estimation notation.
- {cite:t}`barshalom2001`, Ch. 1: conditioning of jointly Gaussian vectors,
  which is the basis of its Kalman filter derivation.
- {cite:t}`sarkka2023`: Gaussian conditioning as used in Bayesian filtering.
