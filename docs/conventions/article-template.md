# Article template

Every article covers one concept and uses these sections in this order. Leave
out a section only if it truly doesn't apply. "See also" and "References" are
never optional.

Copy the block below to start a new article. File it according to
{doc}`index`.

````markdown
(topic-label)=
# Topic name

One or two sentences: what this is and what problem it solves.

## Intuition

The idea in words and pictures, before any algebra. What would you tell
someone at a whiteboard?

## Prerequisites

Links to the articles this one builds on: {ref}`other-label`.

## Derivation

Assumptions first, then the derivation, step by step. Justify each move. Don't
skip algebra that took effort to work out. Number the results that the code
implements:

$$
...
$$ (eq-topic-result)

## Numerical considerations

Conditioning, singularities, degenerate inputs, stability. What goes wrong in
floating point, and how the implementation guards against it.

## Implementation

Design decisions and how the code maps to the derivation. Name the equation
each function implements and embed the code:

```{literalinclude} ../topic.hpp
:language: cpp
:start-after: "[doc:topic]"
:end-before: "[/doc:topic]"
```

Testing strategy: oracles, invariants, and edge cases. Link the test file.

## Examples

Worked examples by hand, plus pointers to runnable targets in `examples/`.

## See also

- {ref}`related-label`: one line on how it relates

## References

{cite}`key` for specific claims. Books and papers go in `docs/references.bib`.
````

## Writing rules

- **Use symbols from {ref}`notation`.** Add any new symbol there when it is
  first introduced.
- **Define glossary terms on first use** with `` {term}`Term` ``, and add new
  terms to the {doc}`/docs/glossary`.
- **Link generously.** Every concept mentioned that has an article gets a link,
  in the text where it appears and in "See also".
- **Write it to be read later.** Say why each step holds, not only what the step
  is.
