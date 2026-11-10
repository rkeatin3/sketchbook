# VS Code setup

- **Extensions:** opening the repo prompts for the recommended ones
  (`extensions.json`): clangd for C++ (IntelliSense, navigation, inline
  clang-tidy), `ruff` and `mypy-type-checker` for Python, and the Bazel
  extension.
- **Settings:** `settings.json` turns on format-on-save for C++, Python, and
  Bazel files, and points clangd at the compilation database (`../.clangd`).
- **Tasks:** `Cmd+Shift+P → Run Task` has shortcuts for build, test,
  regenerating `compile_commands.json`, and running pre-commit (`tasks.json`).

The compilation database is generated locally and gitignored. Create it once
after cloning:

```bash
bazel run //tools:refresh_compile_commands
```

After that, the `emeraldwalk.RunOnSave` extension regenerates it whenever a
`BUILD.bazel`, `MODULE.bazel`, or `.bzl` file is saved.
