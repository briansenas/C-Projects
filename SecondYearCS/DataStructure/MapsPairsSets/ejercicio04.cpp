#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool letter_boundaries(char A) {
    return ((A >= 65 && A <= 90) ||
            (A >= 96 && A <= 122) ||
            (A >= 128 && A <= 165) ||
            (A == 39)
    );
}


map<string, int> contar(string texto) {
    string temp = "";
    pair<string, int> toAdd;
    map<string, int> res;
    map<string, int>::iterator it;
    bool word = false;
    for (unsigned int i = 0; i < texto.size(); i++) {
        word = false;
        if (letter_boundaries(texto[i])) {
            if(i < texto.size()-1 && letter_boundaries(texto[i+1]))
                word = true;
            if (temp.empty()) {
                temp += toupper(texto[i]);
            } else {
                temp += texto[i];
            }
        }/*else if (temp.empty())
            temp = texto[i];*/ //Esto es para signos de puntuación ","".""!"...
        if (!word) {
            it = res.find(temp);
            if (it != res.end()) {
                it->second += 1;
            } else if(!temp.empty()){
                //cout << "\t\t ADDING " << temp << endl;
                toAdd.first = temp;
                toAdd.second = 1;
                res.insert(toAdd);
            }
            temp.clear();
        }
    }
    return res;
}

vector<string> veces(const map<string,int> &palabras, int num){
    vector<string> res;
    for(map<string,int>::const_iterator it = palabras.begin();
        it != palabras.end(); it++){
        if(it->second == num){
            res.push_back(it->first);
        }
    }
    return res;
}

int main() {
    int num = 0;
    string cad1 = "Hola - dijo el; Hola - respondio ella";
    string cad2 = "Bueno, buena, buen, buenos, buenas ";
    string cad3 = "Los Signos! Ellos No me asustan. Repito, no me asustan!";

    cout << "############# Test Sample 1 ##############" << endl;
    cout << "Sample: " << cad1 << endl;
    map<string, int> res1 = contar(cad1);
    num = 2;
    cout << "Words that repeated: " << num << " times" << endl;
    vector<string> temp = veces(res1,num);
    for(unsigned int i=0;i<temp.size();i++){
        cout << temp[i];
        if(i!=temp.size()-1)
            cout << " -> ";
    }
    cout << endl;
    cout << "############# End Test Sample ##############" << endl;

    cout << "############# Test Sample 2 ##############" << endl;
    cout << "Sample: " << cad2 << endl;
    map<string, int> res2 = contar(cad2);
    num = 2;
    cout << "Words that repeated: " << num << " times" << endl;
    temp = veces(res2,num);
    for(unsigned int i=0;i<temp.size();i++){
        cout << temp[i];
        if(i!=temp.size()-1)
            cout << " -> ";
    }
    cout << endl;
    cout << "############# End Test Sample ##############" << endl;

    cout << "############# Test Sample 3 ##############" << endl;
    cout << "Sample: " << cad3 << endl;
    map<string, int> res3 = contar(cad3);
    num = 2;
    cout << "Words that repeated: " << num << " times" << endl;
    temp = veces(res3,num);
    for(unsigned int i=0;i<temp.size();i++){
        cout << temp[i];
        if(i!=temp.size()-1)
            cout << " -> ";
    }
    cout << endl;
    cout << "############# End Test Sample ##############" << endl;
}