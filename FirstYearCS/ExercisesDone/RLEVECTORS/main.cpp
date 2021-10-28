#include <iostream>
#include <vector>

using namespace std;

void Bubble_sort(vector<int> vec, int cont);

int main()
{
   int read, cont=0;
   vector<int> vec;
   cout << "Start inputing the code ";
   cin >> read;
   while(read>0) {
      vec.push_back(read);
      cont++;
      cin >> read;
   }
   cout << cont << endl;
   Bubble_sort(vec,cont);

}
void Bubble_sort(vector<int> vec, int cont)
{
   int intercambia;
   for (int izda = 0; izda < cont; izda++) {
      for (int i = cont-1 ; i > izda ; i--) {
         if (vec[i] < vec[i-1]) {
            intercambia = vec[i];
            vec[i] = vec[i-1];
            vec[i-1] = intercambia;
         }
      }
   }
   for(int i=0; i<cont; i++){
      cout << vec.at(i) << " ";
   }

}
