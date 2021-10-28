#include <stdio.h>
#include <stdlib.h>

#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
#endif

//gcc -O2 -fopenmp -o single single.c

int main(int argc, char const* argv[]){
  int i,n=20, a[n], suma=0;

  if(argc<2){
    fprintf(stderr,"[ERROR] Exec: ./{this} {nº chunks}\n");
    exit(-1);
  }

  n=atoi(argv[1]); if(n>20) n=20;
  for(i=0;i<n;++i) a[i] = i;

#pragma omp parallel for firstprivate(suma) lastprivate(suma) schedule(runtime)
  for(i=0;i<n;++i){
    suma = suma + a[i];
    printf("%d: %d\n", i, omp_get_thread_num());
  }

  return 0;
}
