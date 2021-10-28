#!/bin/bash

echo "Tiempo en ejecución paralela código A (10000):"
for i in $(seq 1 32); do
    export OMP_NUM_THREADS=$i
    ./pmv_OpenMP-a 10000
done

echo "Tiempo en ejecución paralela código B (10000):"
for i in $(seq 1 32); do
    export OMP_NUM_THREADS=$i
    ./pmv_OpenMP-b 10000
done

echo "Tiempo en ejecución paralela código C (10000):"
for i in $(seq 1 32); do
    export OMP_NUM_THREADS=$i
    ./pmv_OpenMP-reduction 10000
done
