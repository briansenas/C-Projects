#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifdef _OPENMP
  #include <omp.h>
#else
  #define omp_get_thread_num() 0
#endif

void print_stuff(){
  omp_sched_t tipo;
  int modif;
  char type[20];
  omp_get_schedule(&tipo,&modif);
  printf("dyn-var:%d\nnthreads-var:%d\nthread-limit-var:%d\nrun-schedvar:%d\n", 
        omp_get_dynamic(),omp_get_max_threads(),omp_get_thread_limit(),modif);
 switch(tipo){
          case omp_sched_static:
            strcpy(type,"STATIC");
            break;
          case omp_sched_dynamic:
            strcpy(type,"DYNAMIC");
            break;
          case omp_sched_auto:
            strcpy(type,"AUTO");
            break;
          case omp_sched_guided:
            strcpy(type,"GUIDED");
            break;
          default:
            strcpy(type,"[ERROR SWITCH]");
            break;
 
       }
        printf("tipo:%s\n", type);
}

int main(int argc, char const* argv[])
{
  int i,n=200,chunk,a[n],suma=0;
  bool first = true;

  if(argc<3){
    fprintf(stderr, "[ERROR] Exec: ./{this} {size} {nº chunk(s)}\n");
    exit(-1);
  }

  n = atoi(argv[1]);
  chunk = atoi(argv[2]);

  if(n>200) n = 200;

  for(i=0;i<n;++i) a[i]=i;

#pragma omp parallel for firstprivate(suma) lastprivate(suma) schedule(dynamic, chunk)
  for(i=0;i<n;i++){
    if(first){
        first = false;
        #pragma single
        printf("\n\t############################### \n ");
        printf("\t Dentro del Bucle-for-paralelo \n");
                          print_stuff();
        printf("\t################################# \n\n");
    }
    suma+=a[i];
    //printf("thread:%d suma de a[%d], suma=%d\n",omp_get_thread_num(),i,suma);
  }

  printf("\n\t############################## \n");
  printf("\t Fuera del Bucle-for-paralelo \n");
                    print_stuff();
  printf("\t ############################### \n\n");
  return 0;
}
        
