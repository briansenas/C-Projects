#include<sys/types.h>
#include <sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>
#include <string.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
    int fd1[2], fd2[2];
    int bytesLeidos, bytesLeidos2, val1, val2, estado;
    pid_t esclavo1, esclavo2;
    int intervalos[6];
    char inicio[10];
    char fin[10];

    if (argc < 3) {
        perror("Usos ./maestro <inicio> <fin>\n");
        exit(-1);
    }

    /*if (setvbuf(stdout, NULL, _IONBF, 0)) {
        perror("\nError en setvbuf");
    }*/

    //División de Intervalos
    intervalos[0] = atoi(argv[1]);
    intervalos[1] = atoi(argv[2]);
    intervalos[2] = intervalos[0];
    intervalos[3] = (intervalos[0] + intervalos[1]) / 2;
    intervalos[4] = intervalos[3] + 1;
    intervalos[5] = intervalos[1];

    //Creación de los cauces
    pipe(fd1);
    pipe(fd2);

    esclavo1 = fork();
    sprintf(inicio, "%d", intervalos[2]);
    sprintf(fin, "%d", intervalos[3]);
    printf("\nNumeros primos en el intervalo [%d,%d]: \n", intervalos[2], intervalos[3]);
    if (esclavo1 == 0) {
        close(fd1[0]);
        dup2(fd1[1], STDOUT_FILENO);
        if (execl("./esclavo", "esclavo", inicio, fin, NULL) < 0) {
            perror("\n[ERROR_1] Execl failed.");
            exit(-1);
        }
    } else {
        esclavo2 = fork();
        sprintf(inicio, "%d", intervalos[4]);
        sprintf(fin, "%d", intervalos[5]);
    }
    if (esclavo2 == 0) {
        close(fd2[0]);
        dup2(fd2[1], STDOUT_FILENO);
        if (execl("./esclavo", "esclavo", inicio, fin, NULL) < 0) {
            perror("\n[ERROR_2] Execl failed.");
            exit(-2);
        }
    }
    esclavo1 = waitpid(&estado);
    esclavo2 = waitpid(&estado);

    close(fd1[1]); //Cerramos el cauce de escritura_1
    int i = 0;
    while ((bytesLeidos = read(fd1[0], &val1, sizeof(int))) > 0) {
        printf("%d ", val1);
        i++;
    }
    close(fd1[0]); //Cerramos el cauce de lectura_1
    printf("\nNumeros primos en el intervalo [%d,%d]: \n", intervalos[4], intervalos[5]);
    close(fd2[1]); //Cerramos el cauce de escritura_2
    i = 0;
    while ((bytesLeidos2 = read(fd2[0], &val2, sizeof(int))) > 0) {
        printf("%d ", val2);
        i++;
    }
    close(fd2[0]); //Cerramos el cauce de lectura_2
    printf("\n");
    return (0);
}
