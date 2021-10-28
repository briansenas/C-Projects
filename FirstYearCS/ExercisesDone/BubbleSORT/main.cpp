#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void Rellenar(vector<int>& vec1, int szvec1);
void MostrarVEC(vector<int>& vec1, int szvec1);
void Insertion(vector<int>& vec1, int szvec1);
void Bubble(vector<int>& vec1, int szvec1);
void Selection(vector<int>& vec1, int szvec1);

int main()
{
   int szvec1 = 8;
   vector<int> vec1(szvec1,0);
   cout << "\nINSERTION MODE BITCHES\n" << endl;
   Rellenar(vec1, szvec1);
   MostrarVEC(vec1, szvec1);
   Insertion(vec1, szvec1);
   MostrarVEC(vec1, szvec1);
   cout << "\nSELECTION MODE BITCHES\n" << endl;
   Rellenar(vec1, szvec1);
   MostrarVEC(vec1, szvec1);
   Selection(vec1, szvec1);
   MostrarVEC(vec1, szvec1);
   cout << "\nBUBBLE MODE BITCHES\n" << endl;
   Rellenar(vec1, szvec1);
   MostrarVEC(vec1, szvec1);
   Bubble(vec1, szvec1);
   MostrarVEC(vec1, szvec1);


}
void Rellenar(vector<int>& vec1, int szvec1)
{
   const int VAL = 50;
   int aleatorio;
   srand(time(NULL));
   rand();
   for (int i = 0; i < szvec1; i++) {
      aleatorio = (1.0 * rand() / RAND_MAX)*(VAL);
      vec1[i]=(aleatorio);
   }
}
void MostrarVEC(vector<int>& vec1, int szvec1)
{
   for (int i = 0; i < szvec1; i++)
      cout << vec1[i] << " ";
   cout << endl;
}
void Selection(vector<int>& vec1, int szvec1){
   int minimo, pos_minimo;
   for(int i = 0; i < szvec1-1; i++){
      minimo = vec1.at(i);
      pos_minimo = i;
      for(int j = i+1; j < szvec1; j++){
         if(vec1.at(j)<minimo){
            minimo = vec1.at(j);
            pos_minimo = j;
         }
      }
      vec1.at(pos_minimo) = vec1.at(i);
      vec1.at(i) = minimo;
   }
}
void Bubble(vector<int>& vec1, int szvec1)
{
   int change;
   for (int i = 0; i < szvec1; i++) {
      for (int j = szvec1 - 1; j >= i; j--) {
         if (vec1[i] > vec1[j]) {
            printf("Since %d is bigger than %d we gon change them\n", vec1[i], vec1[j]);
            change = vec1[i];
            vec1[i] = vec1[j];
            vec1[j] = change;
         }
      }
      MostrarVEC(vec1,szvec1);
   }
}
void Insertion(vector<int>& vec1, int szvec1)
{
   int a_desplazar, i;
   for( int izda = 1; izda < szvec1; izda++){
      a_desplazar = vec1.at(izda);

      for(i = izda; i > 0 && a_desplazar < vec1[i-1]; i--){
            vec1[i] = vec1[i-1];
      }
      vec1.at(i) = a_desplazar;
   }
}
