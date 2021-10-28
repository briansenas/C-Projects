#include <iostream>

using namespace std;

void Rellenar_Polinomio(int Tam, int* p);
void Sumar_Polinomio(int size1, int size2, int* p, int* q);
void multiplicar(int* p, int* q, int size1, int size2, int* multipol);
void Potencial(int* p,int size1, int veces, int* potencia, int* multipol);

int main()
{
    int potencia[50]; int multipol[5]={0};
    const int size1 = 2; const int size2 = 5;
    int p[size1];
    Rellenar_Polinomio(size1,p);
    Potencial(p,size1,2,potencia,multipol);
}
void Rellenar_Polinomio(int Tam, int* p){
   for(int i=0; i<Tam; i++){
      cout << "Elemento " << i << ": ";
      cin >> p[i];
   }
   return;
}
void Sumar_Polinomio(int size1, int size2, int* p, int* q){
   const int mayor = max(size1,size2);
   const int menor = min(size1,size2);
   int sumar[mayor];
   int j = menor-1;
   for(int i = mayor; i>=0; i--){
      if(j>=i){
         sumar[i]=p[i]+q[j];
         j-=1;
         cout << sumar[i] << " ";
      }
   }
   return;
}
void multiplicar(int* p, int* q, int size1, int size2, int* multipol){
   for(int i = 0; i<size1;i++){
      for(int j = 0; j<size2;j++){
         multipol[j+i]+=p[i]*q[j];
      }
   }
}
void Potencial(int* p,int size1, int veces, int* potencia, int* multipol){
   for(int i=0; i<size1;i++){
      potencia[i]=p[i];
   }
   for(int i=1;i<veces;i++){
      multiplicar(p,potencia,size1,size1,multipol);
      for(int j=0; j<i*(size1);j++){
         potencia[j]=multipol[j];
      }
   }
   for(int i=0; i<veces*size1-1;i++){
      cout << multipol[i] << "x^" << i << " ";
   }
}
