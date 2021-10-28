#include <iostream>
#include <list>

using namespace std;

template<typename T>
void elimina_duplicados(list<T> &l) {
    list<T> temp;
    for(typename list<T>::iterator it = l.begin();
        it != l.end(); it++){
        it = l.begin();
        if(l.begin() == l.end())
            break;
        temp.emplace_back(*it);
        l.remove(*it);
    }
    l = temp;
}

template<typename T>
ostream &operator<<(ostream &out, const list<T> &obj) {
    out << "< ";
    for (typename list<T>::const_iterator it = obj.begin();
         it != obj.end(); it++) {
        out << *it << " ";
    }
    out << " >" << endl;
    return out;
}


int main() {
    //SAMPLES
    list<int> cad1 = {2, 1, 1, 1, 2, 2, 3, 2, 3, 2}; //{2,1}
    list<int> cad2 = {2,2,2};
    list<int> cad3 = {1,2,3,4};
    //END SAMPLES
    cout << "############# Test Sample 1 ##############" << endl;
    cout << cad1;
    elimina_duplicados(cad1);
    cout << cad1;
    cout << "############# End Test Sample ##############" << endl;
    cout << "############# Test Sample 2 ##############" << endl;
    cout << cad2;
    elimina_duplicados(cad2);
    cout << cad2;
    cout << "############# End Test Sample ##############" << endl;
    cout << "############# Test Sample 3 ##############" << endl;
    cout << cad3;
    elimina_duplicados(cad3);
    cout << cad3;
    cout << "############# End Test Sample ##############" << endl;
}