//-*-Mode: C++;-*-


/**
  * @file avl.hxx
  * @brief Implementación del TDA AVL
  * @author Miguel García Silvente
  */

  /**
       * repABB Rep del TDA ABB
       *
       * @section invABB Invariante de la representaci�n
       *
       * Un objeto v�lido e rep del TDA AVL debe cumplir
       - @c
       * rep.arbolb.Etiqueta(n).clave != rep.arbolb.Etiqueta(m).clave
       * para todo \e n,m del �rbol binario - Para todo nodo @c n se
       * verifica que la @c rep.arbolb.Etiqueta(n).clave es mayor que
       * @c rep.arbolb.Etiqueta(m).clave para todo @c m descendiente a
       * la izquierda de @c n y menor que @c
       * rep.arbolb.Etiqueta(u).clave para todo @c u es descendiente a
       * la derecha de @c n
       *
       * @section fA: Funci�n de abstracci�n
       *
       * Un objeto válido @e rep del TDA ABB queda representado por el �rbol arbolb
       *
    */



template <typename Key, typename T>
inline
bool AVL<Key, T>::encontrar(const pair<Key, T> & e,
      typename bintree<etiqueta_nodo>::node & n,
      typename bintree<etiqueta_nodo>::node & nodo_padre) const
{
  bool encontrado = false;
  n = arbolb.root();

  typename bintree<etiqueta_nodo>::node padre_aux;

  while (!n.null() && !encontrado) {
    Key aux =  (*n).clave;
    if (aux == e.first)  // La clave ya aparece
      encontrado = true;
    else {
      padre_aux = n;
      if (aux < e.first) // Debe insertarse a la derecha de n
        n = n.right();
      else // Debe insertarse a la izquierda de n
        n = n.left();
    }
  }

  nodo_padre = padre_aux;

  return encontrado;
}


template <typename Key, typename T>
inline
AVL<Key, T>::AVL()
{
}

template <typename Key, typename T>
void AVL<Key, T>::insert(const pair<Key, T> & entrada)
{
  bool encontrado = false;
  typename bintree<etiqueta_nodo>::node n, nodo_padre;


  encontrado = encontrar(entrada, n, nodo_padre);
  /*if (encontrado) {
      cout << entrada.first << endl;
  }
  else {
      cout << entrada.first << " no encontrado" << endl;
  }
  */

  if (!encontrado) {
    etiqueta_nodo en;
    en.clave = entrada.first;
    en.etiqueta = entrada.second;
    en.h = 0;
    if (nodo_padre.null()) { // Arbol vacio
      bintree<etiqueta_nodo> aux(en);
      arbolb = aux;
    }
    else {
      bintree<etiqueta_nodo> aux(en);
      if ((*nodo_padre).clave < entrada.first) {
        arbolb.insert_right(nodo_padre, aux);
      }
      else {
        arbolb.insert_left(nodo_padre, aux);
      }
      // Actualizar altura
      typename bintree<etiqueta_nodo>::node aux_node = nodo_padre;
      bool terminar = false;
      while (!terminar && !aux_node.null()) {
          int h_nueva = 1+max(altura(aux_node.left()), altura(aux_node.right()));
          if (h_nueva != (*aux_node).h) {
              (*aux_node).h = h_nueva;
              aux_node = aux_node.parent();
          }
          else terminar = true;
      }
      // Ajustar árbol
      //cout << "Padre: " << (*nodo_padre).clave << " hijo " << entrada.first << endl;
      if ((*nodo_padre).clave < entrada.first)
        ajustar_avl(nodo_padre.right());
      else
        ajustar_avl(nodo_padre.left());
      //cout << "Padre: " << (*nodo_padre).clave << " hijo " << entrada.first << endl;
    }
  }
  else // Sustituimos la etiqueta para esa clave
    (*n).etiqueta = entrada.second;
}

