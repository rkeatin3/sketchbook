(module-cpp-idioms)=
# Idioms

The recurring small-scale techniques of C++: how resources, copies, lookup,
and access are handled by convention. Some are timeless. Others were
workarounds that newer features replace, and knowing both forms helps when
reading older code.

**Status:** not started ·
[source](https://github.com/rkeatin3/sketchbook/tree/main/src/cpp/idioms)

## How this module works

Each idiom gets an article, `docs/<idiom>.md`, from the
{doc}`C++ article template </docs/conventions/cpp-article-template>`, and an
experiment, `<idiom>_test.cpp`. Larger designs, like CRTP, type erasure, and
policy-based design, are in {ref}`module-patterns` instead.

## Inventory

"Modern form" is where a newer feature replaces or reshapes the idiom; see
{ref}`module-cpp-features`.

### Current

| Idiom | Modern form | Article | Used in |
|---|---|---|---|
| RAII | | | |
| Rule of zero, rule of five | | | |
| Value semantics and regular types | defaulted `<=>` and `==` | | |
| Strong types | | | |
| Copy-and-swap | | | |
| Pimpl | | | |
| Hidden friends | | | |
| Non-virtual interface | | | |
| Passkey | | | |
| Null object | | | |
| Mixins | deducing `this` in place of a CRTP base | {ref}`deducing-this` | |
| Scope guard | | | |
| Immediately invoked lambda for `const` initialization | | | |
| `overloaded` lambda set for `std::visit` | | | |
| Customization point objects (niebloids) | | | |
| Expression templates | | | |

### Superseded

| Idiom | Modern form | Article | Used in |
|---|---|---|---|
| SFINAE and `std::enable_if` | concepts and `requires` | | |
| Tag dispatch | `if constexpr`, concepts | | |
| Erase–remove | `std::erase_if` | | |
| `const` and non-`const` overload pairs | deducing `this` | {ref}`deducing-this` | |
| Out-parameters and error codes | `std::expected`, `std::optional` | | |
| `printf` and `iostream` formatting | `std::format`, `std::print` | | |
| Pointer and length pairs | `std::span` | | |
| Hand-written loops that are a standard algorithm | `std::ranges` algorithms and views | | |

## Articles

```{toctree}
:maxdepth: 1
```

## See also

- {ref}`module-cpp-features`: the features in the "Modern form" column
- {ref}`module-patterns`: larger-scale designs built from these idioms

## References

_Key texts for this module, cited from `docs/references.bib`._
