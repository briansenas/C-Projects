#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string,string> params(string cad){
   map<string,string> res;
   pair<string,string> toAdd;
   string temp = "";
   bool twice;
   unsigned int i = 0 , j = 0;
   while(i<cad.size()){
       if(cad[i]=='-'){
           twice = false;
           temp = ""; // temp = cad[i]; //Depende de si queremos el "-" o no
           if(i==cad.size()-1)
               //cout <<"@[ERROR] Opción no válida" << endl;
               break; //It's a trap
           i++;
           if(cad[i]==' ')
               //cout <<"@[ERROR] Opción no válida" << endl;
               break; //Also a trap
           for(j=i;j<cad.size(); j++){
               if(cad[j]==' ') {
                   if(twice) //Si hay 2 espacios estamos en otro argumento o opcion
                       break;
                   toAdd.first = temp;
                   temp = "";
                   twice = true; //asegurarnos que no vamos a coger otro argumento de más
               }
               else if(cad[j] == ';' || cad[j] == '-')
                   break;
               else
                   temp += cad[j];
           }
           toAdd.second = temp;
           res.insert(toAdd);

           i = j-1; //Hay que reajustar la posicion;
       }
       i++;
   }
   return res;
}

ostream &operator<<(ostream &out, const map <string,string> &obj) {
    for (typename map<string,string>::const_iterator it = obj.begin();
         it != obj.end(); it++) {
        out << "< ";
        out << it->first;
        if(!it->second.empty())
            out << " with arg: " << it->second;
        out << " >" << endl;
    }
    return out;
}


int main(){
    //SAMPLES
    string cad1 = "tar -z -x -f fichero";
    map<string,string> res1;
    string cad2 = "g++ -g -Wall - std=c++11 -o ejecutable ejercicio05.cpp";
    map<string,string> res2;
    string cad3 = "g++ -o ejecutable main.cpp -g -Wall -";
    map<string,string> res3;

    //END SAMPLES
    cout << "############# Test Sample 1 ##############" << endl;
    cout << "La cadena es: " << cad1 << endl;
    res1 = params(cad1);
    cout << res1;
    cout << "############# End Test Sample ##############" << endl;
    cout << "############# Test Sample 2 ##############" << endl;
    cout << "La cadena es: " << cad2 << endl;
    res2 = params(cad2);
    cout << res2;
    cout << "############# End Test Sample ##############" << endl;
    cout << "############# Test Sample 3 ##############" << endl;
    cout << "La cadena es: " << cad3 << endl;
    res3 = params(cad3);
    cout << res3;
    cout << "############# End Test Sample ##############" << endl;
}