#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double tamano;
    int filas,columnas,extra;
    cout << "Introduce el numero magico " << endl;
    cin >> tamano;
    //piramide
    for(filas=0; filas<tamano; filas++) {
        for(columnas=0; columnas<filas; columnas++) {
            cout << "*";
        }
        cout << "*" << endl;
    }

    cout << " " << endl; //para limpiar la pantalla;

    //Cuadrado:
    for(filas=0; filas<tamano; filas++) {
        if (filas==0 || filas==tamano-1) {
            for(columnas=0; columnas<tamano-2; columnas++) {
                cout << "*"; //para hacer la tapadera y la base
            }//fin del for
        }

        cout << "*"; //dibujar el lateral izquierdo
        if (filas!=0 && filas!=tamano-1) { //He tenido que poner el if porque por algun motivo no funcionaba sin.
            for(extra=0; extra<tamano-2; extra++) { //espacio blanco dentro.
                cout << " ";
            }
        }

        cout << "*" << endl;

    }
    //limpiar la pnatalla.
    cout << " " << endl;

    //rombo
    double espacio_blanco = tamano/2;
    double mitad = tamano/2;
    int rombo = 1;

    for(filas=1; filas<=ceil(mitad); filas++) {
        for(columnas=1; columnas<ceil(espacio_blanco); columnas++) {
            cout << " ";
        }
        for(columnas=1; columnas<=rombo; columnas++) {
            if (columnas==rombo) {
                cout << "*" << endl;
            } else {
                cout << "*";
            }
        }
        rombo+=2;
        espacio_blanco-=1;
    }

    extra=1;
    rombo-=4;

    for (filas=1; filas<=floor(mitad); filas++) {
        for(columnas=1; columnas<=extra; columnas++) {
            cout << " ";
        }
        for(columnas=1; columnas<=rombo; columnas++) {
            if(columnas==rombo) {
                cout << "*" << endl;
            } else {
                cout << "*";
            }
        }
        extra+=1;
        rombo-=2;
    }

}
