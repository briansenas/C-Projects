#include <iostream>
#include <list>
using namespace std;

template<typename T>
ostream &operator<<(ostream &out, const list <T> &obj) {
    for (typename list<T>::const_iterator it = obj.begin();
         it != obj.end(); it++) {
        out << *it << " ";
    }
    out << endl;
    return out;
}

template<typename T>
list<T> mezclar(const list<T> &l, const list<T> &l2){
    list<T> res;
    typename list<T>::const_iterator it = l.begin(),
    it2 = l2.begin();
    while(it != l.end() && it2 != l2.end()){
        if(*it <= *it2) {
            res.push_back(*it);
            it++;
        }else{
            res.push_back(*it2);
            it2++;
        }
    }
    if(it==l.end()){
        while(it2 != l2.end()){
            res.push_back(*it2);
            it2++;
        }
    }else{
        while(it != l.end()){
            res.push_back(*it);
            it++;
        }
    }

    return res;
}

int main(){
    //SAMPLES
    list<int> cad1 = {1,2,3,4,7,8,9};
    list<int> cad11 = {1,5,6,10};
    list<float> cad2 = {2.34,3.14,6.9};
    list<float> cad22 = {-1,0,4.56,10};
    //END SAMPLES
    cout << "############# Test Sample 1 ##############" << endl;
    cout << "Lista 1: " << cad1;
    cout << "Lista 2: " << cad11;
    cad1 = mezclar(cad1,cad11);
    cout << "Resultado: " << cad1;
    cout << "############# End Test Sample ##############" << endl;
    cout << "############# Test Sample 2 ##############" << endl;
    cout << "Lista 1: " << cad2;
    cout << "Lista 2: " << cad22;
    cad2 = mezclar(cad2,cad22);
    cout << "Resultado: " << cad2;
    cout << "############# End Test Sample ##############" << endl;
    return 0;
}