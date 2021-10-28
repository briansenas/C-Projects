#include <iostream>
#include <bintree.h>
#include <string>
#include <stack>

using namespace std;

template<typename T>
bool same(bintree<T> &arb1, bintree<T> &arb2) {
    if (arb1.root().null() && arb2.root().null())
        return true;
    else if (arb1.root().null() || arb2.root().null())
        return false;
    else {
        bool li, ri;
        bintree<T> izqd, dcha, izqd2, dcha2;
        arb1.prune_left(arb1.root(), izqd);
        arb2.prune_left(arb2.root(), izqd2);
        li = same(izqd, izqd2);
        arb1.prune_right(arb1.root(), dcha);
        arb2.prune_right(arb2.root(), dcha2);
        ri = same(dcha, dcha2);
        if (li && ri) {
            return *(arb1.root()) == *(arb2.root());
        }
        else
            return false;
    }
}

template<typename T>
bool similares(const bintree<T> &arb1, const bintree<T> &arb2) {
    if (!arb1.root().null() && !arb2.root().null()) {
        bintree<T> temp = arb1;
        bintree<T> temp2 = arb2;
        return same(temp, temp2);
    } else {
        return false;
    }
}

bintree<int> crear_arbol() {
    bintree<int> A(7);
    bintree<int>::node n;

    A.insert_left(A.root(), 1);
    A.insert_right(A.root(), 9);
    n = A.root().left();
    A.insert_left(n, 6);
    A.insert_right(n, 8);

    n = n.right();
    A.insert_right(n, 4);

    n = A.root().right();
    A.insert_left(n, 5);

    return A;
}

bintree<int> crear_arbol1() {
    bintree<int> A(7);
    bintree<int>::node n;

    A.insert_left(A.root(), 1);
    A.insert_right(A.root(), 9);
    n = A.root().left();
    A.insert_left(n, 6);
    A.insert_right(n, 8);

    n = n.right();
    A.insert_right(n, 4);

    n = A.root().right();
    A.insert_left(n, 3);

    return A;
}

int main() {
    bintree<int> A = crear_arbol();
    bintree<int> B = crear_arbol1();
    cout << "Los arboles " << (similares(A, B) ? " son " : " NO son ") << "similares " << endl;
    return 0;
}
