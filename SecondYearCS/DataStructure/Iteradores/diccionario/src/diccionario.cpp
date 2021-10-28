#include <iostream>
#include <list>

using namespace std;

// ###############################################################
template<typename T, typename U>
bool Diccionario<T,U>::esta_Clave(const T &p, typename list<data<T, U>>::iterator &it_out) {
    bool res = false;
    if (datos.size() > 0) {
        for (typename list<data<T,U>>::iterator it = datos.begin();
        it != datos.end(); it++){
            if ((*it).clave == p){
                it_out = it;
                res = true;
                break;
            }
            if ((*it).clave > p){//It is a sorted list, therefore if I surpassed the value it is not there.
                it_out = it;
                res = false;
                break;
            }
        }
    } else {
        it_out = datos.end();
        res = false;
    }
    return res;
}

// ##########################################################################

template<typename T, typename U>
void  Diccionario<T,U>::Insertar(const T &clave, const list <U> &info) {
    typename list<data<T, U> >::iterator it;
    list<U> temp = info;
    if (!esta_Clave(clave, it)) {
        data<T, U> p;
        p.clave = clave;
        p.info_asoci = info;
        datos.insert(it, p);
    }else{
        (*it).info_asoci.splice((*it).info_asoci.begin(),temp); //Podría tbm llamar a AddSignifica_Palabra;
    }
}

// ##########################################################################
template<typename T, typename U>
list <U> Diccionario<T,U>::getInfo_Asoc(const T &p) {
    typename list<data<T, U> >::iterator it;
    if (!esta_Clave(p, it)) {
        return list<U>();
    } else {
        return (*it).info_asoci;
    }
}

// ##########################################################################

template<typename T, typename U>
Diccionario<T, U>& Diccionario<T,U>::operator=(const Diccionario<T, U> &Dicc) {
    if (this != &Dicc) {
        Borrar();
        Copiar(Dicc);
    }
    return *this;
}

// ##########################################################################

template<typename T, typename U>
void Diccionario<T,U>::AddSignificado_Palabra(const T &p, const U &s){
    Diccionario<T,U>::Iterator it;
    for(it=this->begin(); it !=this->end();it++){
        if((*it).clave == p){
            (*it).info_asoci.push_back(s);
        }
    }
}

template<typename T, typename U>
void Diccionario<T,U>::Erase(T clave){
    typename list<data<T,U>>::iterator it;
    if(esta_Clave(clave,it)){
        datos.erase(it);
    }
}