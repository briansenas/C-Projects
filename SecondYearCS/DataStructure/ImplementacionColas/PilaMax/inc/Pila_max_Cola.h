/**
  * @file Pila_max_Cola.h
  * @brief Fichero cabecera del TDA Cola
  *
  * Gestiona una secuencia de elementos con facilidades para la inserci�n y
  * borrado de elementos en un extremo
  */

#ifndef _Pila_max_H_
#define _Pila_max_H_

#include <cassert>
#include <iostream>
#include "cola.h"
using namespace std;


/**
 *  @brief T.D.A. Cola
 *
 *
 * Una instancia @e c del tipo de dato abstracto Cola sobre un dominio @e T es
 * una sucesi�n finita de elementos del mismo con un funcionamiento @e FIFO
 * (First In, First Out}). En una cola, las operaciones de inserci�n tienen
 * lugar en uno de los extremos, denominado @e final de la cola, mientras que
 * el borrado y consulta se lleva a cabo en el otro extremo, denominado 
 * @e frente de la cola. Una cola de longitud @e n la denotamos

 * - <a1,a2,a3,..,an<

 * En esta cola, tendremos acceso �nicamente al elemento del @e Frente,
 * es decir, a @e a1. El borrado o consulta de un elemento ser� sobre @e a1,
 * mientras que la inserci�n de un nuevo elemento se har� despu�s de
 * @e an (final de la cola).
 *
 * Si n=0 diremos que la cola est� vac�a.
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el n�mero 
 * de elementos de la cola.
 *
 * @author J. Fdez-Valdivia
 * @date Octubre 2011
*/
template<class T>
struct Elemento{
    T valor;
    T maximo;
    Elemento():valor(0),maximo(0){}
    Elemento(const T& elem): valor(elem),maximo(elem){}

    friend ostream& operator<<(ostream &out, const Elemento &obj){
        out << "Elemento: " << obj.valor << endl;
        out << "Maximo: " << obj.maximo;
        return out;
    }
};

template<class T>
class Pila_max{
private:
    Cola<Elemento<T>> pila;
    int size;

    void changeMax();

public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    Pila_max() { size = 0;
    }

    /**
     * @brief Constructor de copias
     * @param original La cola de la que se har� la copia.
     */
    Pila_max(const Pila_max<T> &original);
    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~Pila_max();
    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignaci�n
     * @param otra La cola que se va a asignar.
     */
    Pila_max& operator=(const Pila_max<T> &otra);

    /**
     * @brief Comprueba si la cola est� vac� a
     */
    bool vacia() const {
        return size == 0;
    }

    /**
     * @brief Devuelve el elemento del frente de la cola
     */
    T& tope();

    /**
     * @brief A�ade un elemento al final de la cola
     * @param elem Elemento que se va a a�adir.
     */
    void poner(const T &elem);

    /**
     * @brief Quita el elemento del frente de la cola
     */
    void quitar();

    /**
     * @brief Devuelve el n�mero de elementos de la cola
     */
    int num_elementos() const {
        return size;
    }

    /**
     * @brief llama de manera recursiva a la funci�n quitar()
     */
    void clean();
};
#include "../src/Pila_max_Cola.cpp"
#endif
