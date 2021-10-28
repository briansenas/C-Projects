#include <iostream>

using namespace std;

int main()
{
    const int TAM=10;
    int v[TAM], indices[TAM];
    int j, minimo;
    minimo = 675000;

    for (int i=0; i < TAM; i++){
            cin >> v[i];
    }

    j=0;
    for(int i=0; i<TAM;i++){
        if(v[i] <= minimo){
            minimo=v[i];
            indices[j]=i;
            j+=1;

        }
    }
    cout << "Los indices con el menor valor son: ";
    for(int i=0; i<j; i++){
        cout << indices[i] << " " ;
    }
    cout << "\n" << "Los valores, respectivamente, son: ";
    for(int i=0; i<j; i++){
        cout << v[indices[i]] << " ";

    }

}
