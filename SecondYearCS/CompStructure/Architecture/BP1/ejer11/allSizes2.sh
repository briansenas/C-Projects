#!/bin/bash

echo "Tiempo ejecución secuencial:"
for i in $(seq 23 26); do
    A=`echo "2^$i" | bc `
    time ./SumaVectoresG $A
done

echo "Tiempo ejecución de OpemMP-FOR:"
for i in $(seq 23 26); do
    A=`echo "2^$i" | bc `
    time ./sp-OpenMP-for $A
done

echo "Tiempo ejecución de OpenMP-sections:"
for i in $(seq 23 26); do
    A=`echo "2^$i" | bc `
    time ./sp-OpenMP-sections $A
done
