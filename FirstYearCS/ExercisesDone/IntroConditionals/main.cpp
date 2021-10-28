#nclude <iostream>
#include <cctype>

using namespace std;

int main()
{
    char semillas, vasos, frutos;
    int cotiledoneas;
    cout << "Tiene semillas? ";
    cin >> semillas;
    if((toupper(semillas)=='N')){
        cout << "Tiene vasos conductores " << endl;
        cin >> vasos;
        if(toupper(vasos)=='S'){
            cout << "Pteridofitas " << endl;
        }
        else {
            cout << "Briofitas " << endl;
        }
    }
    else{
        cout << "Tiene frutos? ";
        cin >> frutos;
        if(toupper(frutos)=='N'){
            cout << "Gimnospermas " << endl;
        }
        if(toupper(frutos)=='S'){
            cout << "Numero de cotiledoneas? ";
            cin >> cotiledoneas;
            if(cotiledoneas==1){
                cout << "Monocotiledoneas " << endl;
            }
            else {
                cout << "Dicotiledoneas " << endl;
            }
        }
    }

}
