#include <cmath>
#include <iostream>
#include "./include/bintree/bintree.h"
#include <set>
#include <tuple>
#include <limits>
#include <functional>

using namespace std;


template<typename t>
void postOrder(bintree<t> &arb) {
    typename bintree<t>::postorder_iterator it = arb.begin_postorder();
    for (; it != arb.end_postorder(); ++it)
        cout << *it << " ";
}

template<typename t>
string postToString(bintree<t> &arb) {
    string res;
    typename bintree<t>::postorder_iterator it = arb.begin_postorder();
    for (; it != arb.end_postorder(); ++it)
        res += *it + " ";
    return res;
}

bool compareRight(int i, int j, tuple<char, int, int> it, int bound) {
    if (j + bound >= get<2>(it) || (i <= get<1>(it) && (j + bound + 1) == get<2>(it)))
        return true;
    else
        return false;
}


bool compareLeft(int i, int j, tuple<char, int, int> it) {
    if (j >= get<2>(it))
        return true;
    else
        return false;
}

void getString(set<tuple<char, int, int>> match, string &res, int &bound) {
    while (match.size() > 2) {
        set<tuple<char, int, int>>::iterator it = match.begin();
        set<tuple<char, int, int>>::iterator coincidencia = it;
        int i = numeric_limits<int>::max(), j = numeric_limits<int>::max();
        for (; it != match.end(); it++) { //lado izquierdo;
            if (get<1>(*it) == 0 || get<2>(*it) == bound) {
                continue;
            }
            if (compareLeft(i, j, *it)) {
                i = get<1>(*it);
                j = get<2>(*it);
                coincidencia = it;
            }
        }
        cout << "I: " << i << " J: " << j << " Value: " <<
        res += get<0>(*coincidencia);
        match.erase(coincidencia);
    }
    set<tuple<char, int, int>>::iterator it = match.begin();
    res += get<0>(*it);
}

string postorden(string preorden, string inorden) {
    set<tuple<char, int, int>> match;
    int bound = 0;
    bool done = false;
    for (unsigned int i = 0; i < preorden.size(); i++) {
        done = false;
        for (unsigned int j = 0; j < inorden.size() && !done; j++) {
            if (preorden[i] == inorden[j]) {
                if (i == 0)
                    bound = j;
                match.insert(make_tuple(preorden[i], i, j));
                done = true;
            }
        }
    }
    string res = "";
    getString(match, res, bound);
    return res;
}

template<typename t>
void preOrder(bintree<t> &arb) {
    typename bintree<t>::preorder_iterator it = arb.begin_preorder();
    for (; it != arb.end_preorder(); ++it)
        cout << *it << " ";
}

template<typename t>
string preToString(bintree<t> &arb) {
    string res = "";
    typename bintree<t>::preorder_iterator it = arb.begin_preorder();
    for (; it != arb.end_preorder(); ++it)
        res += *it + " ";
    return res;
}

template<typename t>
void inOrder(bintree<t> &arb) {
    typename bintree<t>::inorder_iterator it = arb.begin_inorder();
    for (; it != arb.end_inorder(); ++it)
        cout << *it << " ";
}

template<typename t>
string inToString(bintree<t> &arb) {
    string res = "";
    typename bintree<t>::inorder_iterator it = arb.begin_inorder();
    for (; it != arb.end_inorder(); ++it)
        res += *it + " ";
    return res;
}

//Calculamos el arbol dado el inorden y preorden para comprobaciones luego.
bintree<char> crearArbol1() {
    bintree<char> A('G');
    bintree<char>::node n;
    A.insert_left(A.root(), 'E');
    A.insert_right(A.root(), 'M');

    //focus on left side, on E
    n = A.root().left();
    A.insert_left(n, 'A');
    n = n.left();
    A.insert_left(n, 'I');
    A.insert_right(n, 'B');

    //focus on right side, on M
    n = A.root().right();
    A.insert_left(n, 'C');
    A.insert_right(n, 'K');

    //Focus on the left side, on C
    n = n.left();
    A.insert_left(n, 'L');
    A.insert_right(n, 'F');
    n = n.left();
    A.insert_right(n, 'D');

    //Focus on the right side, on K
    n = A.root().right().right(); //Position K
    A.insert_right(n, 'J');
    n = n.right();
    A.insert_left(n, 'H');

    return A;
}


int main() {
    string preorden = "GEAIBMCLDFKJH";
    string inorden = "IABEGLCDCFMKHJ";
    bintree<char> A = crearArbol1();
    cout << "Preorden en string: " << preorden << endl;
    cout << "Preoden arbol creado: ";
    preOrder(A);
    cout << endl;
    cout << "Inorden en string: " << inorden << endl;
    cout << "Inorden en arbol creado: ";
    inOrder(A);
    cout << endl;
    cout << "PostOrden en string: " << postorden(preorden, inorden) << endl;
    cout << "PostOrden en arbol creado: ";
    postOrder(A);
    cout << endl;
    return 0;
}
