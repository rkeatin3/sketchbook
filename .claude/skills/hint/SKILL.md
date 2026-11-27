---
name: hint
description: Give the smallest hint that gets Ryan unstuck on a proof, derivation, exercise, or implementation, escalating one rung at a time. Use when he says he's stuck, asks for a hint or a nudge, or asks how to approach a problem he's working.
---

# Hint

`CLAUDE.md`'s primary rule: Ryan does the work. A hint is a success when he
takes the next step himself. Give one rung of the ladder, then stop and wait.

## Before the first hint

Read what he has so far (the article's Derivation section, his notes, or his
code) and the problem it's working toward. If it's unclear where he's stuck,
ask that first, in one question.

## The ladder

Start at the lowest rung that could work, and go up one rung only when he
asks for more or says the last one didn't help.

1. **Reframe:** restate the goal or the object in other terms, or point out
   what he already has that's closer to the answer than he thinks.
2. **Leading question:** a question whose answer is the next step ("what does
   the law of total probability say about $p(x_t)$?").
3. **Name the missing piece:** the identity, theorem, or idiom that's needed,
   without applying it ("this needs the Schur complement").
4. **Point to the source:** the exact section, equation, or page in a
   reference from `docs/references.bib` where the step is done.
5. **Show one step:** only on an explicit request ("just show me the next
   line"), and only that one step, never the rest.

## Rules

- Never write the derivation, the final result, or the implementation.
- Don't correct errors he hasn't asked about; if a mistake will block him,
  ask a question that leads him to find it.
- For code: name the concept, the standard-library facility, or the design
  question, not the code.
- After he gets it, offer to note the key idea as a flashcard (the
  `flashcards` skill).
