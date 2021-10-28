#include <stdio.h>
#include <stdlib.h>

#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
#endif

//#define GLOBAL //Para vectores y matriz globales
#define DYNAMIC //Para vectores y matriz dinamicos

//gcc -O2 -fopenmp -o Pvm_secuencial Pmv_secuencial.c

#ifdef GLOBAL
    #define MAX 25 //2^25
#endif

int main(int argc, char const* argv[])
{
  if(argc<2){
    fprintf(stderr,"[ERROR]: Execution: ./{this} [int size]");
    exit(-1);
  }

  unsigned int n = atoi(argv[1]);

#ifdef GLOBAL
  if(n>MAX){
      n=MAX;
      printf("n=%d\n",n);
  }
  int m[n][n], v1[n], v2[n];
#endif

#ifdef DYNAMIC
  int **m, *v1, *v2;
  v1 = (int*) malloc(n*sizeof(int));
  v2 = (int*) malloc(n*sizeof(int));
  m = (int**) malloc(n*sizeof(int*));

  if((v1 == NULL) || (v2 == NULL) || (m == NULL)){
    printf("[MEMORY ERROR] Unable to reserve memory, malloc error;");
    exit(-2);
  }
int i; 
#pragma omp for 
  for(i=0;i<n;++i){
    m[i] = (int*)malloc(n*sizeof(int));
    if(m[i]==NULL){
      printf("[MEMORY ERROR 2] Unable to reserve memory for row %d", i);
      exit(-2);
    }
  }

#endif

  int half = n / 2;

#pragma omp for 
  for(i=0; i<n;++i){
    for(int j=0;j<n;++j){
      m[i][j]=2;
    }
    v1[i]=3;
    v2[i]=0;
  }

  double time_start = omp_get_wtime();

#pragma omp for 
  for(i=0;i<n;++i){
    for(int j=0;j<n;++j){
      v2[i]+=m[i][j] * v1[j];
    }
  }

  double total_time = (double)(omp_get_wtime() - time_start);

  printf("Tiempo (seg.) %11.9f\n", total_time);

  if(n>25){
    printf("(");
    for(int i=0;i<6;++i){
      if(i+1==6)
        printf("...,%d)\n", v2[n-1]);
      else if(i<5)
        printf("%d, ", v2[i]);
    }
  }else{
    for(int i=0;i<n;i++){
      printf(" |");
      for(int j=0;j<n;++j){
        if(j+1==n)
          printf("%d| ",m[i][j]);
        else
          printf("%d ", m[i][j]);
      }
      if(half==i)
        printf("x |%d| = |%d| \n", v1[i], v2[i]);
      else
        printf("  |%d|   |%d| \n", v1[i], v2[i]);
    }
  }
  
  printf("V2[%d]=%d\n", 0, v2[0]);
  printf("V2[%d]=%d\n", n-1, v2[n-1]);

#ifdef VECTOR_DYNAMIC
  free(v1);
  free(v2);

  for(int i=0;i<n;++i)
    free(m[i]);

  free(m);

#endif

  return 0;
}
