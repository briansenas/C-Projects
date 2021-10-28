#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cctype>

using namespace std;

int main()
{
    int ext_inf,ext_sup,guess,number;
    char tamano;
    srand(time(NULL));
    cout << "Introduzca el intervalo con cual trabajamos ";
    cin >> ext_inf >> ext_sup;

    cout << "Ahora introduzca su numero ";
    cin >> number;

    guess = ext_inf + rand()%(ext_sup+1-ext_inf);
    cout << guess << endl;

    while(guess!=number){
        cout << "Es su numero el numero " << guess << endl;
        cout << "Si el numero es mayor introduca B, si es menor cualquier otra mierda ";
        cin >> tamano;

        if(toupper(tamano)=='B'){
            ext_inf = guess;
        } else {
            ext_sup = guess;
        }

        guess = ext_inf + rand()%(ext_sup+1-ext_inf);
    }
    cout << "Su numero es el " << guess << " Verdad? " << endl;
}
