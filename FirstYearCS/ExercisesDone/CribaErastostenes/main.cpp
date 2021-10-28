#include <iostream>
#include <vector>

using namespace std;

int main()
{
   vector<int> vec(10000), vec3(10000);
   vector<bool> vec2(10000);
   int num;
   cout << "Cual es el numero? ";
   cin >> num;

   for(int i=1;i<num;i++){
      vec.at(i)=i;
      vec2.at(i)=true;
   }
   cout << "working... " << endl;
   int cont = --num;

   for(int i=2; i<num; i++){
      for(int j=2*i; j<=num; j+=i){
         if(j>=num){continue;}
         if(vec2.at(j)==true){
            cont--;
            vec.at(j)=0;
            vec2.at(j)=false;
         }
      }
   }
   int j=0;
   for(int i=0; i<vec.size();i++){
      if(vec2[i]==true){
         vec3.at(j)=vec.at(i);
         j++;
      }
   }
   for(int i=0; i<cont; i++){
      cout << vec3.at(i) << " ";
   }
}
