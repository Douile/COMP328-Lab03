#!/bin/sh

set -x

CC=icc
FILE="${1:-matrix2D.c}"
BASE_FILE="$(basename "$FILE" ".c")"

for level in $(seq 0 3); do
  output="$BASE_FILE-o$level"
  $CC "-O$level" "$FILE" -o "$output" -qopt-report3
  mv "$BASE_FILE.optrpt" "$output.optrpt"
done