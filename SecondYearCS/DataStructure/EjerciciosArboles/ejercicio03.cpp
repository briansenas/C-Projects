#include <stack>
#include <cmath>
#include <iostream>
#include <bintree.h>
using namespace std;

template<typename T>
int profundidad(typename bintree<T>::node root){
    if(root.parent().null())
        return 0;
    return profundidad<T>(root.parent()) + 1;
}

template<typename T>
typename bintree<T>::node ancestro_comun(typename bintree<T>::node n1, typename bintree<T>::node n2){
    //Sin usar iteradores;
    bool done = false;
    int h1 = profundidad<T>(n1);
    int h2 = profundidad<T>(n2);
    //Como sabemos que el ancestro está a la diferencia de profundidad entre ambos;
    //Podemos asumir que en el WCE -> O(|H2-H1| + 1) -> O(n) -> P.j: Son hojas excluyentes;
    while((!n1.null() && !n2.null())){
        if(n1==n2) {
            break;
        }
       if(!n1.parent().null() && h2 <= h1){
           n1 = n1.parent();
           h1--;
       }
       if(!n2.parent().null() && h1 < h2){
           n2 = n2.parent();
           h2--;
       }
    }
    return n1;
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
    typename bintree<int>::node izqd(A.root().left());
    typename bintree<int>::node dcha(A.root().left().right());
    typename bintree<int>::node padre_comun = ancestro_comun<int>(izqd,dcha);
    cout << "Ancestro comun: " << *padre_comun << endl;
    return 0;
}
