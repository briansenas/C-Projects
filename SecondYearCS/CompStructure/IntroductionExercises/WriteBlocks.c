/*
tarea1.c
Trabajo con llamadas al sistema del Sistema de Archivos ''POSIX 2.10 compliant''
Probad tras la ejecución del programa: $>cat archivo y $> od -c archivo
*/
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(int argc, char *argv[]) {
    int fi;
    if ((fi = open("entrada.txt", S_IRUSR)) < 0) {
        printf("\n Error %d en open entrada.txt", errno);
        perror("\n Error en open entrada.txt\n");
        exit(-2);
    }
    int fd;
    if ((fd = open("salida.txt", O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR)) < 0) {
        printf("\nError %d en open", errno);
        perror("\nError en open\n");
        exit(-1);
    }
    int cont = 0;
    char buf1[81] = "Espacio Titulo\n", ch[1];

    if (write(fd, buf1, 80) != 80) { //Para poder poner el titulo luego;
        printf("\nError %d en write title", errno);
        perror("\nError en write title\n");
        exit(-1);
    }

    while (read(fi, ch, 1) != 0) {
        lseek(fi,-1L,SEEK_CUR);
        sprintf(buf1, "Bloque %d\n", cont);
        if (write(fd, buf1, 10) != 10) {
            printf("\nError %d en write title", errno);
            perror("\nError en write title\n");
            exit(-1);
        }
        if (read(fi, buf1, 80) == 0) {
            printf("\nError %d en read", errno);
            perror("\nError en read\n");
            exit(-1);
        }
        buf1[80] = '\n';
        if (write(fd, buf1, 81) != 81) {
            printf("\nError %d en write block", errno);
            perror("\nError en write block\n");
            exit(-1);
        }
        cont++;
    }
    lseek(fd,0,SEEK_SET);
    char title[30];
    sprintf(title,"El nº de bloques es: %d\n", cont);
    if (write(fd, title, 30) != 30) { //Para poder poner el titulo luego;
        printf("\nError %d en write title", errno);
        perror("\nError en write title\n");
        exit(-1);
    }

    close(fi);
    close(fd);
    return 0;
}