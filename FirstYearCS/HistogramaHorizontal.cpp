#include <iostream>
#include <ctime>
#include <cstdlib>
#define VAL 100000
using namespace std;

void Ordenar(int arr[], int ord[]);
void Histograma(int ord[]);

int main(void){
    srand(time(NULL));
    int arra[VAL],ord[VAL];
    clock_t t1,t2;
    double numsecs;
    for (int i = 0; i<VAL; i++){
        arra[i] = rand();
        ord[i] = 0;
    }
    Ordenar(arra,ord);
    t1 = clock();
    Ordenar(arra,ord);
    t2 = clock();
    numsecs = (double)(t2-t1)/CLOCKS_PER_SEC;
    cout << "TIEMPO" << numsecs;
    Histograma(ord);
    return 0;
}
void Ordenar(int arr[], int ord[]){
    int pos;
    for (int i= 0; i<VAL; i++){
        pos = 0;
        for (int j = 0; j< 10; j++){
            if (arr[i] < arr[j]){
                pos+=1;
            }
        }
        while (ord[pos] !=0){
            pos+=1;
        }
        ord[pos] = arr[i];
    }
    return;
}
void Histograma(int ord[]){
    //(ord[1],0);
    cout << "Patata";
    return;
}
