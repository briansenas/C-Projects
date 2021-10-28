#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc, char *argv[]) {
    pid_t pid; // Para diferenciar entre padre y hijo.

    int i = 0;
    if (argc < 2) {
        printf("Error en ejecución, tiene que ser ./ejecutable <integer>");
        exit(-1);
    } else {
        i = atoi(argv[1]);
    }

    if ((pid = fork()) < 0) {
        perror("Error en el fork");
        exit(-1);
    } else if (pid == 0) {
        //Soy el proceso hijo;

        printf("\n\t#######################################\t\n\n");
        printf("Mi pid es %d \n", getpid());
        printf("El pid de mi padre es %d\n", getppid());
        printf("Mi UID es %d\n", getuid());
        printf("Mi EUID es %d\n", geteuid());
        printf("Mi GID es %d\n", getgid());
        printf("Mi EGID es %d\n", getegid());
        if (i % 2 == 0)
            printf("El número %d es par\n", i);
        else
            printf("El número %d es impar\n", i);
        printf("\n\t#######################################\t\n\n");
    } else {
        //Soy el proceso padre:
        sleep(1);
        printf("Mi pid es %d \n", getpid());
        printf("El pid de mi padre es %d\n", getppid());
        printf("Mi UID es %d\n", getuid());
        printf("Mi EUID es %d\n", geteuid());
        printf("Mi GID es %d\n", getgid());
        printf("Mi EGID es %d\n", getegid());
        if (i % 4 == 0)
            printf("El número %d es divisible por 4\n", i);
        else
            printf("El número %d no es divisible por 4\n", i);
        printf("\n\t#######################################\t\n\n");
    }

    return 0;
}