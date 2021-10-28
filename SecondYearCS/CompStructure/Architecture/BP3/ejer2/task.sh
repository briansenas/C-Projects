#!/bin/bash

export OMP_NUM_THREADS=3

echo -e "\n[MONOTONIC:STATIC]"
for i in $(seq 1 2); do
  echo -e "\n[X==$i]"
  export OMP_SCHEDULE="monotonic:static,$i"
  ./schedule-clause 16 | sort -n | cut -d ":" -f2-
done

echo -e "\n[NONMONOTONIC:STATIC]"
for i in $(seq 1 2); do
  echo -e "\n[X==$i]"
  export OMP_SCHEDULE="nonmonotonic:static,$i"
  ./schedule-clause 16 | sort -n | cut -d ":" -f2-
done

echo -e "\n[MONOTONIC:DYNAMIC]"
for i in $(seq 1 2); do
  echo -e "\n[X==$i]"
  export OMP_SCHEDULE="monotonic:dynamic,$i"
  ./schedule-clause 16 | sort -n | cut -d ":" -f2-
done

echo -e "\n[MONOTONIC:GUIDED]"
for i in $(seq 1 2); do
  echo -e "\n[X==$i]"
  export OMP_SCHEDULE="monotonic:guided,$i"
  ./schedule-clause 16 | sort -n | cut -d ":" -f2-
done
