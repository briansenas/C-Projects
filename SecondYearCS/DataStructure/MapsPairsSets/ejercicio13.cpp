#include <iostream>
#include <list>
using namespace std;

template<typename T>
list<T> lista_posiciones(const list<T> &l, const list<typename list<T>::iterator> &li){
    list<T> res;
    for(typename list<typename list<T>::iterator>::const_iterator it = li.begin(); it != li.end(); it++){
        res.push_back(*(*it));
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
    list<list<int>::iterator> li1;
    int i=0;
    for(list<int>::iterator it = cad1.begin(); it != cad1.end(); it++){
        if(i%2==0)
            li1.push_back(it);
        i++;
    }
    //END SAMPLES
    cout << "############# Test Sample 1 ##############" << endl;
    cout << "Dada la lista: " << cad1;
    cout << "Y otra de iteradores para cada posicion par " << endl;
    cad1 = lista_posiciones(cad1,li1);
    cout << "El resultado de la lista hecha por esos iteradores es: " << endl;
    cout << cad1;
    cout << "############# End Test Sample ##############" << endl;
}