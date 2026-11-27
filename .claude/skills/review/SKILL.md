---
name: review
description: Review the current branch's changes (or a given PR) before opening a pull request, using the same criteria as the CI review bot. Use when asked to review code or docs, or before opening or marking a PR ready.
---

# Review

Review a change the way the CI bot will, so its findings are dealt with
before the PR exists. The criteria live in [criteria.md](criteria.md), shared
with `.github/workflows/claude-review.yml`. Read them first, along with
`CLAUDE.md` and, for code, the feature and idiom inventories in `src/cpp/`
(criteria §2).

## 1. Find the change

- **A branch (default):** diff against the merge base with the base branch,
  not its tip:
  `git diff "$(git merge-base HEAD "$(git base)")"..HEAD`. Include
  uncommitted changes if there are any (`git diff HEAD`), and say so.
- **A PR number:** `gh pr diff <n>` and `gh pr view <n>`.

Read every changed file in full, not only the hunks. For code, also read the
article it implements; for an article, the code it describes.

## 2. Run the checks

Run what applies to the change, and report failures as findings:

- C++: `bazel build //...` and `bazel test` for the affected packages.
- clang-tidy: `tools/clang_tidy.sh <files>` if the script exists.
- Coverage, when tests changed or new code lacks them:
  `bazel coverage //src/<area>/<module>/... --combined_report=lcov`, then
  look for untested branches in the changed files.
- Docs: the strict wiki build,
  `sphinx-build -c docs -W --keep-going . docs/_build/html` (install with
  `pip install --group docs`, pip >= 25.1, in a virtual environment).

## 3. Review

Go through criteria.md in order. Verify each finding before reporting it:
re-read the code, and where a claim is checkable (a numeric result, a
compile error, a failing edge case), check it.

## 4. Report, then act by authorship

Report findings as criteria.md describes. Then:

- **Ryan's code and derivations:** report only. Don't fix them, and don't
  include replacement implementations; point toward the fix.
- **Docs, tooling, tests, and scaffolding Claude wrote:** fix the findings
  directly, rerun the checks, and list what changed. This includes the C++
  inventories: fill in "Used in" cells and add rows for features the change
  uses, even when the code itself is Ryan's.

Don't commit, push, or open the PR unless Ryan explicitly asks.
