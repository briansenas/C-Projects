#include <stdio.h>
#include <omp.h>

// gcc -O2 -fopenmp -o single single.c

int main(){
  int n=9, i, a, b[n];

  for(i=0;i<n;i++) b[i]=-1;

#pragma omp parallel
  {
#pragma omp single
    {
      printf("introduce valor de inicialización a:");
      scanf("%d",&a);
      printf("Single ejecutada por el thread %d\n", omp_get_thread_num());
    }

#pragma omp for
    for(i=0;i<n;++i) b[1]=a;


#pragma omp master
    {
      printf("Despues de la región parallel:\n");
      for(i=0;i<n;++i)
        printf("b[%d] = %d (%d)\t",i,b[i],omp_get_thread_num());
      printf("\n");
    }
  }
  return 0;

}
