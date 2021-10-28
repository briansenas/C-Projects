#include <iostream>
#include <list>
using namespace std;

template<typename T>
typename list<T>::const_iterator contenida(const list<T>&l1,const list<T>&l2){
    typename list<T>::const_iterator res = l2.begin();
    if(!l1.empty()) {
        typename list<T>::const_iterator it1 = l1.begin();
        typename list<T>::const_iterator it2 = l2.begin();
        bool found = false;
        while (it2 != l2.end() && it1 != l1.end()) {
            if (*it1 == *it2) {
                if (it1 == l1.begin())
                    res = it2;
                it1++;
                if (it1 == l1.end()) {
                    found = true;
                    break;
                }
            } else //Quitar si no tienen porque estar seguidos
                it1 = l1.begin();
            it2++;
        }
        if (!found)
            res = l2.end();
    }

    return res;
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
    //SAMPLES
    list<int> cad1 = {1,2,3,4,5,6,7,8,9};
    list<int> cad11 = {4,5,6,7};
    list<int> cad12 = {7,8,9,10};
    list<int> cad13 = {0,5,1,3};
    //END SAMPLES
    typename list<int>::const_iterator it;
    cout << "############# Test Sample 1 ##############" << endl;
    cout << "Está la cadena: " << cad11;
    cout << "Contenida en: " << cad1;
    it = contenida(cad11,cad1);
    if(it!=cad1.end()){
        cout << "Sí, está contenida! " << endl;
    }else{
        cout << "No, no está contenida!" << endl;
    }
    cout << "############# End Test Sample ##############" << endl;
    cout << "############# Test Sample 2 ##############" << endl;
    cout << "Está la cadena: " << cad12;
    cout << "Contenida en: " << cad1;
    it = contenida(cad12,cad1);
    if(it!=cad1.end()){
        cout << "Sí, está contenida! " << endl;
    }else{
        cout << "No, no está contenida!" << endl;
    }
    cout << "############# End Test Sample ##############" << endl;
    cout << "############# Test Sample 3 ##############" << endl;
    cout << "Está la cadena: " << cad13;
    cout << "Contenida en: " << cad1;
    it = contenida(cad13,cad1);
    if(it!=cad1.end()){
        cout << "Sí, está contenida! " << endl;
    }else{
        cout << "No, no está contenida!" << endl;
    }
    cout << "############# End Test Sample ##############" << endl;
}