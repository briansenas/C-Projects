#include <iostream>

using namespace std;

int main()
{
    cout << "Juegos Palillos" << endl;
    int palitos, jugador, maquina;

    cout << "Con cuantos palillos jugamos ";
    cin >> palitos;
    if(palitos%2!=0){
        maquina = 1;
        palitos-=maquina;
        cout << "He quitado: " << maquina << " quedan " << palitos << endl;
    }
    else {
        cout << "Me siento generoso, empiezas tu vengaaa: " << endl;
    }

    while(palitos>0) {
        cout << "Cuantos palitos quitas tu? ";
        cin >> jugador;
        if(jugador>=4){
            cout << "Error, no hagas trampas pringao....GAMEOVER" << endl;
            return 0;
        }
        palitos-=jugador;
        cout << "Has quitado " << jugador << " palitos ahora quedan " << palitos << endl;
        if(palitos<4){
            maquina=palitos;
        }else{
            maquina=4-jugador;
        }
        palitos-=maquina;
        cout << "He quitado " << maquina << " quedan " << palitos << endl;
    }
    cout << "Lo siento pero te he ganado... como siempre :) " << endl;
}
