#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
   vector<int> vec;
   double media=0, var=0, desviacion=0, num;

   cout << "BIENVENIDO AL CALCULO DE MEDIA/VAR/DESVIATION" << endl;
   cout << "---------------------------------------------" << endl;
   cout << endl;

   cout << "Ve introduciendo los valores, para finalizar introduzca 0 ";
   cin >> num;
   while(num!=0){
      vec.push_back(num);
      cin >> num;
   }

   for(int i=0; i<vec.size();i++){
      media+=vec.at(i);
   }
   media/=vec.size();
   cout << media << endl;

   for(int i=0; i<vec.size();i++){
      desviacion+=fabs(vec.at(i)-media);
   }
   desviacion/=vec.size();
   cout << desviacion << endl;

   for(int i=0; i<vec.size();i++){
      var+=(vec.at(i)-media)*(vec.at(i)-media);
   }
   var/=vec.size();
   cout << var << endl;
}
