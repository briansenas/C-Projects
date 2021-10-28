#include <iostream>
#include <cmath>

using namespace std;

int funcion(int x){
    int whatever = 2*pow(x,3) + 8*pow(x,2) - 5;
    return whatever;
    }

int main()
{
    double a, b, A, B, c, C, Error;
    bool run = true;

    cout << "Indica la precision de los calculos " << endl;
    cin >> Error;

    cout << "Introduzca los intervalos " << endl;
    cin >> a >> b;

    while ( fabs(b - a) > Error || run){
        A = funcion(a);
        B = funcion(b);
        cout << "doing stuff " << endl;
        if (A*B<0){
            c = (a+b)/2;
            C = funcion(c);
            if (A*C<=0){
                b = c;
            }
            if (C*B<0){
                a = c;

            }

        }

    }

    cout << "Solucion es " << (a + b)/2 << endl;
    cout << "El valor maximo es " << (b-a)/2 << endl;

}
