#include <signal.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include <string.h>


int main(int argc, char *argv[]) {
    if (argc != 4) {
        perror("[ERROR] Format: ./(this) <function1> | <function2>");
        exit(-1);
    }
    int fd,fd2;
    if ((fd = open("./temporal", O_CREAT | O_RDWR)) < 0) {
        perror("[ERROR] OpeningFile");
        exit(-2);
    }
    if (strcmp(argv[2], "|") == 0) {
        close(STDOUT_FILENO);
        fcntl(fd, F_DUPFD, STDOUT_FILENO);
        execlp(argv[1], argv[1], NULL);
        execl(argv[3], argv[3], NULL);
    }
    return (0);
}
