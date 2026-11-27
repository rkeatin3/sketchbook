# C++ article template

Articles in {ref}`area-cpp` cover one language feature or idiom. They follow
the {doc}`article template <article-template>`, with sections that fit a
language topic in place of the derivation. The writing rules there apply here
too.

% TODO: write Exercises as titled {exercise} blocks, matching the main
% article template, once sphinx-exercise is enabled in docs/conf.py.

Copy the block below to start a new article. It goes in
`src/cpp/features/docs/<topic>.md` or `src/cpp/idioms/docs/<topic>.md`, and
its experiment in `<topic>_test.cpp` beside the module's `BUILD.bazel`.

````markdown
(topic-label)=
# Topic name

One or two sentences: what this is and what problem it solves.

**Standard:** C++NN ([PNNNN](https://wg21.link/PNNNN)) ·
**Toolchain:** both, macOS only, or CI only (`__cpp_feature_test_macro`)

## Motivation

The problem, and how it was solved before: the old idiom and what it cost.

## Prerequisites

Links to the articles this one builds on: {ref}`other-label`.

## Rules

How it works: what the compiler deduces or generates, what is allowed and
what isn't, and how it interacts with other features. Each rule worth
remembering gets a check in the experiment.

## Before and after

The old form next to the new one, embedded from the experiment:

```{literalinclude} ../topic_test.cpp
:language: cpp
:start-after: "[doc:topic]"
:end-before: "[/doc:topic]"
```

## Pitfalls

Mistakes that compile, surprising interactions, and when not to use it.

## Where it's used

Links to the code in this repository that uses it, matching the "Used in"
cell of the module's inventory.

## Exercises

1. _Coding:_ Experiments to write, in the experiment file.

## See also

- {ref}`related-label`: one line on how it relates

## References

The proposal, the cppreference page, and a good explanatory article.
````

The opening line names the standard, the proposal, and where the feature
works today, matching the module's inventory. Idioms leave out what doesn't
apply (an idiom has no proposal).