template <typename Key, typename T>
void AVL<Key, T>::ajustar_avl(const typename bintree<etiqueta_nodo>::node &n)
{
    typename bintree<etiqueta_nodo>::node m = n.parent();
    bool terminar = false;
    while (!terminar && !m.null()) {
        //cout << altura(m.left()) << " " << altura(m.right()) << endl;
        if (abs(altura(m.left()) - altura(m.right())) > 1)
            terminar = true;
        else
            m = m.parent();
    }
    if (!m.null()) { // Hay que ajustar el árbol
        //cout << altura(m.left()) << " " << altura(m.right()) << endl;
        if (altura(m.left()) > altura(m.right())) { // Rotar derecha
            //cout << " y " << altura(m.left()) << " " << altura(m.right()) << endl;
            if (altura(m.left().left()) > altura(m.left().right())) // Simple
                rotar_derecha(m.left());
            else {
                rotar_izquierda(m.left().right());
                rotar_derecha(m.left());
            }
	}
        else { // Rotar izquierda
            //cout << " y " << altura(m.left()) << " " << altura(m.right()) << endl;

            if (altura(m.right().right()) > altura(m.right().left())) // Simple
                rotar_izquierda(m.right());
            else {
                rotar_derecha(m.right().left());
                rotar_izquierda(m.right());
            }
        }
    }
}

template <typename Key, typename T>
void AVL<Key, T>::rotar_derecha(const typename bintree<etiqueta_nodo>::node &n)
{
    //cout << "Clave: " << (*n).clave << endl;
    typename bintree<etiqueta_nodo>::node padre_n = n.parent();

    bool sobre_raiz = false, es_hijo_izquierda = false;
    if (padre_n.parent().null())
        sobre_raiz = true;
    else
	    if (padre_n==padre_n.parent().left())
		    es_hijo_izquierda = true;

    bintree<etiqueta_nodo> aux, aux2, aux_padre;
    arbolb.prune_right(n, aux);
    arbolb.prune_left(padre_n, aux2);

    if (!sobre_raiz) {
	    typename bintree<etiqueta_nodo>::node m = padre_n.parent();
	    if (es_hijo_izquierda) {
                //cout << "Es hijo izquierda " << arbolb.size() << endl;
		    arbolb.prune_left(m, aux_padre);
                    aux_padre.insert_left(aux_padre.root(), aux);
                    (*aux_padre.root()).h = 1+max(altura(aux_padre.root().left()),
                                                  altura(aux_padre.root().right()));
                    aux2.insert_right(aux2.root(), aux_padre);
		    arbolb.insert_left(m, aux2);
                    //cout << "Nodos " << arbolb.size() << endl;
	    }
        else {
                //cout << "Es hijo derecha " << arbolb.size() << endl;
		    arbolb.prune_right(m, aux_padre);
            aux_padre.insert_left(aux_padre.root(), aux);
            (*aux_padre.root()).h = 1+max(altura(aux_padre.root().left()),
                                                  altura(aux_padre.root().right()));
            aux2.insert_right(aux2.root(), aux_padre);
		    arbolb.insert_right(m, aux2);
	    }
        if (!m.right().null()) (*m.right()).h = 1+max(altura(m.right().left()), altura(m.right().right()));
            (*m).h = 1+max(altura(m.left()), altura(m.right()));

    }
    else {
        aux2.insert_right(aux2.root(), arbolb);
        aux2.insert_left(aux2.root().right(), aux);
	    arbolb.assign_subtree(aux2, aux2.root());

        typename bintree<etiqueta_nodo>::node m = arbolb.root();
        (*m.left()).h = 1+max(altura(m.right().left()), altura(m.right().right()));
        (*m).h = 1+max(altura(m.left()), altura(m.right()));
    }
    //cout << " __________________________________" << endl;
}

