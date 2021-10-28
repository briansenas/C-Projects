#include <iostream>

using namespace std;

int main()
{
    double max_subida, min_bajada, subida, bajada, diferencia, maximo, minimo, valor, old_valor;
    valor = 0; maximo = 0; minimo = 0; subida = 0; bajada = 0; diferencia = 0; max_subida = 0; min_bajada = 0;

    while (valor!=-1){

        diferencia = valor - old_valor;
        if ((diferencia > 0)&&(old_valor!=0)){
            subida = diferencia;
            if (subida>max_subida){
                max_subida=subida;
            }
        }
        if ((diferencia < 0)&&(old_valor!=0)){
            bajada = diferencia;
           if(bajada<min_bajada){
                min_bajada=bajada;
           }
        }
        if (valor>maximo){
            maximo=valor;
        }
        minimo=maximo;
        if(valor<minimo){
            minimo=valor;
        }
        old_valor = valor;
        cout << "Introduzca un valor " << endl;
        cin >> valor;
    }
    cout << "El valor maximo es " << maximo << endl;
    cout << "El valor minimo es " << minimo << endl;
    cout << "La subida maxima es " << max_subida << endl;
    cout << "La subida minima es " << min_bajada << endl;
}

