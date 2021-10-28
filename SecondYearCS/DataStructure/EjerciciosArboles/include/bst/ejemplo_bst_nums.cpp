// Ejemplo de uso del tipo BST

#include <string>
#include <iostream>
#include <ctime>
#include "bst.h"
using namespace std;

int main()
{
  BST<long int, string> dicc;

  const long int NUM = 100000;
  long int *v = new long int[NUM];
  long int n = 0;
  srand(time(NULL));
  for (long int i= 0; i<NUM; i++) {
    pair<int, string> aux(1.0*rand()/RAND_MAX*NUM, "");
    dicc.insert(aux);
  }

  cout << "Se han insertado " << dicc.size() << " elementos" << endl;

  int elemento = (*dicc.begin()).first;

  if (dicc.find(elemento)!=dicc.end())
	  cout << elemento << " está en el dicionario" << endl;
  
  elemento = 23;

  if (dicc.find(elemento)!=dicc.end())
	  cout << elemento << " está en el dicionario" << endl;
  return 0;
}
