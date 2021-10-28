#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <typename T>
class vdisperso{
public:
    vdisperso(){
        if(n<0)
            n = -n;
    }
    vdisperso(const vector<T> &v){
        n = 10; //Default value;
        for(unsigned int i=0;i<v.size();i++){
            this->asignar_coeficiente(i,v[i]);
        }
    }
    void asignar_coeficiente(int i,const T&x){
        pair<int,T> temp;
        if (i > n)
            n = i;
        temp.first = i;
        temp.second = x;
        bool added = false;
        if(!coefs.empty()){
            for(typename list<pair<int,T>>::iterator it = coefs.begin();
                it != coefs.end(); it++){
                if(it->first == i) {
                    *it = temp;
                    added = true;
                }
            }
        }
        if(coefs.empty() || !added)
            coefs.push_back(temp);
        n++;
    }
    T operator[](int i) const{
        T temp;
        for(typename list<pair<int,T>>::const_iterator it = coefs.begin();
            it != coefs.end(); it++){
            if( it->first == i)
                temp = it->second;
        }
        return temp;
    }
    vector<T>convertir()const{
        vector<T> res;
        T temp;
        for(int i=0;i<n;i++){
            res.push_back(temp);
        }
        for(typename list<pair<int,T>>::const_iterator it = coefs.begin();
            it != coefs.end(); it++){
            res[it->first] = it->second;
        }
        return res;
    }
    int size() const{
        return n;
    }
    int size_not_nulls()const{
        return coefs.size();
    }

    friend ostream& operator << (ostream& out, const vdisperso<T> &obj){
        out << "< ";
        for(typename list<pair<int,T>>::const_iterator it=obj.coefs.begin();
            it != obj.coefs.end();it++){
            out << it->second << " ";
        }
        out << " >";
        return out;
    }

private:
    list<pair<int,T>>coefs;
    int n;
};

template<typename T>
ostream& operator << (ostream& out, const vector<T> &obj){
    out << "< ";
    for(T num: obj)
       out << num << " ";
    out << " >";
    return out;
}

int main(){
    //SAMPLES
    vector<int> vec1 = {1,2,3,4,5,6};
    vdisperso<int> test1(vec1);
    int pos = 20, valor = 34;

    //END SAMPLES
    cout << "############# Test Sample 1 ##############" << endl;
    cout << "Vector: " << vec1 << endl;
    cout << "VDisperso: " << test1 << endl;
    cout << "Número total de valores: " << test1.size() << endl;
    cout << "Número total de valores no nulos: " << test1.size_not_nulls() << endl;
    cout << "Vamos a cambiar el valor en: " << pos << " por " << valor << endl;
    test1.asignar_coeficiente(pos,valor);
    cout << "VDisperso: " << test1 << endl;
    cout << "Número total de valores: " << test1.size() << endl;
    cout << "Número total de valores no nulos: " << test1.size_not_nulls() << endl;
    cout << "Valor out-of-bound: " << test1[27] << endl;
    cout << "############# End Test Sample ##############" << endl;
}