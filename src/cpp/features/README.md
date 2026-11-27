(module-cpp-features)=
# Language and library features

What each feature added in C++20 and later is for, how it works, and where
this repository uses it.

**Status:** not started ·
[source](https://github.com/rkeatin3/sketchbook/tree/main/src/cpp/features)

## How this module works

Each feature gets an article, `docs/<feature>.md`, from the
{doc}`C++ article template </docs/conventions/cpp-article-template>`, and an
experiment, `<feature>_test.cpp`: small tests and `static_assert`s that pin
down how the feature behaves. The experiments are for learning the rules. Real
use belongs in the other modules, linked from the "Used in" column.

## Inventory

**Toolchain** is where the feature works today:

- **both:** macOS (Apple Clang 21, libc++) and CI (GCC 14, libstdc++).
  `support_test.cpp` checks these with feature-test macros.
- **macOS only** or **CI only:** don't use it yet. Mention it as a future
  option instead.
- **neither:** unavailable in practice, for the reason given.
- **unchecked:** C++26, not yet assessed.

A feature becomes usable everywhere when both toolchains support it. Update
the column and `support_test.cpp` together.

% TODO: recheck the "macOS only" and "CI only" rows whenever Apple Clang or
% CI's GCC (CC in .github/workflows/cpp.yml) is upgraded; GCC 15 adds
% std::mdspan and std::flat_map. Assess the "unchecked" C++26 rows.

### C++20

| Feature | Toolchain | Article | Used in |
|---|---|---|---|
| Concepts and `requires` clauses | both | | |
| Abbreviated function templates (`auto` parameters) | both | | |
| Three-way comparison (`<=>`) and defaulted `==` | both | | |
| Designated initializers | both | | |
| `consteval` and `constinit` | both | | |
| `using enum` | both | | |
| Template parameter lists on lambdas | both | | |
| `[[likely]]`, `[[unlikely]]`, `[[no_unique_address]]` | both | | |
| Coroutines (language support) | both | | |
| Ranges and views | both | | |
| `std::span` | both | | |
| `std::format` | both | | |
| `std::numbers` (`pi`, `e`, …) | both | | |
| `std::jthread` and stop tokens | both | | |
| `std::source_location` | both | | |
| `std::bit_cast` | both | | |
| `std::erase` and `std::erase_if` | both | | |
| Modules | neither (Bazel) | | |

### C++23

| Feature | Toolchain | Article | Used in |
|---|---|---|---|
| Deducing `this` (explicit object parameters) | both | {ref}`deducing-this` | |
| Multidimensional `operator[]` | both | | |
| `if consteval` | both | | |
| `static operator()` | both | | |
| `auto(x)` decay-copy | both | | |
| `std::expected` | both | | |
| `std::print` and `std::println` | both | | |
| `std::ranges::to` | both | | |
| `std::forward_like` | both | | |
| `std::unreachable` | both | | |
| `std::to_underlying` | both | | |
| `std::mdspan` | macOS only | | |
| `std::flat_map` and `std::flat_set` | macOS only | | |
| `views::zip`, `enumerate`, `chunk`, `cartesian_product` | CI only | | |
| `std::ranges::fold_left` and friends | CI only | | |
| `std::generator` | CI only | | |
| `std::move_only_function` | CI only | | |
| `std::stacktrace` | neither (libc++ lacks it) | | |

### C++26 to watch

| Feature | Toolchain | Article | Used in |
|---|---|---|---|
| Contracts (`pre`, `post`, `contract_assert`) | unchecked | | |
| Static reflection | unchecked | | |
| Pack indexing | unchecked | | |
| `std::linalg` | unchecked | | |
| `std::inplace_vector` | unchecked | | |
| `std::execution` (senders and receivers) | unchecked | | |
| `= delete("reason")` | unchecked | | |

## Articles

```{toctree}
:maxdepth: 1

docs/deducing_this
```

## See also

- {ref}`module-cpp-idioms`: the idioms these features enable or replace
- {ref}`module-patterns`: designs that modern features reshape

## References

- [C++ compiler support](https://en.cppreference.com/w/cpp/compiler_support.html),
  cppreference: per-compiler support for each feature
- [Feature testing](https://en.cppreference.com/w/cpp/feature_test.html),
  cppreference: the feature-test macros `support_test.cpp` checks
