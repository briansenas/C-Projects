#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double limite, median, var, suma, suma2, valor;
    median = 0; var = 0; suma = 0; suma2 = 0;
    cout << "Dime el numero de iteraciones: " << endl;
    cin >> limite;

    for(int i=0; i<limite; i++){
        cout << "Dime los valores " << endl;
        cin >> valor;
        suma = suma + valor;
        median = suma/limite;
        suma2 = suma2 + pow(valor,2);
        var = suma2/limite - pow(median,2);
    }
    cout << "The median is " << median << endl;
    cout << "The var is " << var << endl;

}
