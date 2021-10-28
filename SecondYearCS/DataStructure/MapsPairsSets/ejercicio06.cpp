#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T>
void elimina(list <T> &l, const vector <T> &v) {
    typename list<T>::iterator temp;
    for (unsigned int i = 0; i < v.size(); i++) {
        for (typename list<T>::iterator it = l.begin();
             it != l.end(); it++) {
            temp = it;
            while (temp != l.end()) {
                if ((*temp) == v[i]) {
                    temp = l.erase(temp);
                } else
                    temp++;
            }
            if(temp==l.end())
                break;
        }
    }
}

template<typename T>
ostream &operator<<(ostream &out, const vector <T> &obj) {
    for (unsigned int i = 0; i < obj.size(); i++) {
        out << obj[i];
        if (i != obj.size() - 1)
            out << " -> ";
    }
    out << endl;
    return out;
}

template<class T>
ostream &operator<<(ostream &out, const list <T> &obj) {
    for (typename list<T>::const_iterator it = obj.begin();
         it != obj.end(); it++) {
        out << *it << " ";
    }
    out << endl;
    return out;
}

int main() {

    // SAMPLES
    vector<int> del1 = {1, 6};
    list<int> cad1 = {2, 1, 1, 1, 1, 5, 3, 6};
    vector<int> del2 = {0};
    list<int> cad2 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<float> del3{3.14, 2.25, 6.9};
    list<float> cad3{3.14, 2.25, 6.9};
    //END SAMPLES

    cout << "############# Test Sample 1 ##############" << endl;
    cout << "Vector: " << del1;
    cout << "Lista: " << cad1;
    cout << "Borrando todas las incidencias del vector en la lista.." << endl;
    elimina(cad1, del1);
    cout << "Resultado: " << cad1;
    cout << "############# End Test Sample ##############" << endl;

    cout << "############# Test Sample 2 ##############" << endl;
    cout << "Vector: " << del2;
    cout << "Lista: " << cad2;
    cout << "Borrando todas las incidencias del vector en la lista.." << endl;
    elimina(cad2, del2);
    cout << "Resultado: " << cad2;
    cout << "############# End Test Sample ##############" << endl;

    cout << "############# Test Sample 3 ##############" << endl;
    cout << "Vector: " << del3;
    cout << "Lista: " << cad3;
    cout << "Borrando todas las incidencias del vector en la lista.." << endl;
    elimina(cad3, del3);
    cout << "Resultado: " << cad3;
    cout << "############# End Test Sample ##############" << endl;
}