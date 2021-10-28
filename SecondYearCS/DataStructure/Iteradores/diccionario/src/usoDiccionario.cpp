#include <iostream>
#include <fstream>
#include <string>
#include "diccionario.h"

using namespace std;

int main() {
    ifstream input("data/data.txt");
    Diccionario <string, string> diccionario;
    cout << "\n#### Practica 4, Brian Sena #### \n";
    cout << "Leyendo Información del archivo de texto... \n";
    input >> diccionario;

    cout << "Información adquirida: \n";
    cout << diccionario;

    string clave = "Yllari";
    cout << "Buscando por clave: " << clave << endl;
    cout << diccionario[clave] << endl;

    int pos = 0;
    cout << "Buscando por posición en el diccionario: " << pos << endl;
    cout << diccionario[pos] << endl;


    cout << "#### Practica 4, Brian Sena #### \n";
}