#include <iostream>
#include <cmath>

using namespace std;

int Numero_feliz(int numero); // numero feliz a mi manera
int Numero_feliz2(int num); // numero feliz optimizado a manera professor
int Leer_valor();
int Rango_happy(int minimo, int maximo);

int main()
{
    int valor_A, valor_B;
    valor_A = Leer_valor();
    valor_B = Leer_valor();
    if(valor_A > valor_B ){
        cout << "Numeros desordenados, intercambiando ... " << endl;
        int temp = valor_B;
        valor_B = valor_A;
        valor_A = temp;
    }

    cout << Rango_happy(valor_A,valor_B);

}

int Leer_valor(){
    int valor;

    cout << "Introduzca un numero positivo ";
    cin >> valor;
    if(valor<0){
        cout << "Error, introduzca un valor mayor que cero" << endl;
        Leer_valor();
    }
    if(valor>0){
        return valor;
    }

}

int Numero_feliz1(int num)
{
    bool feliz = false;
    int back_upnum, num_cifras,cociente,suma;
    while (num>9){
        num_cifras=1;suma=0;

        back_upnum = num;
        while (back_upnum>=10) {
            back_upnum = back_upnum/10;
            num_cifras++;
        }

        back_upnum = num;
        for (int i=1; i<=num_cifras; i++) {
            cociente = back_upnum / pow(10,num_cifras-i);
            back_upnum = back_upnum % (int) ceil (pow(10,num_cifras-i ));
            suma+= cociente*cociente;
        }

        num = suma;
    }
    if(suma == 1 || suma == 7){
        feliz = true;
    }
    return feliz;
}
int Numero_feliz2(int num){
    int suma, cifras;
    bool feliz = false;
    suma = 0;
    while (num>0){
        cifras = num % 10;
        num = num/10;
        suma = suma + cifras*cifras;
    }
    cout << suma << " ";
    if (suma>9){
        feliz=Numero_feliz2(suma);
    }
    if(suma == 1 || suma == 7){
        feliz=true;
    }
    return feliz;

}


int Rango_happy(int minimo, int maximo){
    int cont=0;
    for(int i=minimo;i <= maximo; i++){
        bool feliz = false;
        feliz = Numero_feliz1(i);
        if (feliz){
            cout << i << " ";
            cont++;
        }
    }
    cout << "\nNumero de felices: " << cont << endl;
    return 0;
}
