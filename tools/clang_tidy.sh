#!/usr/bin/env bash
# Runs clang-tidy with the repo's .clang-tidy over the given source files, or
# over every tracked .cpp file if none are given. Headers are checked through
# the sources that include them (HeaderFilterRegex), and template members only
# once something instantiates them, which is one more reason to test them.
#
#   tools/clang_tidy.sh [--refresh] [file.cpp ...]
#
# --refresh regenerates compile_commands.json first; do that after changing a
# BUILD.bazel file.
set -euo pipefail

cd "$(git rev-parse --show-toplevel)"

if [[ "${1:-}" == "--refresh" ]]; then
  shift
  bazel run //tools:refresh_compile_commands
fi

if [[ ! -f compile_commands.json ]]; then
  echo "compile_commands.json is missing; rerun with --refresh." >&2
  exit 1
fi

# Prefer Homebrew's LLVM on macOS, since Apple doesn't ship clang-tidy.
clang_tidy="clang-tidy"
if ! command -v "${clang_tidy}" >/dev/null; then
  for candidate in /opt/homebrew/opt/llvm/bin/clang-tidy /usr/local/opt/llvm/bin/clang-tidy; do
    if [[ -x "${candidate}" ]]; then
      clang_tidy="${candidate}"
      break
    fi
  done
fi

extra_args=()
# A non-Apple clang-tidy can't find the macOS SDK's standard headers on its
# own, and a header that fails to parse makes every later diagnostic suspect.
if [[ "$(uname)" == "Darwin" ]]; then
  extra_args+=("--extra-arg=-isysroot$(xcrun --show-sdk-path)")
fi

if [[ $# -eq 0 ]]; then
  # Read line by line rather than with mapfile, which macOS's bash 3.2 lacks.
  while IFS= read -r file; do
    set -- "$@" "${file}"
  done < <(git ls-files '*.cpp' '*.cc')
fi
if [[ $# -eq 0 ]]; then
  exit 0
fi

# The ${a[@]+...} form expands an empty array safely under set -u in bash 3.2.
"${clang_tidy}" -p . --quiet ${extra_args[@]+"${extra_args[@]}"} "$@"
