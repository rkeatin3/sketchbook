# Conventions

How this wiki is written and linked. The goal is that any article, read years
later, is unambiguous on its own and connected to everything it depends on.

```{toctree}
:maxdepth: 1

notation
article-template
```

## Where pages live

| Page | Location |
|---|---|
| Module hub | `src/<area>/<module>/README.md` |
| Article about implemented code | Beside the code: `src/<area>/<module>/<topic>.md` |
| Article with no code | `docs/concepts/<topic>.md` |
| Glossary entry | `docs/glossary.md` |
| Citation | `docs/references.bib` |

File names are `snake_case`, matching the header they describe.

## Linking

Every article starts with a label named after its topic:

```markdown
(mahalanobis-distance)=
# Mahalanobis distance
```

Link to it with `` {ref}`mahalanobis-distance` `` or
`[custom text](#mahalanobis-distance)`. Labels don't depend on file paths, so
moving an article never breaks a link. Use plain relative Markdown links only
within a module.

Other references:

| Target | Syntax |
|---|---|
| Section label | `` {ref}`label` `` |
| Numbered equation | `` {eq}`label` `` (define with `$$ ... $$ (label)`) |
| Glossary term | `` {term}`Innovation` `` |
| Citation | `` {cite}`barshalom2001` `` (key from `references.bib`) |
| Definition / theorem / algorithm | `` {prf:ref}`label` `` |
| Source on GitHub | full `https://github.com/rkeatin3/sketchbook/blob/main/...` URL |

The build runs with warnings as errors, so a broken reference of any kind fails
CI.

## Embedding code

Show the implementation inside the article by including it from the real source
file, so the docs never drift from the code. Prefer named markers to line
numbers, because markers survive edits:

````markdown
```{literalinclude} mahalanobis.hpp
:language: cpp
:start-after: "[doc:mahalanobis]"
:end-before: "[/doc:mahalanobis]"
```
````

with the region marked in the source:

```cpp
// [doc:mahalanobis]
...
// [/doc:mahalanobis]
```

In the other direction, each header's top comment names the article it
implements by its path relative to the repository root.

## Math

Use `$...$` for inline math and `$$...$$` for display math. Add a label to
number an equation and reference it from anywhere:

```markdown
$$
d^2 = \nu^\top S^{-1} \nu
$$ (eq-mahalanobis)
```

Multi-line derivations use `\begin{align} ... \end{align}`. Definitions,
theorems, proofs, and algorithms use the `sphinx-proof` directives
(`{prf:definition}`, `{prf:theorem}`, `{prf:proof}`, `{prf:algorithm}`), each
with a `:label:` so it can be referenced.

## Building locally

See the Development section of the
[README](https://github.com/rkeatin3/sketchbook#development) for the live
preview. CI runs the strict build:

```bash
sphinx-build -c docs -W --keep-going . docs/_build/html
```
