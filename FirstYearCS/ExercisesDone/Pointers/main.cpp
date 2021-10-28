#include <iostream>

using namespace std;

void GET_TEXT(char* Ptexto, int* Pcont, int* Pfin_linea,int* Psalto);
void GET_PALABRA(char* palabra, int* cont, bool* error_clave);
void BUSCADOR(char* texto, int tam_util, char* palabra, int tam_palabra, int* index, int* n_index);
void PRINT_RESULTS(char* texto, int* index, int* n_index, int* fin_linea);

int main()
{
   //Condiciones
   bool seguir = true;
   bool error_clave = false;
   //VARIABLES
   int cont = 0;
   int salto = 1;
   const int TAM1 = 1000; const int TAM2 = 500; const int TAM3 = 250;
   char texto[TAM1];
   char palabra[TAM2];
   //Almacenan en que linea esta la palabra y la longitud de cada linea respectivamente.
   int index[TAM3] = {0}, fin_linea[TAM3];
   int tam_util;

   GET_TEXT(texto, &cont, fin_linea, &salto); //Funcion por Referencia

   //Error al introdufuncioncir el texto
   if(cont==0) {
      seguir=false;
      cout << "Tiene un total de " << salto-1 << " lineas" << endl;
      cout << "No es posible realizar la busqueda, texto vacio " << endl;
   }
   tam_util=cont; //Guardamos el tamano util del vector;

   if(seguir) {
      cont = 0;
      GET_PALABRA(palabra,&cont,&error_clave); //Funcion por referencia

      if(!error_clave) {
         int tam_palabra = cont; //Guardamos el tamano de la palabra
         cout << "Tiene un total de " << salto-1 << " lineas" << endl; //Salto-1 para que no cuenta con la clave
         cout << "Vamos a buscar la palabra: ";
         for(int j = 0; j<cont; j++) {
            cout << palabra[j];
         }
         //BUSCADOR DE LA PALABRA
         int n_index = 0;
         BUSCADOR(texto,tam_util,palabra,tam_palabra,index,&n_index);

         //IMPRIMIMOS LAS SOLUCIONES
         PRINT_RESULTS(texto, index, &n_index, fin_linea);

      } //FIN IF CLAVE
   } //FIN IF SEGUIR
   return 0;
}
//FUNCIONES
void GET_TEXT(char* Ptexto, int* Pcont, int* Pfin_linea, int* Psalto)
{
//INTRODUCCION DEL TEXTO
   Pfin_linea[0]=0;//linea inicial
   char lineas;
   lineas = cin.get();
   while(lineas!='#') {
      Ptexto[*Pcont]=lineas;
      *Pcont+=1;
      lineas = cin.get();
   }
   for(int j=0; j<*Pcont; j++) {
      if(Ptexto[j]=='\n') {
         Pfin_linea[*Psalto]=j+1;//ignorar el "\n"
         *Psalto+=1;
      }
   }
}
void GET_PALABRA(char* Ppalabra, int* Pcont, bool* Perror_clave)
{
   //INTRODUCCION DE LA PALABRA
   char lineas = cin.get();
   while(lineas!='#') {
      Ppalabra[*Pcont]=lineas;
      *Pcont+=1;
      lineas = cin.get();
   }
   for(int i=0; i<*Pcont; i++) {
      if(Ppalabra[i]=='\n') {
         *Perror_clave = true;
         cout << "Error de busqueda tipo: Clave Multilinea";
      }
   }
}
void BUSCADOR(char* texto, int tam_util, char* palabra, int tam_palabra, int* index, int* n_index)
{
   int n_linea = 1;
   bool coincidir;
   for(int leer = 0; leer < tam_util; leer++) {
      if(texto[leer]=='\n') {
         n_linea++;
      }
      coincidir = true;
      for(int comprobar = 0; comprobar <= tam_palabra && coincidir; comprobar++) {
         if(comprobar == tam_palabra) {
            index[*n_index]=n_linea;
            *n_index+=1; //variable que maneja la posición en array index
         }
         //Comprobamos en mayusculas para ignorar la diferencia
         if(toupper(texto[leer + comprobar])!=toupper(palabra[comprobar])) {
            coincidir = false;
         }
      }
   }
}
void PRINT_RESULTS(char* Ptexto, int* Pindex, int* Pn_index, int* Pfin_linea)
{
   for(int i = 0; i<*Pn_index; i++) {
      cout << "\n" << Pindex[i] << ":";
      for(int j=Pfin_linea[Pindex[i]-1]; j < Pfin_linea[Pindex[i]] - 1; j++) { //El -1 ignora el "\n"
         cout << Ptexto[j];
      }
   }
}
//END FUNCIONES
