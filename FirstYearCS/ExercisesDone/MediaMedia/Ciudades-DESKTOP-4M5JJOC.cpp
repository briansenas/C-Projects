#include <iostream>

using namespace std;

int main()
{
    double j, temp, suma, ciudades, median,median_max, cont;
    cout << "Introduzca el numero de ciudadaes " << endl;
    cin >> ciudades;

    suma = 0; median = 0; median_max = 0; cont = 0;

    for(int i=1; i<=ciudades;i++){
            temp = 0;
            cont = 0;
            suma = 0;
        while(temp!=-100){
            cin >> temp;
            if(temp > -100){
                suma = suma + temp;
                median = suma/++cont;
            }
            if (median > median_max){
                median_max = median;
                j = i;
            }
        }
    }
    cout << "Mayor temperatura media: " << median_max << endl;
    cout << "Ciudad " << j << endl;
}
