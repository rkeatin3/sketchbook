(module-containers)=
# Containers

Data structures implemented from scratch: what the standard library provides, what it doesn't, and the invariants that make each one correct.

**Status:** not started ·
[source](https://github.com/rkeatin3/sketchbook/tree/main/src/utilities/containers)

## Why it matters

_What problem this solves, and where it shows up in a real system._

## Prerequisites

_Language features and other modules this builds on._

## Roadmap

- A fixed-capacity ring buffer, single-threaded and then lock-free single-producer/single-consumer

## Articles

```{toctree}
:maxdepth: 1
```

## Where it's used

Measurement histories, fixed-lag windows, and sensor queues in the {doc}`tracker </src/robotics/tracking/README>`.

## References

_Key texts for this module, cited from `docs/references.bib`._
