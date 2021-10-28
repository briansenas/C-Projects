#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num, num_cifras, back_upnum, suma, a;
    suma = 0;
    cout << "Try your luck with the narcisist numbers " << endl;
    num = 1;
    num_cifras=1;
    while (num>0){
        cout << "Introduzca un valor mayor que 0 " << endl;
        cin >> num;

        back_upnum = num;
        while (back_upnum>=10){
            back_upnum = back_upnum/10;
            num_cifras++;
        }
        back_upnum = num;
        for (int i=1; i<=num_cifras;i++){
            a = back_upnum / pow(10,num_cifras-i);
            back_upnum = back_upnum % (int) ceil (pow(10,num_cifras-i ));
            suma = suma + ceil(pow(a,num_cifras));
        }
        if(suma==num){
            cout << "Tienes un numero narcisista " << endl;
        }
    }
}
