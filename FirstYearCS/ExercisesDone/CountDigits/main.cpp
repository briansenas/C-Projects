#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int get_cifras(int num);
    int sumar_digitos(int num, int counter);
    int num,counter,resultado;
    cout << "Dime cual es el numero " << endl;
    cin >> num;

    counter = get_cifras(num);
    resultado = sumar_digitos(num,counter);
    cout << resultado << " Suma de " << counter << " digitos" << endl;
}
/* La función get_cifras lo que realiza es el calculo del numero de cifras
que posee un numero n que se le haya sido asignado */

int get_cifras(int num){
    int backup_num=num;
    int counter = 1;
    int suma=0;
    while (backup_num>10){
        backup_num/=10;
        counter++;
    }
    return counter;
}

/* La funcion sumar_digitos lo que hace es que una vez,
que sepamos el numero de digitos que posee un numero,
pues entonces le procedemos a calcular el valor de la suma
de sus digitos */

int sumar_digitos(int num,int counter){
    int backup_num = num;
    int index, valor, suma;
    suma = 0;
    for(int i=1; i<=counter;i++){
        valor = backup_num / (int) pow(10,counter-i);
        suma += valor;
        index = backup_num % (int) ceil(pow(10,counter-i));
        backup_num = index;
    }
    return suma;
}
