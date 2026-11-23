# Review criteria

Shared by the local `review` skill and the CI review
(`.github/workflows/claude-review.yml`), so both review against the same list.
Read `CLAUDE.md` first: the code is Ryan's, and reviewing is the one role with
no restrictions.

Work through these in order. Earlier items matter more.

## 1. Correctness

- The math: does the code compute what the article's derivation says?
- Edge cases and degenerate inputs: empty ranges, one sample, zero or singular
  covariances, `N = 1`.
- Invariants: what each type promises (a normalized distribution, a symmetric
  positive semidefinite covariance), and whether every operation keeps it.

## 2. Readability and maintainability

This repository puts readability ahead of performance. Could someone
relearning the topic years from now follow the code next to its article?

- Names follow the notation in the derivation and `docs/conventions/notation.md`,
  and the naming rules in `.clang-tidy`.
- Functions do one thing and are short enough to check against an equation.
- Comments give the why and the mathematical meaning, name the equation or
  article being implemented, and describe the code as it is (not how it came
  to be).
- A performance trick that costs clarity needs a measured reason.

Minimal code documentation, as plain comments (no Doxygen):

- Each header opens with a short comment on what it provides and which
  articles back it.
- Each public type and function has a brief comment: what it does, the
  article or equation it implements, and its preconditions, invariants, and
  failure behavior (what throws, what returns an error). Skip comments that
  only restate the name.
- Template parameters and concepts say what they require.

## 3. Modern C++

The toolchain is C++23. Point out where a newer construct says the same thing
more clearly or more safely, and why:

- concepts and `requires` clauses instead of unconstrained templates or SFINAE
- ranges and views, `std::span`, `std::mdspan`
- `std::expected` and `std::optional` for fallible results
- `std::format` and `std::print`
- `constexpr` and `consteval` where values are known at compile time
- deducing `this`, designated initializers, structured bindings
- C++26 features worth knowing about, flagged as future options

Also check the basics: `const` correctness, value semantics, RAII, no raw
owning pointers, `[[nodiscard]]` on results that must not be dropped.

## 4. Design

- Interfaces and seams: is each component swappable where the roadmap says it
  should be (estimators, motion and measurement models, belief
  representations)? Is coupling between modules minimal?
- Design patterns: practicing architecture is one of this repository's goals,
  so reusable abstractions are welcome even before a second implementation
  exists, when they demonstrate a pattern well. Suggest where one would fit:
  policy-based design and concepts for static polymorphism, a strategy where
  an algorithm varies, strong types where values are easy to mix up, CRTP or
  type erasure, RAII wrappers. Judge an abstraction by whether it's a clear,
  idiomatic example of its pattern, its seams are in the right place, and its
  purpose is documented. Object only when it hides the math the code exists
  to show, or adds indirection that teaches nothing.
- Error handling: one consistent strategy per module (exceptions,
  `std::expected`, or contracts via asserts), matching the plan's decisions.
- Name the trade-off when suggesting a different design.

## 5. Tests

- Every public behavior has a test, and every bug fix has a regression test.
- Oracles: hand-computed values, analytic results, and identities, rather
  than values copied from the code's own output.
- Properties and invariants: symmetry, normalization, permutation invariance,
  round trips (sample then fit).
- Edge cases from §1.
- Determinism: fixed seeds; no flaky statistical tests. Tolerances for
  statistical tests are justified (e.g. from the estimator's standard
  error), not tuned until green.
- Test names say what behavior is checked. One reason to fail per test.
- Would these tests catch a plausible bug? Name one they would miss.

## 6. Numerical stability

Conditioning, loss of symmetry or positive definiteness in covariances,
catastrophic cancellation, explicit inverses where a solve would do,
underflow in products of probabilities, singular cases.

## 7. Build and tooling hygiene

- Headers are self-contained and include what they use.
- `BUILD.bazel` deps are minimal and correct; nothing depends on a transitive
  include.
- Builds without warnings; clang-tidy is clean, or each suppression has a
  reason.

## 8. Docs

- The article's Implementation section matches the code, and every equation
  the code implements is named.
- Cross-links resolve, "See also" is complete, and `PROGRESS.md` and the
  plan's status tables reflect the change.

## 9. Scope

The change does one thing, sized to review in one sitting. Point out pieces
that belong in a separate PR.

## Reporting

For each finding: where it is, what is wrong, why it matters, and a pointer
toward a fix. Don't rewrite Ryan's implementation. Label each finding
**Problem**, **Suggestion**, **Question**, or **Nit**, most severe first,
and finish with a short summary of what is good and what to do next.
