#!/bin/bash -l

### Written by Dr Maryam Abo-Tabik

# Specify the current working directory as the location for executables/files
# This is the default setting.
#SBATCH -D ./

# Export the current environment to the compute node
# This is the default setting.
#SBATCH --export=ALL

# Specific course queue, exclusive use (for timings), max 5 min wallclock time
#SBATCH -p course
#SBATCH --exclusive
#SBATCH -t 5

# just 1 thread to run on
export OMP_NUM_THREADS=1

CC=gcc
#GNU Compiler
echo running program
#Add compiler instructions here
$CC ./memory_access.c -O3 -g2 -flto -o ./memory_access

#Execute file here
#./memory_access

echo '-------'



