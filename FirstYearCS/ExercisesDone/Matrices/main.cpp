#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
   int a,suma=0;
   srand(time(NULL));
   vector<vector<int>> matriz3x3(3,vector<int>(3,0));
   for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
         a = (rand()*1.0/RAND_MAX)*10;
         matriz3x3[i][j]=a;
         if(i==j){
            suma+=matriz3x3[i][j];
            cout << a << " ";
         }
      }
   }
   cout << "\n" << suma;

}
