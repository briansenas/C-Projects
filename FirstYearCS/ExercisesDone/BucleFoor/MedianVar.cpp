#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double limite, median, var, suma;
    median = 0; var = 0; suma = 0;
    cout << "Dime el numero de iteraciones: " << endl;
    cin >> limite;

    for(int i=1; i<limite; i++){
        suma = suma + i;
        median = suma/i;
        var = pow(i,2)/i - pow(median,2);
    }
    cout << "The median is " << median << endl;
    cout << "The var is " << var << endl;

}
