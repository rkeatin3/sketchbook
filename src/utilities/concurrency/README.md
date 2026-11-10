(module-concurrency)=
# Concurrency

Building blocks for concurrent C++: threads, synchronization, the memory model, and the abstractions built on them.

**Status:** not started ·
[source](https://github.com/rkeatin3/sketchbook/tree/main/src/utilities/concurrency)

## Why it matters

_What problem this solves, and where it shows up in a real system._

## Prerequisites

_Language features and other modules this builds on._

## Roadmap

- A thread pool, with futures for results and cooperative cancellation via `std::stop_token`

## Articles

```{toctree}
:maxdepth: 1
```

## Where it's used

Parallel per-sensor processing and hypothesis evaluation in the {doc}`tracker </src/robotics/tracking/README>`.

## References

_Key texts for this module, cited from `docs/references.bib`._
