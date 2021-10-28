#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int get_cifras(int num);
    int feliz, test;
    cout << "Introduzca el numero a verificar " << endl;
    cin >> feliz;
    test = feliz;
    while (test!=1){
        test = get_cifras(test);
        cout << test << endl;
    }
    cout << "Tienes un numero feliz " << endl;
}

int get_cifras(int num)
{
    int back_upnum, num_cifras,a,suma;
    num_cifras=1;suma=0;
    back_upnum = num;
    while (back_upnum>=10) {
        back_upnum = back_upnum/10;
        num_cifras++;
    }
    back_upnum = num;
    for (int i=1; i<=num_cifras; i++) {
        a = back_upnum / pow(10,num_cifras-i);
        back_upnum = back_upnum % (int) ceil (pow(10,num_cifras-i ));
        suma=suma+pow(a,2);
    }
    return suma;
}
