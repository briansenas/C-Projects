#include <iostream>
#include "pila_max.h"
using namespace std;

int main() {

    Pila_max<float> vec;
    vec.poner(2.3);
    vec.poner(7.8);
    vec.poner(6);
    vec.poner(20);
    vec.poner(9.7);
    vec.poner(11);
    vec.poner(17);

    vec.clean();

}