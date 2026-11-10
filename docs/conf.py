"""Sphinx configuration for the sketchbook wiki.

The source directory is the repository root, so articles can live beside the
code they explain. This file sits in docs/ and is selected with ``-c docs``:

    sphinx-build -c docs -W --keep-going . docs/_build/html

``include_patterns`` is the allow-list of what becomes a page; everything else
in the repository (sources, Bazel output symlinks, data) is invisible to Sphinx.
"""

project = "sketchbook"
author = "Ryan Keating"
copyright = "Ryan Keating"

root_doc = "docs/index"

include_patterns = [
    "docs/**",
    "src/**/*.md",
    "papers/README.md",
]
exclude_patterns = [
    "docs/_build",
    "**/BUILD.bazel",
]

extensions = [
    "myst_parser",
    "sphinx_proof",
    "sphinxcontrib.bibtex",
    "sphinx_tippy",
    "sphinx_copybutton",
]

# --- MyST -------------------------------------------------------------------

myst_enable_extensions = [
    "amsmath",  # \begin{align} ... \end{align} blocks
    "colon_fence",  # ::: fences for directives, readable in raw Markdown
    "deflist",
    "dollarmath",  # $inline$ and $$display$$ math
]
# Heading slugs, so [text](page.md#some-heading) resolves.
myst_heading_anchors = 3
# $$...$$ (label) gives numbered, cross-referenceable equations.
math_numfig = True
math_eqref_format = "Eq. {number}"
numfig = True

# --- Bibliography -------------------------------------------------------------

bibtex_bibfiles = ["references.bib"]
bibtex_default_style = "alpha"
bibtex_reference_style = "author_year"

# --- Strictness ---------------------------------------------------------------

# Every broken reference is a warning, and CI builds with -W, so a broken link
# fails the build. That is the wiki's integrity check.
nitpicky = True

# --- HTML ---------------------------------------------------------------------

html_theme = "sphinx_book_theme"
html_title = "sketchbook"
# The root page is docs/index; _extra/index.html redirects the site root to it.
html_extra_path = ["_extra"]
html_theme_options = {
    "repository_url": "https://github.com/rkeatin3/sketchbook",
    "repository_branch": "main",
    "use_repository_button": True,
    "use_source_button": True,
    "use_issues_button": False,
    "show_toc_level": 2,
    "home_page_in_toc": True,
}

# Hover previews for internal references and citations.
tippy_enable_mathjax = True
