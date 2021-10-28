#include <algorithm>
using namespace std;

template <typename T>
inline
POT<T>::POT() {}

template <typename T>
inline
POT<T>::POT(int tam){ datos.reserve(tam); }

template<typename T>
inline
typename POT<T>::size_type POT<T>::size() const { return datos.size(); }

template <typename T>
inline
T POT<T>::min() const { return datos[0]; }

template <typename T>
inline
void POT<T>::insert(const T& x)
{
	datos.push_back(x);
	int pos = datos.size()-1;
	
	while(pos != 0 && datos[pos] < datos[parent(pos)]){
		swap(datos[pos],datos[parent(pos)]);
		pos = parent(pos);
	}
}

template <typename T>
inline
void POT<T>::erase(){
	if(datos.size() == 1)
		datos.pop_back();
	else{
		datos[0] = datos[datos.size()-1];
		datos.pop_back();
		int pos = 0;
		bool terminar = false;
		while(left(pos)!=-1 && !terminar){
			int pos_menor = left(pos);
			if(right(pos) !=-1){
				if(datos[right(pos)] < datos[left(pos)])
					pos_menor = right(pos);
			}
			if(datos[pos] < datos[pos_menor])
				terminar = true;
			else{
				swap(datos[pos],datos[pos_menor]);
				pos = pos_menor;
			}
		}
	}
}

template <typename T>
inline
bool POT<T>::empty() const
{
  return datos.empty();
}


