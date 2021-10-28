#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int nprocs = 20;
    pid_t childpid;
    int i;
    for (i = 1; i < nprocs; i++) {
        if ((childpid = fork()) == -1) {
            fprintf(stderr, "Could not create child %d: %s\n", i, strerror(errno));
            exit(-1);
        }
        if (!childpid){ //childpid = jerarquía horizontal, !childpid == jerarquía vertical
            printf("\nMi PID %d y mi PPID %d y valor i %d\n",getpid(),getppid(),i);
            printf("The actual childpid %d",childpid);
            break;
        }
        printf("\n");
    }
    return 0;
}