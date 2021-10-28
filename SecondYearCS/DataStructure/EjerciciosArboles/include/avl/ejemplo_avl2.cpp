// Ejemplo de uso del tipo AVL
// @author Miguel García Silvente

#include <string>
#include <iostream>
#include "avl.h"
using namespace std;

int main()
{
  const int NUM = 14;
  AVL<string, string> dicc;
  string palabras[NUM] = {"12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "80", "70", "60"};
  string definiciones[NUM] = {"objeto muy duro", "objeto muy blando", "objeto dur�imo", "tipo de flor",  "objeto duro o persona intransigente", "flor utilizada para tomar decisiones importantes", "cc", "bb", "aa", "dd", "9", "8", "7", "6"};
  // string clave = "piedra";
  // string definicion = "objeto muy duro";
  
  for (int i= 0; i<NUM; i++) {
    pair<string, string> aux(palabras[NUM-i-1], definiciones[NUM-i-1]);
    dicc.insert(aux);
    cout << "Num.datos: " << dicc.size() << endl;
    // AVL<string, string>::iterator it2 = dicc.end();
    //if (dicc.find(palabras[i])!=it2)
    if (dicc.find(palabras[i])!=dicc.end())
      cout << "Clave " << palabras[i] << " insertada correctamente" << endl;
    else
      cout << "Clave " << palabras[i] << " no insertada" << endl;
  }

  AVL<string, string>::iterator i;
  cout << "Listado del �rbol" << endl;
  for (i= dicc.begin(); i!=dicc.end(); ++i)
    cout << (*i).first << ": " << (*i).second << endl;
  
  /*
  AVL<string, string>::iterator i1;
  cout << "Listado del �rbol" << endl;
  for (i1= dicc.begin(); i1!=dicc.end(); ++i1) {
    (*i1).second = (*i1).second + "Abc";
    cout << (*i1).first << ": " << (*i1).second << endl;
  }
  */  cout << endl;
  dicc.print();
     
  return 0;
}
