#include <stdio.h>

#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
#endif

int main(int argc, char const *argv[]){
  int i, n=9, b[n];

  for(i=0;i<n;++i) b[i]=-1;

#pragma omp parallel
  {
    int a;
#pragma omp single
    {
      printf("Introduce valor de a: ");
      scanf("%d",&a);
      printf("\n Single ejecutada por la hebra: %d\n", omp_get_thread_num());
    }
#pragma omp for
    for(i=0;i<n;++i) b[i]=a;
  }

  printf("\nFuera de la reigon parallel:\n");
  for(i=0;i<n;++i) printf("b[%d] = %d\n",i, b[i]);

  return 0;

}
