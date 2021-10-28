#include <iostream>

using namespace std;

int main()
{
    int num, suma;
    num = 1;
    while (num>0){
        suma = 0;
        cout << "Try your luck" << endl;
        cin >> num;

        for(int i=1;i<=num;i++){
            if (num%i==0){
                if(i!=num){
                    suma = suma + i;
                }
            }
        }
        if(suma == num){
                cout << "Tienes un numero perfecto" << endl;
            }

    }
}
