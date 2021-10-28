#include <iostream>
#include <list>
using namespace std;

template<typename T>
list<T> inversa(const list<T> &l){
    list<T> temp;
    for(auto it = l.rbegin();
        it != l.rend(); ++it){
        temp.push_back(*it);
    }
    return temp;
}

template<typename T>
ostream &operator<<(ostream &out, const list <T> &obj) {
    for (typename list<T>::const_iterator it = obj.begin();
         it != obj.end(); it++) {
        out << *it << " ";
    }
    out << endl;
    return out;
}

int main(){
    list<int> cad1 = {1,2,3,4,5,6,7,8,9};
    cout << "############# Test Sample 2 ##############" << endl;
    cout << "Lista: " << cad1;
    cad1 = inversa(cad1);
    cout << "Resultado: " << cad1;
    cout << "############# End Test Sample ##############" << endl;


}