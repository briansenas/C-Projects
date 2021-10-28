#include <time.h>
#include <stdlib.h>
#include <omp.h>
#include <stdio.h>


int main(int argc, const char* argv[])
{
  
  if(argc<2){
    fprintf(stderr,"[ERROR] Exec: ./{this} {size1} ");
    exit(-1);
  }

  int N = atoi(argv[1]);

  double y[N], x[N];
  srand48(time(NULL));
  //Inicializacion
  if(N<8){
    for(int i=0;i<N;i++){
      y[i] = i;
      x[i] = N-i;
    }
  }else{
    for(int i=0;i<N;i++){
      y[i] = drand48();
      x[i] = drand48();
    }
  }

  //calculo
  int X1, X2;
  double a = drand48();

  double t_ini = omp_get_wtime();
  //Código Daxpy
  for(int i=0;i<N;i++)
    y[i] = a*x[i] + y[i];

  double tiempo = omp_get_wtime() - t_ini;

  printf("Tiempo(segs.): %11.9f\n", tiempo);

}
