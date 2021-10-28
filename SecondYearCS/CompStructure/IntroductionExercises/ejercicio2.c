#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc, char* argv[]){
    DIR* direct;
    unsigned int permisos;
    char* pathname;
    struct stat atributos;
    struct dirent *ed;
    char cadena[300];
    char cadena2[300];
    extern int errno;

    if(argc==3){
        pathname = argv[1];
        direct = opendir(pathname);
        permisos = strtol(argv[2],NULL,8);
    }else{
        printf("Uso: Ejercicio2.c <pathname> <permisos> \n");
        exit(-1);
    }

    //Lee la entrada donde esta situado el puntero de lectura de
    //flujo del directorio. Despues adelante el puntero una posicion;
    readdir(direct);

    //Inicializamos Ed con la siguiente lectura.
    while((ed=readdir(direct))!=NULL){

        //Guardamos en cadena el pathname;
        sprintf(cadena,"%s/%s", pathname, ed->d_name);
        //Comprobación de que se puede acceder a los atributos del directorio.
        if(stat(cadena,&atributos)<0){
            //Hemos inicializado la variable atributo ahora.
            printf("\nError al intentar acceder a los atributos de archivo");
            perror("\nError en lstat");
            exit(-1);
        }
        //Si es un archivo regular accedemos a sus atributos
        if(S_ISREG(atributos.st_mode)){
            sprintf(cadena2,"%s",ed->d_name); //Lo guardamos en cadena2
            printf("%s: %o", cadena2, atributos.st_mode); //Imprimimos permisos
            chmod(cadena,permisos);
            if(chmod(cadena,permisos)<0){
                printf("Error: %s\n",strerror(errno));
            }else{
                stat(cadena,&atributos);
                printf("%o \n",atributos.st_mode); //Visualizamos cambios
            }
        }
    }
    closedir(direct);
    return 0;
}