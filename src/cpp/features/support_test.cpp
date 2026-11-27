// Compile-time check that every feature marked "both" in the Toolchain column
// of the feature inventory (src/cpp/features/README.md) is available on this
// compiler. Each check reads a standard feature-test macro, so a toolchain
// change that drops a feature fails the build here instead of in the code
// that uses it.
//
// Features marked "CI only" or "macOS only" are left out: one of the two
// toolchains lacks them, and the inventory says which.
//
// std::numbers is available on both toolchains but has no check here: libc++
// doesn't define __cpp_lib_numbers.

#include <version>

// C++20, language
static_assert(__cpp_concepts >= 202002L, "concepts and requires clauses");
static_assert(__cpp_impl_three_way_comparison >= 201907L, "operator<=>");
static_assert(__cpp_designated_initializers >= 201707L, "designated initializers");
static_assert(__cpp_consteval >= 201811L, "consteval");
static_assert(__cpp_constinit >= 201907L, "constinit");
static_assert(__cpp_using_enum >= 201907L, "using enum");
static_assert(__cpp_impl_coroutine >= 201902L, "coroutines");

// C++20, library
static_assert(__cpp_lib_ranges >= 201911L, "ranges and views");
static_assert(__cpp_lib_span >= 202002L, "std::span");
static_assert(__cpp_lib_format >= 201907L, "std::format");
static_assert(__cpp_lib_jthread >= 201911L, "std::jthread and stop tokens");
static_assert(__cpp_lib_source_location >= 201907L, "std::source_location");
static_assert(__cpp_lib_bit_cast >= 201806L, "std::bit_cast");

// C++23, language
static_assert(__cpp_explicit_this_parameter >= 202110L, "deducing this");
static_assert(__cpp_multidimensional_subscript >= 202110L, "multidimensional operator[]");
static_assert(__cpp_if_consteval >= 202106L, "if consteval");
static_assert(__cpp_static_call_operator >= 202207L, "static operator()");
static_assert(__cpp_auto_cast >= 202110L, "auto(x) decay-copy");

// C++23, library
static_assert(__cpp_lib_expected >= 202202L, "std::expected");
static_assert(__cpp_lib_print >= 202207L, "std::print");
static_assert(__cpp_lib_ranges_to_container >= 202202L, "std::ranges::to");
static_assert(__cpp_lib_forward_like >= 202207L, "std::forward_like");
static_assert(__cpp_lib_unreachable >= 202202L, "std::unreachable");
static_assert(__cpp_lib_to_underlying >= 202102L, "std::to_underlying");

auto main() -> int {
  return 0;
}
