#!/bin/bash

#echo "Tiempo en ejecución paralela atcgrid[1-3] (10000):"
#for i in $(seq 1 32); do
#    export OMP_NUM_THREADS=$i
#    ./pmv_OpenMP-a 10000
#done

echo "Tiempo en ejecución paralela atcgrid[1-3] (100000):"
for i in $(seq 1 32); do
    export OMP_NUM_THREADS=$i
    ./pmv_OpenMP-a 20000
done
