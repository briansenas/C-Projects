#include <iostream>

using namespace std;

int maximo(int a,int b = 0,int c = 0, int d = 0)
{
    if (a>b && a>c && a>d) {
        return a;
    }
    if (b>c && b>d) {
        return b;
    }
    if(c>a && c>d) {
        return c;
    }
    if(d>c) {
        return d;
    }

    return 0;
}


int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << "El valor maximo es: " << maximo(a,b,c,d) << endl;
}
