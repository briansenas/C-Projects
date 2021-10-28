#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void intercalar(vector<T> &v, vector<pair<int,T>> pos){
    typename vector<T>::iterator temp = v.begin();
    for(typename vector<pair<int,T>>::const_iterator it = pos.begin();
        it != pos.end(); it++){
        if(it->first >= 0 && it->first < v.size()){
            v.insert(temp+it->first,it->second);
            temp = v.begin();
        }else
            continue;
    }
}

template<typename T>
ostream &operator<<(ostream &out, const vector <T> &obj) {
    out << "< ";
    for (typename vector<T>::const_iterator it = obj.begin();
         it != obj.end(); it++) {
        out << *it << " ";
    }
    out << " >" << endl;
    return out;
}


template<typename T>
ostream &operator<<(ostream &out, const vector <pair<int,T>> &obj) {
    out << "< ";
    for (typename vector<pair<int,T>>::const_iterator it = obj.begin();
         it != obj.end(); it++) {
        out << "( " << it->first << " " << it->second << " ), ";
    }
    out << " >" << endl;
    return out;
}

int main(){
    //SAMPLES
    vector<int> cad1 = {1,3,7,3};
    vector<pair<int,int>> pos = {{1,5},{0,7},{4,12},{12,4},{-1,7}};
    //END SAMPLES
    cout << "############# Test Sample 1 ##############" << endl;
    cout << "Vector inicial: " << cad1;
    cout << "Cadena de posiciones: " << pos;
    intercalar(cad1,pos);
    cout << "Resultado final: " << cad1;
    cout << "############# End Test Sample ##############" << endl;
}