template <typename Key, typename T>
void AVL<Key, T>::rotar_izquierda(const typename bintree<etiqueta_nodo>::node &n)
{
    //cout << "Rotar_izquierda Clave: " << (*n).clave << endl;
    typename bintree<etiqueta_nodo>::node padre_n = n.parent();

    bool sobre_raiz = false, es_hijo_izquierda = false;
    if (padre_n.parent().null())
        sobre_raiz = true;
    else
	    if (padre_n==padre_n.parent().left())
		    es_hijo_izquierda = true;

    bintree<etiqueta_nodo> aux, aux2, aux_padre;
    arbolb.prune_left(n, aux);
    arbolb.prune_right(padre_n, aux2);

    if (!sobre_raiz) {
	    typename bintree<etiqueta_nodo>::node m = padre_n.parent();
	    if (es_hijo_izquierda) {
		    arbolb.prune_left(m, aux_padre);
                    aux_padre.insert_right(aux_padre.root(), aux);
                    (*aux_padre.root()).h = 1+max(altura(aux_padre.root().left()),
                                                  altura(aux_padre.root().right()));
                    aux2.insert_left(aux2.root(), aux_padre);
                    (*aux2.root()).h = 1+max(altura(aux2.root().left()), altura(aux2.root().right()));
		    arbolb.insert_left(m, aux2);
	    }
    	    else {
		    arbolb.prune_right(m, aux_padre);
                    aux_padre.insert_right(aux_padre.root(), aux);
                    (*aux_padre.root()).h = 1+max(altura(aux_padre.root().left()),
                                                  altura(aux_padre.root().right()));
                    aux2.insert_left(aux2.root(), aux_padre);
                    (*aux2.root()).h = 1+max(altura(aux2.root().left()), altura(aux2.root().right()));
		    arbolb.insert_right(m, aux2);
	    }
            if (!m.left().null()) (*m.left()).h = 1+max(altura(m.left().left()), altura(m.left().right()));
	    (*m).h = 1+max(altura(m.left()), altura(m.right()));
    }
    else {
        aux2.insert_left(aux2.root(), arbolb);
        aux2.insert_right(aux2.root().left(), aux);
	    arbolb.assign_subtree(aux2, aux2.root());

        typename bintree<etiqueta_nodo>::node m = arbolb.root();
        (*m.left()).h = 1+max(altura(m.left().left()), altura(m.left().right()));
        (*m).h = 1+max(altura(m.left()), altura(m.right()));
    }
    //cout << " __________________________________" << endl;
}

template <typename Key, typename T>
int AVL<Key, T>::altura(const typename bintree<etiqueta_nodo>::node &n)
{
    if (n.null())
        return -1;
    else
        return (*n).h;
      //return 1+max(altura(n.left()), altura(n.right()));
}

template <typename Key, typename T>
typename AVL<Key, T>::iterator AVL<Key, T>::find(const Key & clave) const
{
  pair<Key, T> e;
  typename bintree<etiqueta_nodo>::node nodo, nodo_padre;

  e.first = clave;

  bool encontrado = encontrar(e, nodo, nodo_padre);

  iterator it;
  if (encontrado) {
    it.elnodo = nodo;
    return it;
  }
  else
    return end();
}


template <class Key, class T>
void AVL<Key, T>::borrar_nodo(
  typename bintree<typename AVL<Key, T>::entry>::node nodo,
  typename bintree<typename AVL<Key, T>::entry>::node nodo_padre)
{
  if (!nodo.left().null() && !nodo.right().null()) {
    bintree<typename AVL<Key, T>::entry> Taux;
    if (nodo_padre.null())
      arbolb.clear();
    else {
      if (nodo_padre.left() == nodo)
        arbolb.prune_left(nodo_padre, Taux);
      else
        arbolb.prune_right(nodo_padre, Taux);
    }
  }
  else { // 1 � 2 hijos
    if (!nodo.left().null() && !nodo.right().null()) {
      typename bintree<typename AVL::entry>::node aux = nodo.left();
      while (!aux.right().null())
        aux = aux.right();
      *nodo = *aux;
      borrar_nodo(aux, aux.parent());
    }
    else { // 1 hijo
      bintree<typename AVL::entry> Taux, Taux2;
      if (!nodo.left().null())
        arbolb.prune_left(nodo, Taux);
      else
        arbolb.prune_right(nodo, Taux);

      if (!nodo_padre.null())
        arbolb = Taux;
      else {
        if (nodo_padre.left() == nodo) {
          arbolb.prune_left(nodo_padre, Taux2);
          arbolb.insert_left(nodo_padre, Taux);
        }
        else {
          arbolb.prune_right(nodo_padre, Taux2);
          arbolb.insert_right(nodo_padre, Taux);
        }
      }
    }
  }
}

