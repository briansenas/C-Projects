#include <stack>
#include <cmath>
#include <iostream>
#include <bintree.h>

using namespace std;

template<typename T>
int altura(const bintree<T> &arb) {
    if(!arb.empty()) {
        stack<typename bintree<T>::node> pila;
        typename bintree<T>::node root = arb.root();
        pila.push(root);
        pila.push(root);
        int height = 0, maxHeight = 0;
        bool izqd = !root.left().null(), dcha = !root.right().null(), last = true;
        while (!pila.empty()) {
            if (izqd) {
                root = root.left();
                pila.push(root);
                height++;
                izqd = !root.left().null();
                dcha = !root.right().null();
            } else if (dcha) {
                root = root.right();
                pila.push(root);
                height++;
                dcha = !root.right().null();
                izqd = !root.left().null();
            } else {
                pila.pop(); //Valor que nos hemos atascado
                root = pila.top(); //Reintentar;
                pila.pop(); //No volver a un nodo ya visitado.
                dcha = !root.right().null();
                if (height >= maxHeight) {
                    maxHeight = height;
                    height--;
                }
            }
        }

        return maxHeight;
    }else
        return 0;
}

bintree<int> crear_arbol() {
    bintree<int> A(7);
    bintree<int>::node n;

    A.insert_left(A.root(), 1);
    A.insert_right(A.root(), 9);
    n = A.root().left();
    A.insert_left(n,2);
    n = n.left();
    A.insert_left(n,3);
    A.insert_right(n.left(),4);

    return A;
}

int main() {
    bintree<int> A = crear_arbol();
    cout << "La altura del arbol es: " << altura(A) << endl;
    return 0;
}
