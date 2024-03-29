#include <stdio.h>

#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
#endif

int main(int argc, char const *argv[]){
  int i, n=10;
  int a[n], suma=0;

  for(i=0;i<n;++i) a[i] = i;

#pragma omp parallel for firstprivate(suma) 
  for(i=0;i<n;i++){
    suma = suma + a[i];
    printf("thread %d, suma a[%d] SUMA = %d\n", omp_get_thread_num(), i, suma);
  }

  printf("\nFuera de la region parallel suma = %d \n", suma);

  return 0;

}
