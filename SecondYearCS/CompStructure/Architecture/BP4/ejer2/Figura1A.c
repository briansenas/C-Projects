#include <time.h>
#include <stdlib.h>
#include <omp.h>
#include <stdio.h>


int main(int argc, const char* argv[])
{
  
  if(argc<3){
    fprintf(stderr,"[ERROR] Exec: ./{this} {size1} {size2}");
    exit(-1);
  }

  int N = atoi(argv[1]);
  int M = atoi(argv[2]);

  struct {
    int a;
    int b;
  } S[N];
  
  int R[M];
  for(int i=0;i<M;i++)
    R[i] = 0;

  srand(time(NULL));
  
  //Inicializacion
  if(N<8){
    for(int i=0;i<N;i++){
      S[i].a = i;
      S[i].b = N-i;
    }
  }else{
    for(int i=0;i<N;i++){
      S[i].a = rand()%255;
      S[i].b = rand()%255;
    }
  }

  //calculo
  int X1, X2;
  double t_ini = omp_get_wtime();

  for(int i=0;i<M;i++){
    X1=0; X2=0;
    for(int j=0;j<N;j++) X1+=(S[i].a>>1)+i;
    for(int j=0;j<N;j++) X2+=(S[i].a>>1 + S[i].a)-i;

    if (X1<X2) R[i]=X1;
    else R[i]=X2;
  }

  double tiempo = omp_get_wtime() - t_ini;

  printf("Tiempo(segs.): %11.9f\n", tiempo);

}
