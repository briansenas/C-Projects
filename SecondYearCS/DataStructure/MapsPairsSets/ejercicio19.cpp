#include <iostream>
#include <set>
#include <list>
using namespace std;

struct piloto{
    string  nombre,
            apellidos,
            escuderia;
    int puntos;

    piloto(){
        puntos = 0;
    }

    piloto(string vn, string vp,string esc, int vx){
        nombre = vn;
        apellidos = vp;
        escuderia = esc;
        puntos = vx;
    }

    friend ostream& operator <<(ostream& out, const piloto &obj){
        out << obj.nombre << " " << obj.apellidos << " con: " << obj.escuderia << " con " << obj.puntos << " puntos!";
        return out;
    }
};

class piloto_ordenar{
public:
    bool operator()(const piloto& p1, const piloto& p2)const {
        return p1.puntos >= p2.puntos;
    }
};

typedef set<piloto,piloto_ordenar> pilotosSet;

ostream &operator<<(ostream &out, const list<piloto> &obj) {
    for (typename list<piloto>::const_iterator it = obj.begin();
         it != obj.end(); it++) {
        out << "< ";
        out << *it;
        out << " >" << endl;
    }
    return out;
}
ostream &operator<<(ostream &out, const pilotosSet &obj) {
    for (pilotosSet::const_iterator it = obj.begin();
         it != obj.end(); it++) {
        out << "< ";
        out << *it;
        out << " >" << endl;
    }
    return out;
}

class pilotos{
private:
    pilotosSet datos;

public:
    pilotos(){
        datos = pilotosSet();
    }
    pilotos(pilotosSet ndata){
        datos = ndata;
    }
    void insertar_piloto(const piloto &p){
        datos.insert(p);
    }
    piloto buscar_apellidos(string apellidos) const{
       pilotosSet::const_iterator it = datos.begin();
       piloto res;
       for(; it != datos.end(); it++){
           if(it->apellidos == apellidos)
               res = *it;
           if(it->apellidos > apellidos)
               break;
       }
       return res;
    }
    piloto buscar_nombre(string nombre) const{
        pilotosSet::const_iterator it = datos.begin();
        piloto res;
        for(; it != datos.end(); it++){
            if(it->nombre == nombre)
                res = *it;
            if(it->nombre > nombre)
                break;
        }
        return res;
    }
    void cambiar_puntuacion(string apellidos,string nombre, int puntos){
        pilotosSet::iterator it = datos.begin();
        piloto temp;
        for(; it != datos.end(); it++){
            if(it->apellidos == apellidos && it->nombre == nombre){
                temp = *it;
                datos.erase(it);
                break;
            }
        }
        temp.puntos = puntos;
        datos.insert(temp);
    }

    list<piloto> buscar_escuderia(string escuderia) const {
        list<piloto> res;
        pilotosSet::const_iterator it = datos.begin();
        for(; it != datos.end(); it++){
            if(it->escuderia == escuderia)
                res.push_back(*it);
        }
        return res;
    }

    piloto posicion(int num)const{
        pilotosSet::const_iterator it = datos.begin();
        for(int i=0;i < num && it != datos.end();i++){
           it++;
        }
        return *it;
    }

    friend ostream& operator<<(ostream& out, const pilotos &obj){
        out << obj.datos;
        return out;
    }

    class iterator{
    private:
        pilotosSet::reverse_iterator m_Ptr;

        iterator(){}

        iterator(pilotosSet::reverse_iterator ptr) : m_Ptr(ptr) {}

        iterator &operator++() {
            m_Ptr++;
            return *this;
        }

        iterator operator++(int) {
            iterator it;
            it.m_Ptr = this->m_Ptr;
            this->m_Ptr++;
            return it;
        }

        iterator &operator--() {
            m_Ptr--;
            return *this;
        }

        iterator operator--(int) {
            iterator it;
            it.m_Ptr = this->m_Ptr;
            this->m_Ptr--;
            return it;
        }

        piloto operator[](int index) {
            for (int i = 0; i < index; i++) {
                m_Ptr++;
            }
            return *m_Ptr;
        }

        piloto operator->() {
            return *m_Ptr;
        }

        piloto operator*() {
            return *m_Ptr;
        }

        bool operator==(const iterator &other) const {
            return m_Ptr == other.m_Ptr;
        }

        bool operator!=(const iterator &other) const {
            return m_Ptr != other.m_Ptr;
        }

        friend class pilotos;
    };

};




int main(){
    //SAMPLES
    piloto Brian("Brian","Sena Simons","Ferrari",67);
    piloto Isra("Isra","Algo","BmW",0);
    piloto Elena("Baguette","Con Qeso","Fiat",23);
    piloto Zoo("Baguette", "Algo","Ferrari",-1);
    piloto Georgi("Suspenso","Pero Feliz","caballo",30);

    pilotos Formula1;
    Formula1.insertar_piloto(Brian);
    Formula1.insertar_piloto(Isra);
    Formula1.insertar_piloto(Elena);
    Formula1.insertar_piloto(Zoo);
    Formula1.insertar_piloto(Georgi);
    //END SAMPLES
    cout << "############# Test Sample 1 ##############" << endl;
    cout << Formula1;
    cout << "Buscando por Nombre: Brian "<< Formula1.buscar_nombre("Brian") << endl;
    cout << "Buscando por Apellidos: Algo " << Formula1.buscar_apellidos("Algo") << endl;
    cout << "Buscando por Escuderia: Ferrari " << endl << Formula1.buscar_escuderia("Ferrari");
    cout << "Indicando Piloto en Primera posicion: " << Formula1.posicion(0) << endl;
    cout << "Cambiando los Puntos de: Baguette Algo" << endl;
    Formula1.cambiar_puntuacion("Algo","Baguette",100);
    cout << Formula1;
    cout << "############# End Test Sample ##############" << endl;
}