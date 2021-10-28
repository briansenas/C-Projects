// Ejemplo de uso del tipo BST

#include <string>
#include <iostream>
#include <ctime>
#include "bst.h"
using namespace std;

template <typename Key, typename T>
void mostrar_bst(const BST<Key, T> &B)
{
  for (typename BST<Key, T>::iterator it = B.begin(); it!=B.end(); it++)
    cout << (*it).first << " ";
  cout << endl;
}

int main()
{
  BST<long int, string> dicc;

  const long int NUM = 100000;
  long int *v = new long int[NUM];
  long int n = 0;
  srand(time(NULL));
  pair<int, string> aux;
  for (long int i= 0; i<NUM; i++) {
    aux.first = 1.0*rand()/RAND_MAX*NUM;
    dicc.insert(aux);
  }
  aux.first =5500;
  dicc.insert(aux);

  cout << "Se han insertado " << dicc.size() << " elementos" << endl;

  int elemento = (*dicc.begin()).first;

  if (dicc.find(elemento)!=dicc.end())
	  cout << elemento << " está en el dicionario" << endl;

  BST<long int, string>::iterator it = dicc.erase(aux.first);
  if (it!=dicc.end()) {

    cout << "Elemento borrado, los siguientes son :";
    for (int i=0; i<5 && it!=dicc.end(); i++) {
       cout << (*it).first << " ";
       it++;
    }
    cout << endl;
  }

  elemento = 23;

  if (dicc.find(elemento)!=dicc.end())
	  cout << elemento << " está en el dicionario" << endl;

  // Probamos a borrar un elemento de un BST sin elementos o con solo uno o dos elementos
  BST<long int, string> dicc2;
  aux.first = 12;
  dicc2.insert(aux);
  mostrar_bst(dicc2);
  aux.first = 25;
  dicc2.insert(aux);
  mostrar_bst(dicc2);
  dicc2.erase(12);
  mostrar_bst(dicc2);
  aux.first = 12;
  dicc2.insert(aux);
  aux.first = 5;
  dicc2.insert(aux);
  mostrar_bst(dicc2);
  dicc2.erase(12);
  mostrar_bst(dicc2);

  return 0;
}
