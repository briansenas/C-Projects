#!/bin/bash

echo -e "\n[MONOTONIC:STATIC,DEFAULT]"
  export OMP_SCHEDULE="monotonic:static"
  ./pmtv-OpenMP 17280

echo -e "\n[MONOTONIC:STATIC,1]"
  export OMP_SCHEDULE="monotonic:static,1"
  ./pmtv-OpenMP 17280

echo -e "\n[MONOTONIC:STATIC,1]"
  export OMP_SCHEDULE="monotonic:static,64"
  ./pmtv-OpenMP 17280

echo -e "\n[MONOTONIC:DYNAMIC,DEFAULT]"
  export OMP_SCHEDULE="monotonic:dynamic"
  ./pmtv-OpenMP 17280

echo -e "\n[MONOTONIC:DYNAMIC,1]"
  export OMP_SCHEDULE="monotonic:dynamic,1"
  ./pmtv-OpenMP 17280

echo -e "\n[MONOTONIC:DYNAMIC,64]"
  export OMP_SCHEDULE="monotonic:dynamic,64"
  ./pmtv-OpenMP 17280

echo -e "\n[MONOTONIC:GUIDED,DEFAULT]"
  export OMP_SCHEDULE="monotonic:guided"
  ./pmtv-OpenMP 17280

echo -e "\n[MONOTONIC:GUIDED,1]"
  export OMP_SCHEDULE="monotonic:guided,1"
  ./pmtv-OpenMP 17280

echo -e "\n[MONOTONIC:GUIDED,64]"
  export OMP_SCHEDULE="monotonic:guided,64"
  ./pmtv-OpenMP 17280
