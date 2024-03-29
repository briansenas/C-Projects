#include <stdio.h>
#include <stdlib.h>

#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
#endif

int main(int argc, char const *argv[])
{
  int i, n=20, a[n], suma=10;

  if(argc<2){
    fprintf(stderr, "Error falta recibir por paramentro un numero.\n");
    exit(-1);
  }

  n = atoi(argv[1]);
  if(n>20){
    n=20;
    printf("\n n = %d\n", n);
  }

  for(i=0;i<n;++i) a[i] = i;

#pragma omp parallel for 
  for(i=0;i<n;++i){
#pragma omp atomic
    suma+=a[i];
  }

  printf("\nFuera de la region parallel: suma = %d\n",suma);
  return 0;

}
