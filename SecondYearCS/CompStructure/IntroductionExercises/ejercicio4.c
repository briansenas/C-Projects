#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    pid_t childpid;
    int nprocs = 5,estado;
    for(int i=0;i < nprocs;i++){
        if((childpid = fork()) == -1){
            printf("\n[ERROR]Fork() gives -1");
            exit(-1);
        }
        if(!childpid){
            printf("Soy el hijo %d\n",getpid());
            exit(0);
        }
    }
    for(int i=nprocs-1;i>=0;i--){
        childpid = waitpid(&estado);
        printf("Ha finalizado mi hijo con PID = %i\n",childpid);
        printf("Solo me quedan %i hijos\n",i);
    }
    return 0;
}