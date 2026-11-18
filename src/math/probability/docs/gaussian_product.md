(gaussian-product)=
# Products of Gaussian densities

Multiplying two Gaussian densities over the same variable, which happens when
independent pieces of information about one quantity are combined: fusing two
estimates, or a prior with a likelihood. The result is proportional to another
Gaussian, and it is simplest to state in information form.

## Intuition

## Prerequisites

- {ref}`multivariate-gaussian`: the density and its quadratic form
- Completing the square for a quadratic form in a vector
- The information (canonical) form of a Gaussian: the precision matrix
  $\Sigma^{-1}$ and the information vector

## Derivation

_To prove:_

- The product of two Gaussian densities in $x$ is an unnormalized Gaussian
  density in $x$. Find its mean and covariance.
- The same result in information form, and why it's simpler there.
- The normalizing constant: what is it, and why is it itself a Gaussian
  density evaluated at a point?

## Numerical considerations

## Implementation

## Examples

## See also

- {ref}`gaussian-affine-transform`: the *sum* of independent Gaussian random
  variables, whose density is a convolution, not a product. The two are easy
  to confuse.
- {ref}`gaussian-marginal-conditional`: conditioning on a linear-Gaussian
  measurement, which the product of prior and likelihood reproduces
- {doc}`Filtering </src/estimation/filtering/README>`: the Kalman update as a
  product of densities, and the information filter

## References

- {cite:t}`bishop2006`, §2.3.3: Bayes' theorem for linear Gaussian models,
  derived by completing the square.
- {cite:t}`murphy2022`, §3.3: linear Gaussian systems, including the
  information form.
- {cite:t}`barfoot2024`, Ch. 2: products of Gaussians and the information
  form, in estimation notation.
- {cite:t}`petersen2012`, §8: Gaussian identities, for checking results.
