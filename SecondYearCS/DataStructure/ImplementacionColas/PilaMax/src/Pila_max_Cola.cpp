/**
  * @file Pila_max_Cola.cpp
  * @brief Implementación del TDA Cola
  *
  */
#include <cassert>
#include <iostream>
using namespace std;

/* _________________________________________________________________________ */

template<class T>
Pila_max<T>::Pila_max(const Pila_max <T> &obj) {
    pila = obj.pila;
    size = obj.size;
}

/* _________________________________________________________________________ */

template<class T>
Pila_max<T>::~Pila_max() {
    this->clean();
}

/* _________________________________________________________________________ */

template<class T>
Pila_max <T> &Pila_max<T>::operator=(const Pila_max <T> &otra) {
    pila = otra.pila;
    size = otra.size;
}

/*_________________________________________________________________________ */

template<class T>
void Pila_max<T>::poner(const T &elem) {
    Elemento<T> temp(elem);
    pila.poner(temp);
    size++;
    this->changeMax();
}

/* _________________________________________________________________________ */
template<class T>
void Pila_max<T>::changeMax() {
    if(size>1){
        Cola<Elemento<T>>* res = new Cola<Elemento<T>>();
        T max = 0;
        Elemento<T> temp;
        int sz = pila.num_elementos();
        for(int i=0;i<sz;i++){
            if(max < pila.frente().valor)
                max = pila.frente().valor;
            res->poner(pila.frente());
            pila.quitar();
        }
        for(int i=0;i<sz;i++){
            temp = res->frente();
            temp.maximo = max;
            pila.poner(temp);
            res->quitar();
        }
        delete res;
    }
}

template<class T>
T& Pila_max<T>::tope() {
    Cola<Elemento<T>> *temp = new Cola<Elemento<T>>();
    while(pila.num_elementos() > 1)
    {
        temp->poner(pila.frente());
        pila.quitar();
    }
    Elemento<T> res = pila.frente();
    temp->poner(pila.frente());
    pila.quitar();
    pila = *temp;
    delete temp;
    return res.valor;
}

template<class T>
void Pila_max<T>::quitar() {
    Cola<Elemento<T>> *temp = new Cola<Elemento<T>>();
    while (pila.num_elementos() > 1) {
        temp->poner(pila.frente());
        pila.quitar();
    }
    Elemento<T> a = pila.frente();
    cout << a << endl << endl;
    pila.quitar();
    pila = *temp;
    if(pila.num_elementos() > 0) {
        if (a.valor >= pila.frente().maximo) {
            this->changeMax();
        }
        cout << "Nuevo maximo es: " << pila.frente().maximo << endl << endl;
    }else
        cout << "La pila esta vacia..." << endl << endl;
    delete temp;
    size--;
}

template<class T>
void Pila_max<T>::clean() {
    while (size!=0)
        this->quitar();
}
