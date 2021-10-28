#include <iostream>

using namespace std;

int main()
{
    double conversion, limite;
    cout << "Cuantos euros vale un dolar " << endl;
    cin >> conversion;

    cout << "Cual es el limite de cambio " << endl;
    cin >> limite;

    for (int i=1;i<limite;i++){
        cout << i << " = " << conversion*i << endl;
    }
}
