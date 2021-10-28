/**
  * @file Pila_max_Cola.h
  * @brief Fichero cabecera del TDA Cola
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
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
 * una sucesión finita de elementos del mismo con un funcionamiento @e FIFO
 * (First In, First Out}). En una cola, las operaciones de inserción tienen
 * lugar en uno de los extremos, denominado @e final de la cola, mientras que
 * el borrado y consulta se lleva a cabo en el otro extremo, denominado 
 * @e frente de la cola. Una cola de longitud @e n la denotamos

 * - <a1,a2,a3,..,an<

 * En esta cola, tendremos acceso únicamente al elemento del @e Frente,
 * es decir, a @e a1. El borrado o consulta de un elemento será sobre @e a1,
 * mientras que la inserción de un nuevo elemento se hará después de
 * @e an (final de la cola).
 *
 * Si n=0 diremos que la cola está vacía.
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el número 
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
     * @param original La cola de la que se hará la copia.
     */
    Pila_max(const Pila_max<T> &original);
    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~Pila_max();
    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignación
     * @param otra La cola que se va a asignar.
     */
    Pila_max& operator=(const Pila_max<T> &otra);

    /**
     * @brief Comprueba si la cola está vací a
     */
    bool vacia() const {
        return size == 0;
    }

    /**
     * @brief Devuelve el elemento del frente de la cola
     */
    T& tope();

    /**
     * @brief Añade un elemento al final de la cola
     * @param elem Elemento que se va a añadir.
     */
    void poner(const T &elem);

    /**
     * @brief Quita el elemento del frente de la cola
     */
    void quitar();

    /**
     * @brief Devuelve el número de elementos de la cola
     */
    int num_elementos() const {
        return size;
    }

    /**
     * @brief llama de manera recursiva a la función quitar()
     */
    void clean();
};
#include "../src/Pila_max_Cola.cpp"
#endif
