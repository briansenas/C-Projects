#include <iostream>

using namespace std;

int main()
{
    cout << "Introduca una secuencia de numeros: " << endl;
    int dato = 1;
    int i=0, j=0;

    while (dato!=0){
        cin >> dato;
        if (dato>0){
            i++; //contador de positivos
        }
        if (dato<0){
            j++; //contador de negativos
        }

    }
    cout << "La cantidad de positivos es: " << i << endl;
    cout << "La cantidad de negativos es: " << j << endl;
}
