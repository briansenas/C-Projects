#include "diccionario.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  Diccionario<string, string> uno;

  // Comprobar iteradores para diccionario vacío
  assert(uno.begin() == uno.end());

  fstream input_data("data/data.txt", fstream::in);
  input_data >> uno;

  Diccionario<string, string> dos(uno);

  Diccionario<string, string>::Iterator it;
  uno.AddSignificado_Palabra("Sentencia",
      "f. Dicho grave y sucinto que encierra doctrina o moralidad"
      );

  assert(uno.getInfo_Asoc("Sentencia").front() ==
         "f. Frase o dicho que implica un juicio,una enseñanza.");
  assert(uno.getInfo_Asoc("Sentencia").back() ==
         "f. Dicho grave y sucinto que encierra doctrina o moralidad");

  assert(uno.getInfo_Asoc("Sentencia").front() ==
         dos.getInfo_Asoc("Sentencia").front());
  assert(uno.getInfo_Asoc("Sentencia").back() !=
         dos.getInfo_Asoc("Sentencia").back());

  uno = uno;
  assert(uno.getInfo_Asoc("Sentencia").front() ==
         "f. Frase o dicho que implica un juicio,una enseñanza.");

  Diccionario<string, string> tres;
  assert(tres.cbegin() == tres.cend());
  uno = tres;
  assert(uno.begin() == uno.end());
  assert(dos.begin() != dos.end());
  cout << "OK" << endl;


  Diccionario<string,string> quatro;
  input_data.seekg(0,ios::beg);
  input_data >> quatro;
  cout << quatro << endl;
  int num = 1;
  cout << "Ahora vamos a buscar un valor por indice: " << num << endl;
  cout << quatro[num] << endl << endl;

  string clave = "Yllari";
  cout << "Ahora vamos a buscar una información por clave: " << clave << endl;
  cout << quatro[clave] << endl << endl;

  cout << "Tenemos exactamente: " << quatro.numDefiniciones("Compilador") << " definiciones para \"Compilador\"" << endl << endl;
  cout << "Nuestro diccionario incluye las siguientes claves:  " << endl; quatro.ImprimirClaves();
  cout << "\nAhora vamos a probar a borrar la clave \"Sentencia\" " << endl;
  quatro.Erase("Sentencia");
  cout << quatro << endl;

  cout << "Vamos a intentar"
  list<string> hola;
  hola.push_front("HolabUenas");
  quatro.Insertar("Compilador",hola);
  cout << quatro << endl;
 return 0;
}
