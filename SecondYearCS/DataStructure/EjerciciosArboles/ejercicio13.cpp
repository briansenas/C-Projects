#include <iostream>
#include <bintree.h>
using namespace std;

template<typename T>
void find(typename bintree<T>::node root, int level, double &maxDepth){
    if( !root.null() ){
        find<T>(root.left(), ++level, maxDepth); //Empezamos mirando el lado izquierdo;
        if(maxDepth < level){
            maxDepth = level-1;
        }
        find<T>(root.right(), level, maxDepth);
    }
}

template<typename T>
void intermedio(typename bintree<T>::node root, double&res){
    if(root.null()){
        return;
    }else{
        double maxDepth = 0;
        find<T>(root.left(),0,maxDepth);
        res+=maxDepth;
        maxDepth = 0;
        find<T>(root.right(),0,maxDepth);
        res+=maxDepth;
        intermedio<T>(root.left(),res);
        intermedio<T>(root.right(),res);
    }
}

template<typename T>
double densidad(const bintree<T> &arb){
    if(arb.root().null())
        return 0;
    else{
        double res = 0,Height = 0;
        typename bintree<T>::node root = arb.root();
        find<T>(root,0,Height);
        cout << "HEIGHT: " << Height << endl;
        intermedio<T>(root,res);
        res += Height;
        cout << "SUM_OF_DENSITY: " << res << endl;
        return res/Height;
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

int main() {
    bintree<int> A = crear_arbol();
    for (bintree<int>::preorder_iterator it = A.begin_preorder(); it!=A.end_preorder(); ++it)
        cout << *it << " ";
    cout << endl;

    double result = densidad(A);
    cout << result << endl;
    return 0;
}
