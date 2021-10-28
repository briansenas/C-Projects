#include <iostream>

using namespace std;

int main()
{
    double n, minimo, maximo,num;
    cout << "Introduzca el N, minimo, maximo" << endl;
    cin >> n >> minimo >> maximo;

    bool run = true;

    for(int i=0;( (i<n)&&(run==true) ); i++){
        cout << "Introduzca el valor " << i << " " << endl;
        cin >> num;
        if((num<minimo)||(num>maximo)){
            cout << "Error de valor " << endl;
            run = false;
        }
    }
    cout << "Los " << n << " valores estan en el intervalo " << endl;
}
