(notation)=
# Notation

One set of symbols for the whole wiki. Code identifiers follow these names.
Add a symbol to the table when a derivation first introduces it. Where a cited
text uses different notation, the article notes it.

## Typography

- **Vectors and matrices** are plain italic: $x$, $P$, $F$, $H$. Context
  distinguishes them from scalars.
- **Estimates** use conditional subscripts: $\hat{x}_{k|j}$ and $P_{k|j}$ are
  the estimate and covariance at time $k$ given data through time $j$. So
  $\hat{x}_{k|k-1}$ is the prior, $\hat{x}_{k|k}$ the posterior, and
  $\hat{x}_{k|N}$ a smoothed estimate.
- **Gaussian densities** name their argument:
  $\mathcal{N}(x;\, \mu, \Sigma)$.

## Frames and transforms

${}^{A}T_{B}$ maps coordinates expressed in frame $B$ into frame $A$:

$$
{}^{A}p = {}^{A}T_{B}\, {}^{B}p, \qquad {}^{A}T_{C} = {}^{A}T_{B}\, {}^{B}T_{C}
$$

In code the same transform is `t_a_b`, so composition reads
`t_a_c = t_a_b * t_b_c`.

## Symbols

| Symbol | Meaning | Code name | Introduced in |
|---|---|---|---|
| | | | |
