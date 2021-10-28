#include <iostream>
#include <cmath>

using namespace std;
//We shall develop the function before or declare it and then develop it (WE use long because of its size);
long long Factorial(int num)
{
    long long res = 1;
    for (int i=1; i<=num; i++) {
        res*=i;
    }
    //return the value calculated;
    return res;
}

int main()
{
    //declare the variables necessary to run the program;
    int a,b,c;
    long result;
    cout << "Tell what values you are using " << endl;
    cin >> a >> b;
    cout << "Calculating... " << endl;
    c = a-b;
    result=Factorial(a)/(Factorial(b)*Factorial(c));
    cout << "El factorial de A es : " << Factorial(a) << endl;
    cout << "El factorial de B es : " << Factorial(b) << endl;
    cout << "El factorial de A-B es : " << Factorial(c) << endl;
    cout << "Calculating... " << endl;
    cout << "Luego el resultado de la combinatoria es: " << result << endl;
}
