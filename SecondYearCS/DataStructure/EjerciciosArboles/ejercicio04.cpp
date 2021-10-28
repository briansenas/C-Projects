#include <stack>
#include <cmath>
#include <iostream>
#include <bintree.h>

using namespace std;

template<typename t>
ostream& operator <<(ostream &out, const bintree<t> &arb){
    typename bintree<t>::const_inorder_iterator it = arb.begin_inorder();
    for(; it != arb.end_inorder(); ++it)
        out << *it << " ";
    return out;
}

template<typename T>
void reflexion(bintree<T> &arb) {
    if (arb.root().null()){
        return;
    }
    else {
        bintree<T> izqd, dcha, temp; //Iniciamos variables
        //Lado izquierdo primero:
        arb.prune_left(arb.root(), izqd);
        arb.prune_right(arb.root(), dcha);
        reflexion(izqd);
        reflexion(dcha);
        arb.insert_left(arb.root(),dcha);
        arb.insert_right(arb.root(),izqd);
    }
}

bintree<int> crear_arbol() {
    bintree<int> A(7);
    bintree<int>::node n;

    A.insert_left(A.root(), 1);
    A.insert_right(A.root(), 9);

    n=A.root().left();
    A.insert_left(n,5);

    return A;
}

int main() {
    bintree<int> A = crear_arbol();
    for (bintree<int>::inorder_iterator it = A.begin_inorder(); it != A.end_inorder(); ++it)
        cout << *it << " ";
    cout << endl;
    reflexion<int>(A);
    for (bintree<int>::inorder_iterator it = A.begin_inorder(); it != A.end_inorder(); ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}
