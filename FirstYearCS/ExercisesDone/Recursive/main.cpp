#include <iostream>

using namespace std;

int f(int x){
   if(x>100) return x-10;
   else return f(x+11);
}

int main()
{
    cout << f(0) << endl;
}
