#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int numero;

    cout << "Introduzca un numero " << endl;
    cin >> numero;

    while ( (numero%3=1) && ( (numero<0) || (numero%2==1) )){
        cout << "Introduzca un numero " << endl;
        cin >> numero;
    }


}


