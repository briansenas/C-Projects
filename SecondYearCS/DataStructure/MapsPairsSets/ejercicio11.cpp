#include <iostream>
#include <list>
using namespace std;

void inserta_despues(list<int> &l, int x){
    list<int>::iterator temp;
    for(list<int>::iterator it = l.begin();
        it != l.end(); it++){
        if(*it == x){
            temp = it;
            temp++;
            l.insert(temp,x-1);
        }
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
    //SAMPLES
    list<int> cad1 = {1,2,3,4,5,6,7,8,9};
    list<int> cad2 = {0,2,3,4,2,2,6,7,8,9,9};
    int num = 0;
    //END SAMPLES
    cout << "############# Test Sample 1 ##############" << endl;
    cout << cad1;
    cout << "Vamos a insertar_despues del valor: " << num << endl;
    inserta_despues(cad1,num);
    cout << cad1;
    cout << "############# End Test Sample ##############" << endl;

    num = 2;
    cout << "############# Test Sample 2 ##############" << endl;
    cout << cad1;
    cout << "Vamos a insertar_despues del valor: " << num << endl;
    inserta_despues(cad1,num);
    cout << cad1;
    cout << "############# End Test Sample ##############" << endl;

    num = 9;
    cout << "############# Test Sample 3 ##############" << endl;
    cout << cad1;
    cout << "Vamos a insertar_despues del valor: " << num << endl;
    inserta_despues(cad1,num);
    cout << cad1;
    cout << "############# End Test Sample ##############" << endl;

    num = 0;
    cout << "############# Test Sample 4 ##############" << endl;
    cout << cad2;
    cout << "Vamos a insertar_despues del valor: " << num << endl;
    inserta_despues(cad2,num);
    cout << cad2;
    cout << "############# End Test Sample ##############" << endl;

    num = 2;
    cout << "############# Test Sample 5 ##############" << endl;
    cout << cad2;
    cout << "Vamos a insertar_despues del valor: " << num << endl;
    inserta_despues(cad2,num);
    cout << cad2;
    cout << "############# End Test Sample ##############" << endl;

    num = 9;
    cout << "############# Test Sample 6 ##############" << endl;
    cout << cad2;
    cout << "Vamos a insertar_despues del valor: " << num << endl;
    inserta_despues(cad2,num);
    cout << cad2;
    cout << "############# End Test Sample ##############" << endl;
}