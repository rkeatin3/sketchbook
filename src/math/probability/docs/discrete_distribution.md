(discrete-distribution)=
# Discrete distributions

Probability on a finite set of outcomes: the axioms, joint distributions over
two variables, marginals, conditionals, and independence. A distribution over
$N$ outcomes is a vector, and a joint distribution over two variables is a
matrix, so each of these operations is a small piece of linear algebra. The
{ref}`bayes-filter` stores its belief this way.

## Intuition

## Prerequisites

- Sets: unions, intersections, complements
- Linear algebra: row and column sums, outer products

## Derivation

_To prove:_

- From the axioms: $P(A^c) = 1 - P(A)$, $P(\varnothing) = 0$, and
  inclusion–exclusion for two events.
- If $A$ and $B$ are independent, then so are $A$ and $B^c$, and $A^c$ and
  $B^c$.
- Marginalizing a joint distribution gives a valid distribution.
- For a fixed $y$ with $p(y) > 0$, the conditional $p(x \mid y)$ is a valid
  distribution over $x$, and the chain rule $p(x, y) = p(x \mid y)\, p(y)$
  holds.
- Two discrete variables are independent if and only if their joint table is
  the outer product of its marginals, so the table has rank one.

## Numerical considerations

## Implementation

Questions to settle:

- How is a distribution over $N$ outcomes represented: a fixed-size Eigen
  vector, a `std::array`, or a wrapper type that enforces the invariant?
  Should the size be a template parameter, as in `Gaussian<N>`?
- What invariant is checked (nonnegative entries, sum within a tolerance of
  one), and when: on construction only, or after every operation?
- How are marginalizing and conditioning a joint table expressed, and over
  which axis?
- Which of these does the {ref}`bayes-filter` need, and which are only for
  the exercises?

## Examples

## Exercises

:::{exercise}
:label: discrete-distribution-ex-hw1-1da

ROB 530 [Homework 1][hw1], §1.D(a): complements of independent events.
:::

:::{exercise}
:label: discrete-distribution-ex-blitzstein-ch2

{cite:t}`blitzstein2019`, Ch. 2: conditional probability exercises.
:::

:::{exercise}
:label: discrete-distribution-ex-coding

_Coding:_ build a joint table for two dependent variables, then check in a
test that the marginals and conditionals come out as computed by hand, and
that the table isn't the outer product of its marginals.
:::

## See also

- {ref}`bayes-rule`: inverting a conditional with these operations
- {ref}`bayes-filter`: a belief over a grid, updated with these operations
- {ref}`correlation`: independence vs. uncorrelatedness for real-valued
  variables
- {ref}`gaussian-marginal-conditional`: the same operations for a continuous
  joint Gaussian

## References

- {cite:t}`blitzstein2019`, Ch. 1–2 and §7.1: the axioms, conditional
  probability, and joint, marginal, and conditional distributions.
- {cite:t}`ghaffari2022`, lecture note 1, §2: the rules in the notation the
  course uses.
- {cite:t}`thrun2005`, §2.2: the same rules as used in robotics.

[hw1]: https://github.com/UMich-CURLY-teaching/UMich-ROB-530-public/blob/main/homework/homework-01/NA568_HW1_W22.pdf
