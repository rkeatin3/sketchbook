#!/usr/bin/env bash
# Fetch benchmark datasets into //data. Each dataset is a separate function so
# they can be pulled individually — several are multi-gigabyte.
set -euo pipefail

DATA_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)/data"
mkdir -p "$DATA_DIR"

usage() {
  cat <<USAGE
usage: fetch_datasets.sh <dataset>

Available:
  silverbox     Nonlinear system identification (small, ~2 MB)
  ceb           Coupled Electric Drives (small)
  euroc         EuRoC MAV visual-inertial (large, ~30 GB for all sequences)
  kitti         KITTI odometry (very large)
USAGE
}

# TODO: implement per-dataset fetch logic as each benchmark is taken on.
case "${1:-}" in
  silverbox|ceb|euroc|kitti)
    echo "not yet implemented: $1" >&2
    exit 1
    ;;
  *) usage; exit 2 ;;
esac
