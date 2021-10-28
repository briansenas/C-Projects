#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main()
{
   char play, change;

   do{
   srand(time(NULL));
   const int TAM=30;
   int lista[TAM],number,guess;

   cout << "Estamos generando la lista de numeros aleatorios...";

   do{
   cout << "\nQue numero quieres que busque?[0-100] ";
   cin >> guess;
   if(guess < 0 || guess > 100){
      cout << "Error, introduzca un valor valido";
   }
   }while(guess<0 || guess>100);

   do{
   cout << "Estamos generando la lista de numeros aleatorios...\n";

   for(int i=0; i<TAM; i++){
      number=(rand()%100);
      lista[i]=number;
   }

   bool encontrado = false;
   int index;

   cout << "Buscando...\n";
   for(int i=0; i<TAM && !encontrado ; i++){
      if (lista[i]==guess){
         encontrado=true;
         index = i;
      }
   }

   if (encontrado){
      cout << "Lo hemos encontrado en el index " << index << endl;
      cout << "Su valor era " << guess << endl;
   }else{
      cout << "El numero no se encuentra en el vector " << endl;
   }

   cout << "Si quieres verificalo tu mismo: " << endl;
   for(int i=0; i<TAM; i++){
      cout << lista[i] << " ";
   }

   cout << "\nQuieres volver a intentarlo? ";
   cin >> play;
   if(toupper(play)=='Y'){
      cout << "Quieres cambiar el numero? ";
      cin >> change;
   }
   }while (toupper(play)=='Y' && toupper(change)=='N');
   }while(toupper(play)=='Y');
   return 0;
}
