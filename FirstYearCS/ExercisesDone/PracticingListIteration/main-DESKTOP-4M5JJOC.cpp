#include <iostream>
#include <list>

using namespace std;

int main()
{
    double deuda,resultado;
    resultado = 0;

    cout << "Cuanto tienes que pagar? " << endl;
    cin >> deuda;

    list<double> Solucion = {};
    list<double> Dinero = {5,2,1,0.5,0.2,0.05,0.01};

        for(const double money : Dinero){
            while ((deuda > 0)){
                deuda += -money;
                Solucion.push_back(money);
            }
            if(deuda < 0){
                    deuda += money;
                    Solucion.pop_back();
                }
        }

    for (const double money : Solucion){
        cout << money;
        resultado+=money;
        if (resultado == deuda) {
            cout << " = ";
        }else{
            cout << " + ";
        }

    }
    cout << "El Resultado total es " << resultado << endl;
}

