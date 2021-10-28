/**
  * @file vector_dinamico.cpp
  * @brief Implementación del TDA VectorDinámico
  *
  */
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/* _________________________________________________________________________ */

template<class T>
Pila_max<T>::Pila_max(const Pila_max<T> &original){
    for(unsigned i=0;i<original.num_elementos();i++){
        this->poner(original.frente());
        original.quitar();
    }
}

/* _________________________________________________________________________ */

template<class T>
Pila_max<T>& Pila_max<T>::operator=(const Pila_max<T>& otra){
    Pila_max<T> vec(otra);
    return vec;
}

/* _________________________________________________________________________ */

template<class T>
void Pila_max<T>::changeMax(){
    for(unsigned i=0;i<valores.size();i++){
        if(valores[i].valor > valores.back().maximo)
            valores.back().maximo = valores[i].valor;
        else
            valores[i].maximo = valores.back().maximo;
    }
}

template<class T>
void Pila_max<T>::poner(const T & elem){
    valores.push_back(Elemento(elem));
    this->changeMax();
}
/* _________________________________________________________________________ */

template<class T>
void Pila_max<T>::quitar(){
    cout << "Extraemos el tope de la pila" << endl;
    cout << valores.back() << endl;
    valores.pop_back();
    if(!valores.empty()) {
        valores.back().maximo = valores.back().valor;
        this->changeMax();
        cout << "El maximo valor de la pila es: " << valores.back().maximo << endl << endl;
    }else
        cout << "La pila está vacia" << endl;
}

/* _________________________________________________________________________ */
