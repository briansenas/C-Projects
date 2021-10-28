#include <iostream>

using namespace std;

int main()
{
    int data, old_data,cont;
    cont=1; data=0; old_data=data;
    cout << "Introduzca la secuencia de numeros: " << endl;
    while(data>=0){
        cin >> data;
        if(old_data==data){
            cont++;
        } if ((old_data!=data)&&(old_data!=0)) {
            cout << cont << " " << old_data << " ";
            cont = 1;
        }
        old_data=data;
    }
}
