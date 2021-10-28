#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <assert.h>
#include <list>

using namespace std;

template<typename T, typename U>
struct data {
    T clave;
    list <U> info_asoci;

    data() {
        clave = "NotFound";
        info_asoci.push_front("tryAgain");
    }

    friend ostream& operator<<(ostream& out, const data<T,U>& obj){
        out << "Clave: " << obj.clave;
        out << "\nContenido:\n";
        for (auto &info: obj.info_asoci) {
            out << "\t" << info << "\n";
        }
        return out;
    }

};

template<typename T, typename U>
bool operator<(const data<T, U> &d1, const data<T, U> &d2) {
    if (d1.clave < d2.clave)
        return true;
    return false;
}

template<typename T, typename U>
bool operator==(const data<T, U> &d1, const data<T, U> &d2) {
    return d1.clave == d2.clave;
}

template<typename T, typename U>
class Diccionario {
private:
    list <data<T, U>> datos;

    void Copiar(const Diccionario<T, U> &Dicc) {
        datos.assign(Dicc.datos.begin(), Dicc.datos.end());
    }

    void Borrar() {
        this->datos.erase(datos.begin(), datos.end());
    }

public:
    using ValueType = data<T, U>;

    Diccionario() : datos(list<data<T, U> >()) {}

    Diccionario(const Diccionario &Dicc) {
        Copiar(Dicc);
    }

    ~Diccionario() {}

    Diccionario<T, U> &operator=(const Diccionario<T, U> &Dicc);

    bool esta_Clave(const T &p, typename list<data<T, U> >::iterator &it_out);

    void Insertar(const T &clave, const list <U> &info);

    void AddSignificado_Palabra(const T &p, const U &s);

    list <U> getInfo_Asoc(const T &p);

    inline int size() const { return datos.size(); }

    /*************************************************************************/
    /****************************FUNCIONES EXTRA******************************/


    void Erase(T clave);

    data<T,U> operator[](int index){
        assert(this->begin() != this->end()) ;
        data<T,U> miData;
        typename Diccionario<T,U>::Iterator it = this->begin();
        miData = it[index];
        return miData;
    }

    //Aniadir aqui
    data<T,U> operator[](T clave){
        assert(this->begin() != this->end()) ;
        data<T,U> miData;
        typename list<data<T,U>>::iterator it;
        bool test = this->esta_Clave(clave, it);
        if(test)
            miData = *it;
        return miData;
    }

    int numDefiniciones(T clave){
        data<T,U> miData = (*this)[clave];
        return miData.info_asoci.size();
    }

    void ImprimirClaves(){
        Diccionario<T,U>::ConstIterator it;
        int cont = 1;
        for(it = this->cbegin(); it!=this->cend();it++){
            cout << cont << " - " <<(*it).clave << endl;
            cont++;
        }
    }

    /// El comentario a continuación es sobre la lectura del archivo data.txt
    /*Operator >>. El formato de la entrada es:
         numero de claves en la primera linea
         clave-iésima retorno de carro
         numero de informaciones asociadas en la siguiente linea
         y en cada linea obviamente la informacion asociada
    */
    template<typename sT, typename sU>
    friend istream &operator>>(istream &is, Diccionario<sT, sU> &Dicc) {
        int num_palabras, num_contenido;
        sT clave;
        string linea;
        sU contenido;
        list <sU> temp, empty;
        is >> num_palabras;
        getline(is,linea);
        for (int i = 0; i < num_palabras; i++) {
            getline(is, clave);
            is >> num_contenido;
            getline(is,linea);
            for (int j = 0; j < num_contenido; j++) {
                getline(is, contenido);
                temp.push_back(contenido);
            }
            Dicc.Insertar(clave, temp);
            temp = empty;
        }
        return is;
    }

    /*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre
    listas de listas y otro sobre listas
    */
    template<typename sT, typename sU>
    friend ostream &operator<<(ostream &os, Diccionario<sT, sU> &Dicc) {
        for (typename Diccionario<T, U>::ConstIterator it = Dicc.cbegin(); it != Dicc.cend(); it++) {
            os << (*it);
            os << endl;
        }

        return os;
    }


    class Iterator {
    public:
        using ValueType = typename Diccionario<T,U>::ValueType;
        using PointerType = ValueType *;
        using ReferenceType = ValueType &;
    public:
        Iterator() : m_Ptr(0) {}

        Iterator(PointerType ptr) : m_Ptr(ptr) {}

        Iterator &operator++() {
            m_Ptr++;
            return this;
        }

        Iterator operator++(int) {
            Iterator iterator;
            iterator.m_Ptr = this->m_Ptr;
            this->m_Ptr++;
            return iterator;
        }

        Iterator &operator--() {
            m_Ptr--;
            return this;
        }

        Iterator operator--(int) {
            Iterator iterator;
            iterator.m_Ptr = this->m_Ptr;
            this->m_Ptr--;
            return iterator;
        }

        ReferenceType operator[](int index){
            for(int i=0;i<index;i++){
                m_Ptr++;
            }
            return *m_Ptr;
        }

        PointerType operator->() {
            return m_Ptr;
        }

        ReferenceType operator*() {
            return *m_Ptr;
        }

        bool operator==(const Iterator &other) const {
            return m_Ptr == other.m_Ptr;
        }

        bool operator!=(const Iterator &other) const {
            return m_Ptr != other.m_Ptr;
        }

        friend class Diccionario<T, U>;

        friend class ConstIterator;

    private:
        typename list<data<T, U>>::iterator m_Ptr;
    };

    class ConstIterator {
    public:
        using ValueType = typename Diccionario<T,U>::ValueType;
        using PointerType = ValueType *;
        using ReferenceType = const ValueType &;
    public:
        ConstIterator() : m_Ptr(0) {}

        ConstIterator(PointerType ptr) : m_Ptr(ptr) {}

        ConstIterator &operator++() {
            m_Ptr++;
            return this;
        }

        ConstIterator operator++(int) {
            ConstIterator iterator;
            iterator.m_Ptr = this->m_Ptr;
            this->m_Ptr++;
            return iterator;
        }

        ConstIterator &operator--() {
            m_Ptr--;
            return this;
        }

        ConstIterator operator--(int) {
            ConstIterator iterator;
            iterator.m_Ptr = this->m_Ptr;
            this->m_Ptr--;
            return iterator;
        }

        ReferenceType operator[](int index) {
            for(int i=0;i<index;i++){
                m_Ptr++;
            }
            return *m_Ptr;
        }

        ReferenceType operator->() {
            return *m_Ptr;
        }

        ReferenceType operator*() {
            return *m_Ptr;
        }

        bool operator==(const ConstIterator &other) const {
            return m_Ptr == other.m_Ptr;
        }

        bool operator!=(const ConstIterator &other) const {
            return m_Ptr != other.m_Ptr;
        }

        friend class Diccionario<T, U>;

    private:
        typename list<data<T, U>>::const_iterator m_Ptr;
    };

    Iterator begin() {
        typename Diccionario<T, U>::Iterator i;
        i.m_Ptr = datos.begin();
        return i;
    }

    Iterator end() {
        typename Diccionario<T, U>::Iterator i;
        i.m_Ptr = datos.end();
        return i;
    }

    ConstIterator cbegin() {
        typename Diccionario<T, U>::ConstIterator i;
        i.m_Ptr = datos.begin();
        return i;
    }

    ConstIterator cend() {
        typename Diccionario<T, U>::ConstIterator i;
        i.m_Ptr = datos.end();
        return i;
    }
};

#include "../src/diccionario.cpp"

#endif