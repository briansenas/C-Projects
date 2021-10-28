#include <iostream>
#include <list>
using namespace std;

template<typename T>
ostream &operator<<(ostream &out, const list <T> &obj) {
    out << "< ";
    for (typename list<T>::const_iterator it = obj.begin();
         it != obj.end(); it++) {
        out << *it << " ";
    }
    out << " >" << endl;
    return out;
}


int main(){
    //SAMPLES
    list<int> cad1 = {1,2,3,4,5,6,7,8,9};

    //END SAMPLES
    cout << "############# Test Sample 1 ##############" << endl;
    cout << "############# End Test Sample ##############" << endl;
}