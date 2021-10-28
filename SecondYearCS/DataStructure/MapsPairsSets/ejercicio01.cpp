#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
 * Busca por un cambio de un char a otro en la variable codigo. En caso de
 * que no se encuentre una pareja, se ignora el cambio y se sigue con el
 * procedimiento de codificación.
 * @param cad cadena  a codificar.
 * @param codigo map con parejas a cambiar.
 * @return cadena codificada.
 */
string encripta(string cad, const map<char, char> &codigo) {
    bool done = false;
    for (unsigned int i = 0; i < cad.size(); i++) {
        done = false;
        for(map<char,char>::const_iterator it = codigo.begin();
            it != codigo.end() && !done; it++){
            if( it->first == cad[i] ) {
                cad[i] = it->second;
                done = true;
            }
            if(it->first > cad[i])
                done = true;
        }
    }
    return cad;
}

int main() {

    string cad1 = "Brian Sena Simons";
    string cad2 = "Apassword123";
    string cad3 = "QuieroCaféPls";


    map<char,char> codigo;
    pair<char, char> temp;
    for (int i = 0; i < 256; i++) {
        temp.first = 1 + i;
        temp.second = temp.first + 5; //Simple encriptación de + 5;
        codigo.insert(temp);
    }

    cout << "############# Test Sample 1 ##############" << endl;
    cout << "Sample: " << cad1 << endl;
    cout << "Result: " << encripta(cad1, codigo) << endl;
    cout << "############# End Test Sample ##############" << endl;


    cout << "############# Test Sample 2 ##############" << endl;
    cout << "Sample: " << cad2 << endl;
    cout << "Result: " << encripta(cad2, codigo) << endl;
    cout << "############# End Test Sample ##############" << endl;

    cout << "############# Test Sample 3 ##############" << endl;
    cout << "Sample: " << cad3 << endl;
    cout << "Result: " << encripta(cad3, codigo) << endl;
    cout << "############# End Test Sample ##############" << endl;

    return 0;
}
