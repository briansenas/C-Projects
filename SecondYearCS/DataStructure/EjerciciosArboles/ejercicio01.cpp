#include <iostream>
#include <bintree.h>
using namespace std;

template<typename T>
void find(typename bintree<T>::node root, int level, int &maxDepth, typename bintree<T>::node &res){
    if( !root.null() ){
        find<T>(root.left(), ++level, maxDepth, res); //Empezamos mirando el lado izquierdo;
        if(maxDepth < level){
            res = root;
            maxDepth = level;
        }
        find<T>(root.right(), level, maxDepth, res);
    }
}

template<typename T>
typename bintree<T>::node mas_profunda(const bintree<T> &arb){
    int maxDepth = -1; //Profundidad final
    typename bintree<T>::node res;
    typename bintree<T>::node root = arb.root();
    find<T>(root,0,maxDepth,res);
    return res;
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
    for (bintree<int>::preorder_iterator it = A.begin_preorder(); it!=A.end_preorder(); ++it)
        cout << *it << " ";
    cout << endl;

    bintree<int>::node result = mas_profunda(A);
    cout << *result << endl;
    return 0;
}
