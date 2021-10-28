#ifndef PRACTICA3_PILA_MAX_VD_H
#define PRACTICA3_PILA_MAX_VD_H

#include <vector>

using namespace std;

/**
 *  @brief T.D.A. Vector_Dinamico
 *
 *
 * Una instancia @e v del tipo de datos abstracto @c Vector_Dinamico sobre el
 * tipo @c float es un array 1-dimensional de un determinado tama�o @e n, que
 * puede crecer y decrecer a petici�n del usuario. Lo podemos representar como
 *
 *  {v[0],v[1],...,v[n-1]}
 *
 * donde  v[i] es el valor almacenado en la posici�n  i del vector
 *
 * La eficiencia en espacio es @e O(n).
 *
 * Un ejemplo de su uso:
 * @include ejemplo_vector_dinamico.cpp
 *
 */
template<class T>
class Pila_max {
private:
    struct Elemento{
        T valor;
        T maximo;
        Elemento():valor(0),maximo(0){}
        Elemento(const T& elem): valor(elem),maximo(elem){}

        friend ostream& operator<<(ostream &out, const Elemento &obj){
            out << "Elemento: " << obj.valor << endl;
            out << "Maximo: " << obj.maximo << endl;
            return out;
        }
    };
    vector<Elemento> valores; ///< Vector de valores

    void changeMax();
public:
    /**
     * @brief constructor por defecto
     */
    Pila_max():valores(0){}

    /**
     * @brief Constructor de copias
     * @param original el vector que se va a copiar
     */
    Pila_max(const Pila_max<T> & original);
    // ------------------ Destructor ------------------
    /**
      * @brief Destructor
      */
    ~Pila_max(){this->clean();}
    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignaci�n
     * @param otra El vector que se va a asignar
     * @return valor
     */
    Pila_max& operator=(const Pila_max<T> &otra);

    /**
     * @brief Comprueba si la cola esta vacia
     * @return
     */
    bool vacia() const{
        return valores.empty();
    }

    /**
     * @brief Devuelve el elemento del frente del vector
     * @return
     */
    T& frente(){
        assert(!this->vacia());
        return valores.back().valor;
    }

    /**
     * @brief A�ade un elemento al final del vector
     * @param elem Elemeneto que se va a a�adir
     */
    void poner(const T& elem);


    /**
     * @brief Quita el elemento del frente de la cola
     */
    void quitar();

    /**
     * @brief Devuelve el n�mero de elementos de la cola
     */
    int num_elementos() const {
        return valores.size();
    }

    /**
     * @brief Vaciamos el vector
     */
    void clean(){
        while(!this->vacia())
            this->quitar();
    }
};

#include "../src/Pila_max_VD.cpp"

#endif //PRACTICA3_PILA_MAX_VD_H
