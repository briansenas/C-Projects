#include <iostream>
#include <bintree.h>
#include <string>
#include <stack>
using namespace std;

template<typename T>
bintree<T> construye_arbol(string postfijo){
    stack<char> pila;
    char a,b;
    stack<bintree<T>> arboles;
    for(unsigned int i=0; i < postfijo.size(); i++){
        if(toupper(postfijo[i])>=65 && toupper(postfijo[i])<=90){
            pila.push(postfijo[i]);
        }else if(pila.size()>1){
            b = pila.top();
            pila.pop();
            a = pila.top();
            pila.pop();
            bintree<T> arb(postfijo[i]);
            arb.insert_left(arb.root(),a);
            arb.insert_right(arb.root(),b);
            arboles.push(arb);
        }
        else if(pila.size()==1 && !arboles.empty()) {
            b = pila.top();
            pila.pop();
            bintree<T> arb(postfijo[i]);
            arb.insert_right(arb.root(),b);
            arb.insert_left(arb.root(),arboles.top());
            arboles.pop();
            arboles.push(arb);
        }
        else if(arboles.size()>1){
            bintree<T> arb(postfijo[i]);
            arb.insert_right(arb.root(),arboles.top());
            arboles.pop();
            arb.insert_left(arb.root(),arboles.top());
            arboles.pop();
            arboles.push(arb);
        }
    }
    return arboles.top();
}

int main() {
    string postfijo[]={
            "ab*c/ef/g*+K+xy*-",
            "ab+c-d*",
            "ab-c/e+",
            "abcde+*+",
            "ab+cd*+e*",
    };
    for(auto& s:postfijo) {
        bintree<char> A = construye_arbol<char>(s);
        for (bintree<char>::postorder_iterator it = A.begin_postorder(); it != A.end_postorder(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    return 0;
}
