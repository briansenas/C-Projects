#ifndef __POT_H__
#define __POT_H__

/**
   TDA bintree.

   Representa un árbol binario equilibrado con nodos etiquetados con datos del tipo T.

   T debe tener definidas las operaciones:

   - T & operator=(const T & e);
   - bool operator!=(const T & e);
   - bool opertaor==(const T & e);

   Son mutables.
   Residen en memoria dinámica.
   
*/

#include <vector>

template<typename T>
class POT{
public:
	
	typedef unsigned int size_type;
	
	POT();
	
	POT(int tam);
	
	POT(const POT<T> &copiado);
	
	size_type size() const;
	
	T min() const;
	
	void erase();
	
	void insert(const T& x);

	bool empty() const;
	
	private:
		std::vector<T> datos;
		
		int parent(int h){
			if (h == 0)
				return -1;
			return (h-1)/2;
		}
		int left(int p){
			if (2*p+1>=datos.size())
				return -1;
			 return 2*p+1;
		}
		int right(int p){
			if (2*p+2>=datos.size())
				return -1;
			return 2*p+2;
		}
};

#include "pot.hxx"


#endif
			 
