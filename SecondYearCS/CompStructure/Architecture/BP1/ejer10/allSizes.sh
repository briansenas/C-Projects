#!/bin/bash

echo "Tiempo ejecución secuencial:"
for i in $(seq 14 26); do
    A=`echo "2^$i" | bc `
    ./SumaVectoresG $A
done

echo "Tiempo ejecución de OpemMP-FOR:"
for i in $(seq 14 26); do
    A=`echo "2^$i" | bc `
    ./sp-OpenMP-for $A
done

echo "Tiempo ejecución de OpenMP-sections:"
for i in $(seq 14 26); do
    A=`echo "2^$i" | bc `
    ./sp-OpenMP-sections $A
done
