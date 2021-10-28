#include <stdio.h>
#include <stdlib.h>

#ifdef _OPENMP
  #include <omp.h>
#else
  #define omp_get_thread_num() 0
#endif

int main(int argc, char const* argv[])
{
  if(argc<2){
    fprintf(stderr,"[ERROR] Exec: ./{this} {size}\n");
    exit(-1);
  }

  omp_sched_t tipo;
  int modif;

  int i,n,j,suma;
  int **m, *v, *v_result;
  double t_ini, t_fin, t_elap;

  n=atoi(argv[1]);

  v = (int*)malloc(n*sizeof(int));
  v_result = (int*)malloc(n*sizeof(int));
  m = (int**)malloc(n*sizeof(int*));

  if((v==NULL)||(v_result==NULL)||(m==NULL)){
    fprintf(stderr,"[ERROR] Couldn't reserve memory\n");
    exit(-2);
  }

  for(int i=0;i<n;++i){
    m[i]=(int*)malloc(n*sizeof(int));
    if(m[i]==NULL){
      fprintf(stderr,"[ERROR] Not enough memory for column: %d\n",i);
      exit(-2);
    }
  }

  //inicialización
  for(i=0;i<n;++i){
    for(j=0;j<n;++j){
      if(i<=j)
        m[i][j]=2;
      else
        m[i][j]=0;
    }
    v[i]=3;
    v_result[i]=0;
  }


  //Cálculo
  #pragma omp parallel private(j)
  {
    #pragma single
    t_ini = omp_get_wtime();

    #pragma omp for private(suma) schedule(runtime)
    for(i=0;i<n;++i){
      suma=0;
      for(j=0;j<n;++j){
        suma+=m[i][j]*v[j];
      }
    #pragma single 
      v_result[i]=suma;
    }

    #pragma single
    t_fin = omp_get_wtime();

  }

  t_elap = t_fin - t_ini;
  printf("Tiempo (seg.):%11.9f\t tamaño: %d\n", t_elap,n);
  printf("v_result[%d]=%d\n",0,v_result[0]);
  printf("v_result[%d]=%d\n",n-1,v_result[n-1]);

  omp_get_schedule(&tipo,&modif);
  if(tipo==omp_sched_static)
    printf("[STATIC]");
  else if(tipo==omp_sched_dynamic)
    printf("[DYNAMIC]");
  else if(tipo==omp_sched_guided)
    printf("[GUIDED]");
  else
    printf("[AUTO]");

  printf("chunk:%d\n",modif);
  free(v);
  free(v_result);

  for(int i=0;i<n;++i)
    free(m[i]);

  free(m);
  return 0;
}
