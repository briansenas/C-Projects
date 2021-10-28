#include <signal.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include <string.h>
#include <sys/mman.h>

#define MMAPSIZE 1

int main(int argc, char *argv[]) {
    off_t len;
    char bufer='a';
    char *cnt;
    int fd;
    fd = open("Archivo", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
    if(fd == -1){
        perror("[ERROR]EL archivo existe");
        exit(-1);
    }
    write(fd, &bufer, sizeof(char));
    cnt = (char *)mmap(0,MMAPSIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(cnt == MAP_FAILED){
        perror("[ERROR] Fallo de mapeo\n");
        exit(-1);
    }
    if(close(fd)==-1){
        perror("[ERROR] Can't close file\n");
        exit(-2);
    }
    if(fork() == 0){
        sleep(2);
        printf("El valor de cnt es: %s ", cnt);
        exit(0);
    }
    strcpy(cnt,"b");
    return (0);
}
