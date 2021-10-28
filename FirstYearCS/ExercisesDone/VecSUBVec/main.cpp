#include <iostream>

using namespace std;

int main()
{
    const int TAM = 6;
    const int TAMB = 3;
    int vec1[TAM];
    int vec2[TAMB] = {1,2,3};

    for(int i=0; i<TAM; i++){
        cin >> vec1[i];
    }
    int j = 0;
    int index = 0;
    bool ENCONTRADO = false;

    for(int i=0; i<TAM; i++){
        if (vec1[i]==vec2[j]){
                j+=1;
        }
        if ( j == TAMB ) {
            ENCONTRADO = true;
            index = i - j;
        }
        if (vec1[i] != vec2[j-1]){
                j = 0;
        }
}
    if (ENCONTRADO==true) {
        cout << "Hemos encontrado el vector y se encuentra en el index "
        << index << endl;
    }
    else {
        cout << "No hemos encontrado el vector" << endl;
    }
}

