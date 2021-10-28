#include <iostream>
#include <list>
#include <set>
#include <string>
using namespace std;

struct paciente{
    string  nombre,
            apellidos,
            dni;
    int gravedad;

    paciente(){
        nombre ="";
        apellidos ="";
        dni="";
        gravedad =0;
    }

    paciente(string a, string b, string c, int d){
        nombre = a;
        apellidos = b;
        dni = c;
        gravedad = d;
    }

    friend ostream& operator <<(ostream& out, const paciente& obj){
        out << obj.nombre << " " << obj.apellidos << " " << obj.dni << " con gravedad:" << obj.gravedad;
        return out;
    }
};

class comparePaciente{
public:
    bool operator()(const paciente& obj1, const paciente& obj2){
        bool result = false;
        if(obj1.gravedad >= obj2.gravedad)
            result = true;
        return result;
    }
};

typedef set<paciente,comparePaciente> pacienteSet;

class urgencias{
private:
    pacienteSet cola;
public:
    urgencias(){
        cola = pacienteSet();
    }
    void insertar_paciente(const paciente& p){
        cola.insert(p);
    }
    paciente mas_grave()const{
        pacienteSet::const_iterator it = cola.begin();
        return *it;
    }
    paciente buscar_paciente(string nombre, string apellidos)const{
        pacienteSet::const_iterator it = cola.begin();
        paciente temp;
        for(; it != cola.end(); it++){
            if(it->nombre == nombre && it->apellidos == apellidos)
                temp = *it;
        }
        return temp;
    }

    int size() const{return cola.size();}
    class iterator{
    private:
        pacienteSet::iterator m_Ptr;
    public:
        iterator(){}

        iterator(pacienteSet::iterator ptr) : m_Ptr(ptr) {}

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

        paciente operator[](int index) {
            for (int i = 0; i < index; i++) {
                m_Ptr++;
            }
            return *m_Ptr;
        }

        paciente operator->() {
            return *m_Ptr;
        }

        paciente operator*() {
            return *m_Ptr;
        }

        bool operator==(const iterator &other) const {
            return m_Ptr == other.m_Ptr;
        }

        bool operator!=(const iterator &other) const {
            return m_Ptr != other.m_Ptr;
        }

        friend class urgencias;
    };
    iterator begin() const{
        urgencias::iterator it;
        it.m_Ptr = cola.begin();
        return it;
    }
    iterator end() const{
        urgencias::iterator it;
        it.m_Ptr = cola.end();
        return it;
    }

    friend ostream& operator<<(ostream& out, const urgencias& obj){
        for(urgencias::iterator it = obj.begin();
            it != obj.end(); it++){
            out << "< ";
            out << *it;
            out << " >" << endl;
        }
        return out;
    }
};

template<typename T>
ostream &operator<<(ostream &out, const list <T> &obj) {
    out << "< ";
    for (typename list<T>::const_iterator it = obj.begin();
         it != obj.end(); it++) {
        out << *it << " ";
    }
    out << " >" << endl;
    return out;
}


int main(){
    //SAMPLES
    paciente Brian("Brian","Sena Simons","1234a",67);
    paciente Isra("Isra","Algo","1234b",0);
    paciente Elena("Baguette","Con Qeso","Y3521",23);
    paciente Zoo("Baguette", "Algo","1234a",-1);
    paciente Georgi("Suspenso","Pero Feliz","y1234-f",30);

    urgencias Cenyt;
    Cenyt.insertar_paciente(Brian);
    Cenyt.insertar_paciente(Isra);
    Cenyt.insertar_paciente(Elena);
    Cenyt.insertar_paciente(Zoo);
    Cenyt.insertar_paciente(Georgi);
    //END SAMPLES
    cout << "############# Test Sample 1 ##############" << endl;
    cout << Cenyt;
    cout << "Paciente más grave: " << Cenyt.mas_grave() << endl;
    cout << "Tamaño total de la cola: " << Cenyt.size() << endl;
    cout << "############# End Test Sample ##############" << endl;
}