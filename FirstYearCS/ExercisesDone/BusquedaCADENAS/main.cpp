#include <iostream>

using namespace std;

int main()
{
   //Condiciones
   bool seguir = true;
   bool error_clave = false;
   //VARIABLES
   int cont = 0, i = 1;
   const int TAM = 500;
   char texto[TAM];
   char palabra[TAM];
   //Almacenan en que linea esta la palabra y la longitud de cada linea respectivamente.
   int index[TAM] = {0}, fin_linea[TAM];
   char lineas;
   int tam_util;

   //INTRODUCCION DEL TEXTO
   fin_linea[0]=0;
   lineas = cin.get();
   while(lineas!='#') {
      texto[cont]=lineas;
      cont++;
      lineas = cin.get();
   }
   for(int j=0; j<cont; j++) {
      if(texto[j]=='\n') {
         fin_linea[i]=j;
         i++;
      }
   }
   //Error al introducir el texto
   if(cont==0) {
      seguir=false;
      cout << "No es posible realizar la busqueda, texto vacio " << endl;
   }
   tam_util=cont; //Guardamos el tamano util del vector;

   if(seguir) {

      //INTRODUCCION DE LA PALABRA
      cont = 0; //contador de lineas
      lineas = cin.get();
      while(lineas!='#') {
         palabra[cont]=lineas;
         cont++;
         lineas = cin.get();
         //Error, clave multilinea
         if(lineas=='\n') {
            error_clave = true;
            cout << "Error de busqueda: clave multilinea";
         }
      }

      if(!error_clave) {

         int tam_palabra = cont; //Guardamos el tamano de la palabra

         cout << "El tamano del texto es " << cont << " letras" << endl;
         cout << "Tiene un total de " << i << " lineas" << endl;

         cout << "El tamano de palabra es " <<tam_palabra << endl;
         cout << "Vamos a buscar la palabra: ";
         for(int j = 0; j<cont; j++) {
            cout << palabra[j];
         }
         //BUSCADOR DE LA PALABRA
         int n_linea = 1, n_index = 0;
         bool coincidir;
         for(int leer = 0; leer < tam_util; leer++) {
            if(texto[leer]=='\n') {
               n_linea++;
            }
            coincidir = true;
            for(int comprobar = 0; comprobar < tam_palabra && coincidir; comprobar++) {
               if(
                  comprobar == tam_palabra-1) {
                  index[n_index]=n_linea;
                  n_index++; //variable que maneja la posición en array index
               }
               //Comprobamos en mayusculas para ignorar la diferencia
               if(toupper(texto[leer + comprobar])!=toupper(palabra[comprobar])) {
                  coincidir = false;
               }
            }
         }
         //IMPRIMIMOS LAS SOLUCIONES
         for(int i = 0; i<n_index; i++) {
            cout << "\n" << index[i] << ":";
            for(int j=fin_linea[index[i]-1]; j < fin_linea[index[i]]; j++) {
               cout << texto[j];
            }
         }
      }
   }
   return 0;
}
