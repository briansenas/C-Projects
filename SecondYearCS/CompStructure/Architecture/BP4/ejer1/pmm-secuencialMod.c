#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
#endif

int main(int argc, char const* argv[])
{
  if(argc<2){
    fprintf(stderr, "[ERROR] Exec: ./{this} {size}");
    exit(-1);
  }

  unsigned int n=atoi(argv[1]);
  double **m, **a, **b;
  a = (double**)malloc(n*sizeof(double*));
  b = (double**)malloc(n*sizeof(double*));
  m = (double**)malloc(n*sizeof(double*));

  if(a==NULL | b==NULL | m == NULL){
    fprintf(stderr,"[MEM_ERROR]");
    exit(-2);
  }

  //Inicializacion
  srand(time(NULL));
  for(int i=0;i<n;++i){
    m[i] = (double*)malloc(n*sizeof(double));
    a[i] = (double*)malloc(n*sizeof(double));
    b[i] = (double*)malloc(n*sizeof(double));
    if(a[i]==NULL | b[i]==NULL |  m[i]==NULL){
    fprintf(stderr,"[MEM_ERROR]");
    exit(-2); 
    } for(int j=0;j<n;j++){
      a[i][j]= drand48();
      b[i][j] = drand48();
      m[i][j] = 0;
    }
  }
  
  //calculo
  double t_ini = omp_get_wtime();
  for(int i=0;i<n;i++){
    for(int j=0; j<n;j+=4){
      for(int k=0; k<n;k++){
        m[i][j] = a[i][k] * b[k][j];
        m[i][j+1] = a[i][k] * b[k][j+1];
        m[i][j+2] = a[i][k] * b[k][j+2];
        m[i][j+3] = a[i][k] * b[k][j+3];
      }
    }
  }
  double tiempo = omp_get_wtime() - t_ini;

  printf("Tiempo(seg.): %11.9f\n", tiempo);

  printf("m[%d] = %f\n",0,m[0][0]);
  printf("m[%d] = %f\n",n-1,m[n-1][n-1]);

  for(int i=0;i<n;++i){
    free(m[i]);
    free(a[i]);
    free(b[i]);
  }

  free(m);
  free(a);
  free(b);

  return 0;

}
