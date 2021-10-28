// tarea9.c
#include <signal.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main() {
    struct sigaction sa;
    sa.sa_handler = SIG_IGN; // ignora la señal
    sigemptyset(&sa.sa_mask);
    //Reiniciar las funciones que hayan sido interrumpidas por un manejador
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        printf("error en el manejador");
    }
    while (1);
}