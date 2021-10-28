#include <iostream>
#include <cmath>

using namespace std;

int factorial(int a){
    int i;
    int res = 1;
    for (i=1; i<a; i++){
        res*=i
    }
    return res;
}

int main(){
        int prueba;
        prueba=factorial(4);
        echo << "Prueba " << prueba << endl;

}
