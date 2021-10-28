#include <iostream>
#include <bintree.h>
#include <list>

using namespace std;

template<typename T>
void intermedio(typename bintree<T>::node root, T a, T b, list<T> &res) {
    if (root.null()) {
        return;
    }
    else {
        intermedio<T>(root.left(), a, b, res);
        if (*root >= a && *root<=b) {
            res.push_back(*root);
        }
        intermedio<T>(root.right(), a, b, res);
    }
}

template<typename T>
list<T> intervalo(const bintree<T> &arb, const T &a, const T &b) {
    if (arb.root().null())
        return list<T>();
    else {
        list<T> res;
        intermedio<T>(arb.root(), ((a <= b) ? a : b), ((a >= b) ? a : b), res);
        res.sort();
        return res;
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
    A.insert_left(n, 4);

    n = A.root().right();
    A.insert_left(n, 5);

    return A;
}

int main() {
    bintree<int> A = crear_arbol();
    for (bintree<int>::preorder_iterator it = A.begin_preorder(); it != A.end_preorder(); ++it)
        cout << *it << " ";
    cout << endl;

    list<int> res;
    res = intervalo(A, 1, 7);
    list<int>::iterator it = res.begin();
    for (; it != res.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
