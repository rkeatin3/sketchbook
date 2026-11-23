(gaussian-affine-transform)=
# Affine transforms of Gaussians

What happens to a Gaussian under $x \mapsto Fx + b$: the mean and covariance of
the result, and why the result is still Gaussian.

## Intuition

## Prerequisites

- {ref}`random-vector-moments`
- {ref}`multivariate-gaussian`
- {ref}`characteristic-function`

## Derivation

_To prove:_

- The mean and covariance of $Fx + b$ (from {ref}`random-vector-moments`;
  cite).
- Closure: $Fx + b$ is Gaussian, for any $F$, square or not. Uses
  {ref}`characteristic-function`.
- Corollary: the sum of independent Gaussian random variables is Gaussian, and
  its parameters.

## Numerical considerations

## Implementation

## Examples

## Exercises

1. ROB 530 [Homework 1][hw1], §1.D(b): an affine map of a Gaussian random
   vector is Gaussian.
2. ROB 530 [Homework 1][hw1], §6: a linear calibration of a Gaussian range
   measurement. Is the result exact or an approximation?
3. _Coding:_ check `Transform` against samples pushed through the same map.

## See also

- {ref}`gaussian-sampling`: sampling is an affine transform of a standard
  normal
- {ref}`gaussian-marginal-conditional`: marginalizing is an affine transform
  that selects components
- {ref}`monte-carlo-propagation`: the nonlinear case, where closure fails
- {ref}`gaussian-product`: *products* of densities, as opposed to sums of
  random variables, whose density is a convolution

## References

- {cite:t}`murphy2022`, §3.2–3.3: affine transforms and linear Gaussian
  systems.
- {cite:t}`blitzstein2019`, §7.5: the multivariate normal defined through
  linear combinations, with closure proved via the moment-generating
  function. The most direct route to the "still Gaussian" half.
- {cite:t}`barfoot2024`, Ch. 2: linear transforms of Gaussians in estimation
  notation.

[hw1]: https://github.com/UMich-CURLY-teaching/UMich-ROB-530-public/blob/main/homework/homework-01/NA568_HW1_W22.pdf
