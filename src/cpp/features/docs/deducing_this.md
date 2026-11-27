(deducing-this)=
# Deducing `this`

A member function can take the object it's called on as an explicit first
parameter, `this auto&& self`, whose type is deduced like any other template
parameter. One function then serves every way the object can be passed.

**Standard:** C++23 ([P0847R7](https://wg21.link/P0847R7)) ·
**Toolchain:** both (`__cpp_explicit_this_parameter`)

## Motivation

_To work out:_

- A member function returns a reference to a data member. How many overloads
  does it need to return the right reference for `const` and non-`const`,
  lvalue and rvalue objects? What do the usual ways of avoiding the
  duplication cost?
- Why can't a lambda call itself by name, and how was recursion in a lambda
  written before?
- What does the CRTP base class in a mixin exist to recover, and how much of
  its syntax is there only for that?

## Prerequisites

- Forwarding references, `std::forward`, and value categories
- Templates and template argument deduction
- {ref}`module-patterns`: the CRTP pattern this simplifies

## Rules

_To work out, each with a check in the experiment:_

- What `Self` deduces to for a non-`const` lvalue, a `const` lvalue, an
  rvalue, and an object of a derived class.
- What can't be used in the body of such a function, and how members are
  reached instead.
- Which kinds of member function can't have an explicit object parameter, and
  which qualifiers it can't be combined with.
- How the type of `&Class::function` differs from an ordinary pointer to
  member function, and what that means for calling it.
- When taking `self` by value is useful, and what it costs.
- What `std::forward_like` does, and why it goes naturally with this feature.

## Before and after

_Embed the experiment's before-and-after regions here once written._

## Pitfalls

## Where it's used

_None yet. Candidates: accessor overload pairs in the math and estimation
modules, and the {ref}`module-patterns` area's CRTP examples._

## Exercises

% TODO: convert to titled {exercise} blocks, as in
% docs/conventions/article-template.md, once sphinx-exercise is enabled in
% docs/conf.py.

1. _Coding:_ Write a class with `const`, non-`const`, and rvalue overloads of
   an accessor, then collapse them into one function with an explicit object
   parameter. Check with `static_assert` and `std::is_same_v` that each value
   category gets the same reference type as before.
2. _Coding:_ Write a recursive lambda, such as a depth-first walk over a small
   tree, using an explicit object parameter.
3. _Coding:_ Write a mixin both ways, as a CRTP base and with deducing
   `this`, and compare what each derived class has to write.
4. _Coding:_ Write a chainable setter (`builder.with_x(1).with_y(2)`) that
   moves out of a temporary builder and copies an lvalue one.
5. Find a place in the repository where this feature would remove
   duplication, and fill in "Where it's used" once it's applied.

## See also

- {ref}`module-cpp-features`: the inventory of features
- {ref}`module-cpp-idioms`: the overload pairs and CRTP mixins it supersedes
- {ref}`module-patterns`: CRTP

## References

- [P0847R7](https://wg21.link/P0847R7), Deducing `this`: the proposal, with
  the motivating examples
- [Member functions: explicit object member functions](https://en.cppreference.com/w/cpp/language/member_functions.html),
  cppreference: the rules
- [C++23's Deducing this](https://devblogs.microsoft.com/cppblog/cpp23-deducing-this/),
  Sy Brand: an explanation of the use cases by one of the proposal's authors
