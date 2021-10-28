#!/bin/bash

export OMP_NUM_THREADS=3

echo -e "\n[NONMONOTONIC:STATIC]"
for i in $(seq 1 2); do
  echo -e "\n[X==$i]"
  export OMP_SCHEDULE=nonmonotonic:static,$i
  ./schedule-clause 16 | sort -n | cut -d ":" -f2-
done
