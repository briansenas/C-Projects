#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    int maxi,mini,guess,num,old_guess;
    cout << "introduce un rango pringao\n";
    cin >> mini >> maxi;
    guess = (rand() % (maxi-mini))+mini;
    old_guess = guess;
    cout << "introduce un numero q adivine la maquina bro\n";
    cin >> num;
    if (num < mini || num>maxi){
        cout << "pillin, el numero no esta en el rango";
        return 0;
    }
        for(int cont=1;num!=guess;cont++){
        guess = old_guess;
        if (num < guess){
                guess -= cont;
                cout << guess << " es mayor que " << num << endl;
        }
        else{
            guess += cont;
            cout << guess << " es menor que " << num << endl;
        }
    }
}
