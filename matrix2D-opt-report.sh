#!/bin/sh

CC=icc
FILE="$(1:-matrix2D.c)"
BASE_FILE="$(basename "$FILE" ".c")"

for level in $(seq 0 3); do
  $CC "-O$level" "$FILE" -o "$BASE_FILE-o$level" -qopt-report3
done