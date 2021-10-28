#include <iostream>
#include <string>

using namespace std;

int main()
{
    int limite;
    cout << "Introduzca el lado del cuadrado " << endl;
    cin >> limite;
    for(int i=0; i<limite; i++){
        cout << string(limite,'+') << endl;
    }
}
