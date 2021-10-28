#include <iostream>
#include <list>
using namespace std;

template<typename T>
void inversa(list<T> &l){
    int i = 0, size = (l.size()%2==0)? l.size()/2:l.size()/2+1;
    auto rev = l.rbegin();
    auto it = l.begin();
    T temp;
    while(i < size){
        temp = *it;
        *it = *rev;
        *rev = temp;
        it++;
        rev++;
        i++;
    }
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
    list<int> cad2 = {1,2,3,4};
    cout << "############# Test Sample 1 ##############" << endl;
    cout << "Lista: " << cad1;
    inversa(cad1);
    cout << "Resultado: " << cad1;
    cout << "############# End Test Sample ##############" << endl;

    cout << "############# Test Sample 2 ##############" << endl;
    cout << "Lista: " << cad2;
    inversa(cad2);
    cout << "Resultado: " << cad2;
    cout << "############# End Test Sample ##############" << endl;
}
