#include <iostream>

using namespace std;

int main()
{
    int input;
    input = 1;
    while(input%3==0 || (input>0 && input%2==1)){
        cin >> input;
    }
}
