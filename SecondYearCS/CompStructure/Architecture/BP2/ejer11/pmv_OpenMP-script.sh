#!/bin/bash

echo "Tiempo en ejecución secuencial atcgrid[1-3] (10000-100000):"
srun -pac -Aac ./pmv_secuencial 100000
srun -pac -Aac ./pmv_secuencial 1000000

echo "Tiempo en ejecución secuencial atcgrid4 (10000-100000):"
srun -pac4 -Aac ./pmv_secuencial 10000
srun -pac4 -Aac ./pmv_secuencial 100000

echo "Tiempo en ejecución paralela atcgrid[1-3] (10000):"
for i in $(seq 1 32) do
    export OMP_NUM_THREADS=$i
    echo $i
    srun -pac -Aac ./pmv_secuencial 10000
done

echo "Tiempo en ejecución paralela atcgrid[1-3] (100000):"
for i in $(seq 1 32) do
    export OMP_NUM_THREADS=$i
    echo $i
    srun -pac -Aac ./pmv_secuencial 100000
done
