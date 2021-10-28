#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long double cuota, capital, interes, intereses, pendiente, plazo, amortizacion,cont;
    cuota=0;
    pendiente=0;
    cont=0;
    cout << "Introduzca el valor del prestamo, del interes mensual y el plazo: " << endl;
    cin >> capital >> interes >> plazo;

    plazo*=12;
    pendiente = capital;
    interes/=12;
    cuota=(capital*interes)/(100*(1-pow(1+interes/100,-plazo)));
    cout << "Cuota fija a pagar: " << cuota << endl;

    while (pendiente>cuota) {
        intereses=pendiente*(interes/100);
        amortizacion = cuota - intereses;
        if (cont==12) {
            cout << "Interes acumulado: " << intereses << " amortizacion pagada: " << amortizacion << endl;
        }
        if (cont>=12) {
            cont=0;
        }

        cont++;
        pendiente -= amortizacion;
        capital -= cuota;
    }

    cout << "Valor de la pendiente " << pendiente << endl;
}