template <class Key, class T>
typename AVL<Key, T>::iterator AVL<Key, T>::erase(const Key & clave)
{
  typename bintree<typename AVL<Key, T>::entry>::node nodo, nodo_padre;

  typename AVL<Key, T>::entry e;
  typename AVL<Key, T>::iterator it;
  e.clave = clave;

  bool encontrado = encontrar(e, nodo, nodo_padre);

  it.elnodo = nodo;
  if (encontrado) {
    ++it; // El siguiente al nodo borrado
    borrar_nodo(nodo, nodo_padre);
  }
  ajustar_avl(nodo_padre);

  return it;
}


template <class Key, class T>
inline
typename AVL<Key, T>::size_type AVL<Key, T>::size() const
{
  return arbolb.size();
}

template <class Key, class T>
inline
typename AVL<Key, T>::iterator AVL<Key, T>::begin() const
{
  iterator ite;
  if (!arbolb.empty()) {
    typename bintree<typename AVL<Key, T>::entry>::node nodo = arbolb.root();
    while (!nodo.left().null)
      nodo = nodo.left();
    ite.elnodo = nodo;
  }

  return ite;
}

template <class Key, class T>
inline
typename AVL<Key, T>::iterator AVL<Key, T>::end()
{
  iterator ite;
  return ite;
}

template <class Key, class T>
inline
typename AVL<Key, T>::iterator AVL<Key, T>::begin()
{
  iterator ite;
  if (!arbolb.empty()) {
    typename bintree<typename AVL<Key, T>::entry>::node nodo = arbolb.root();
    while (!nodo.left().null())
      nodo = nodo.left();
    ite.elnodo = nodo;
  }

  return ite;
}

template <class Key, class T>
inline
typename AVL<Key, T>::iterator AVL<Key, T>::end() const
{
  iterator ite;
  return ite;
}


template <class Key, class T>
inline
AVL<Key, T>::~AVL()
{
    //preorden_con_altura(arbolb.root());
}

template <class Key, class T>
inline
AVL<Key, T>::iterator::iterator()
{
}

template <class Key, class T>
inline
typename AVL<Key, T>::iterator& AVL<Key, T>::iterator::operator++()
{
  if (elnodo.null())
    return *this;

  if (!elnodo.right().null()) {
      elnodo = elnodo.right();
      while (!elnodo.left().null())
        elnodo = elnodo.left();
  }
  else {
      while (!elnodo.parent().null() &&
                 elnodo.parent().right() == elnodo)
        elnodo = elnodo.parent();
      // Si (padre de elnodo es nodo_nulo), hemos terminado
      //       // En caso contrario, el siguiente node es el padre
     elnodo = elnodo.parent();
  }
  return *this;
}

template <class Key, class T>
inline
typename AVL<Key, T>::iterator AVL<Key, T>::iterator::operator++(int)
{
  typename AVL<Key, T>::iterator aux(*this);
  this->operator++();

  return aux;
}

template <class Key, class T>
inline pair<Key, T> AVL<Key, T>::iterator::operator*() const
{
  return pair<Key, T>((*elnodo).clave, (*elnodo).etiqueta);
}


template <class Key, class T>
inline
bool AVL<Key, T>::iterator::operator==(const AVL<Key, T>::iterator &i) const
{
  return elnodo == i.elnodo;
}

template <class Key, class T>
inline
bool AVL<Key, T>::iterator::operator!=(const AVL<Key, T>::iterator &i) const
{
  return !(*this == i);
}

template <class Key, class T>
inline
typename AVL<Key, T>::iterator &
AVL<Key, T>::iterator::operator=(const AVL<Key, T>::iterator &i)
{
  elnodo = i.elnodo;
  return *this;
}


template <class Key, class T>
inline
AVL<Key, T>::iterator::iterator(const typename AVL<Key, T>::iterator & i)
  : elnodo(i.elnodo)
{
}
