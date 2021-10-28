#include <iostream>
#include <bintree.h>
#include <queue>

using namespace std;

template<typename T>
bool RecursiveCheck(bintree<T> &arb){
    if(arb.root().null())
        return true;
    else{
        bintree<T> izqd, dcha;
        arb.prune_left(arb.root(),izqd);
        arb.prune_right(arb.root(),dcha);
        bool li = RecursiveCheck(izqd);
        bool ri = RecursiveCheck(dcha);
        if(izqd.empty() && !dcha.empty())
            return false;
        else if(li && ri)
            return true;
    }
}

template<typename T>
bool completo(const bintree<T> &arb) {
    if (!arb.root().null()) {
         bintree<T> temp = arb;
         return RecursiveCheck(temp);
    } else
        return true;
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

int main() {
    bintree<int> A = crear_arbol();
    for (bintree<int>::preorder_iterator it = A.begin_preorder(); it != A.end_preorder(); ++it)
        cout << *it << " ";
    cout << endl;
    cout << completo(A) << endl;
    cout << "El árbol " << (completo(A) ? "es ": "no es ") << "completo" << endl;
    return 0;
}
