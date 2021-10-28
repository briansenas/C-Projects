#include <iostream>
#include "../PilaMax/inc/cola.h"

using namespace std;

int main() {
    srand(time(NULL));
    Cola<int> p;
    int i;

    for (i = 0; i < 10; i++)
        p.poner(i);

    p.clean();
    cout << p.num_elementos() << endl;


    Cola<float> q;
    int j;


    for (j = 10; j > 0; j--)
        q.poner(j / 10.0);


    float z = q.frente();
    cout << z << endl;
    q.clean();
    cout << q.num_elementos() << endl;

    for (int i = 0; i < 10; i++) {
        q.poner(rand() % 10 + 1);
    }

    q.clean();

    return 0;
}
