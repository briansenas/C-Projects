#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

//gcc -O2 -fopenmp -o bucle-for bucle-for.c

int main(int argc, char **argv){

  int i, n = 9;

  if(argv < 2) {
    fprintf(stderr, "\n[ERROR] - Falta nº iteraciones \n");
    exit(-1);
  }

  n = atoi(argv[1]);


  #pragma omp parallel for

    for (i=0;i<n;i++)
      printf("thread %d ejecuta la itración %d del bucle\n", omp_get_thread_num(),i);

  return(0);
}
