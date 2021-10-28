#include <iostream>
#include <cstdlib>
#include "pot.h"

const int MAXIMO = 200;

void generar_datos(vector<int> &v, int n)
{
  for (int i= 0; i<n; i++)
    v.push_back((int) (1.0*rand()*MAXIMO/RAND_MAX));
}

template <class Tbase>
void heapsort(vector<Tbase> &v)
{
  int i;
  POT<int> un_POT;

  for (i= 0; i<v.size(); i++)
    un_POT.insert(v[i]);

  i = 0;
  while (!un_POT.empty()) {
    v[i] = un_POT.min();
    i++;
    un_POT.erase();
  }
}

const int NUM = 50;

int main()
{
  vector<int> v;
  generar_datos(v, NUM);
  for (int i=0; i<NUM; i++)
    cout << v[i] << " ";
  cout << endl;
  heapsort(v);
  for (int i=0; i<NUM; i++)
    cout << v[i] << " ";
  cout << endl;

  return 0;
}

