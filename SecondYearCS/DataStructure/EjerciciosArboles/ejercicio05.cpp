#include <stack>
#include <cmath>
#include <iostream>
#include <bintree.h>
#include <map>
#include <queue>

using namespace std;


template<typename t>
ostream& operator <<(ostream &out, bintree<t> &arb){
    typename bintree<t>::inorder_iterator it = arb.begin_inorder();
    for(; it != arb.end_inorder(); ++it)
        out << *it << " ";
    return out;
}

double value(double A,double B, char operand){
    double res;
    switch(operand){
        case '+':
            res = A+B;
            break;
        case '-':
            res = A-B;
            break;
        case '*':
            res = A*B;
            break;
        case '/':
            res = A/B;
            break;
    }
    return res;
}

double toDouble(char A, const map<char,double>& valores){
    double res;
    map<char,double>::const_iterator it = valores.begin();
    for(; it != valores.end(); it++){
        if( A == it->first)
            res = it->second;
    }
    return res;
}

double eval(typename bintree<char>::node root, const map<char,double> &valores){
   if(root.null())
       return 0;
   if(root.left().null() && root.right().null())
       return toDouble(*root,valores);
   double lval = eval(root.left(),valores);
   double rval = eval(root.right(),valores);

   return value(lval,rval,*root);
}

double evaluar(typename bintree<char>::node n, const bintree<char> &arb, const map<char, double> &valores) {
    if (arb.root().null()) {
        return 0;
    } else {
        n = arb.root();
        return eval(n,valores);
    }
}

bintree<char> crear_arbol() {
    bintree<char> A('*');
    bintree<char>::node n;

    A.insert_left(A.root(), '+');
    A.insert_right(A.root(), '+');

    n = A.root().left();
    A.insert_left(n, 'a');
    A.insert_right(n,'b');
    n = A.root().right();
    A.insert_left(n,'c');
    A.insert_right(n,'d');

    return A;
}

int main() {
    bintree<char> A = crear_arbol();
    cout << A << endl;
    typename bintree<char>::node n;
    map<char,double> valores ={
            {'a', 5},
            {'b', 3},
            {'c', 2},
            {'d', 4},
            {'e', 9}
    };
    cout << "Resultado: " << evaluar(n,A,valores) << endl;
    return 0;
}
