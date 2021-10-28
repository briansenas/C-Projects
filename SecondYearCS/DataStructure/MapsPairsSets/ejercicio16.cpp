#include <iostream>
#include <list>
using namespace std;

template<typename T>
list<pair<T,int>> comprimir(const list<T> &l){
    T old_value,new_value; int count = 0;
    list<pair<T,int>> res;
    pair<T,int> temp;
    typename list<T>::const_iterator it = l.begin();
    if(it != l.end())
        new_value = old_value = *it;
    for(; it != l.end(); it++){
        new_value = *it;
        if(old_value!=new_value){
            temp.first = old_value;
            temp.second = count;
            res.push_back(temp);
            count = 0;
            old_value = new_value;
        }
        count++;
    }
    temp.first = new_value;
    temp.second = count;
    res.push_back(temp);
    return res;
}

template<typename T>
list<T> descomprimir(const list<pair<T,int>> &lc){
    list<T> res;
    for(typename list<pair<T,int>>::const_iterator it = lc.begin();
        it != lc.end(); it++){
        for(int i = 0; i < it->second; i++){
            res.push_back(it->first);
        }
    }
    return res;
}

template<typename T>
ostream &operator<<(ostream &out, const list <T> &obj) {
    out << "< ";
    for (typename list<T>::const_iterator it = obj.begin();
         it != obj.end(); it++) {
        out  << *it << ",";
    }
    out << " >" << endl;
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, const list <pair<T,int>>&obj) {
    out << "< ";
    for (typename list<pair<T,int>>::const_iterator it = obj.begin();
         it != obj.end(); it++) {
        out  << "( " << it->first << ", " << it->second << " ), " ;
    }
    out << ">" << endl;
    return out;
}

int main(){
    //SAMPLES
    list<int> cad1 = {1,1,1,2,2,2,2,2,2,7,7,7,7,7,12,1,1,5,5};
    list<pair<int,int>> cad11;
    list<int> cad2;
    //END SAMPLES
    cout << "############# Test Sample 1 ##############" << endl;
    cout << cad1;
    cad11 = comprimir(cad1);
    cout << cad11;
    cad2 = descomprimir(cad11);
    cout << cad2;
    cout << "############# End Test Sample ##############" << endl;
}