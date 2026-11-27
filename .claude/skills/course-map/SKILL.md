---
name: course-map
description: Map a course's homework or lecture notes onto the wiki, linking each problem from the article it exercises and proposing articles for gaps, without solving anything. Use when starting a new homework, lecture, or course module, or when asked how course material fits the repo.
---

# Map course material

The courses being followed, and the phase each anchors, are in
`docs/courseware.md`. Local clones of course repositories are read-only
sources; link to the official upstream, not to a fork or a local path.

## 1. Read the material

Read the homework and the lecture notes it draws on, in full. For each
problem, note what concept it exercises and whether it's a proof, a
calculation, or a coding task.

## 2. Map each problem

For each problem, find the article that covers its concept (search labels
and titles across the wiki). Then:

- **Covered:** add it to that article's Exercises, by source and number with
  a link. Never copy the problem statement. Mark coding tasks with the target
  they lead to.
- **Covered but missing a result:** add the result to the article's
  "_To prove:_" list, named but not answered.
- **Not covered:** propose a new article, preferring a module with code over
  a concept page. Scaffold it only if asked (the `scaffold-article` skill).

## 3. Update the plan

Add the mapping to the module plan's course alignment table, and adjust its
work chunks if a problem changes what a chunk includes or its order.

## 4. Report

Summarize the mapping in a table, list the gaps and proposed articles, and
note anything the course does differently from the wiki (notation,
conventions, scope).

Don't work any problem, even partly. Hints on request follow the `hint`
skill.
