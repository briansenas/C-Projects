#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Arreglar(string* str1);
void Print(string str1);
void Clean(string* str1, string* str2);

int main() {
	 string str1, str2;
	 cout << "Nombre: ";
	 getline(cin, str1);
	 str1[0] = toupper(str1[0]);//Pone la primera letra en mayusculas
	 Clean(&str1, &str2);
	 Print(str2);
	 Arreglar(&str2);
}
void Print(string str1) {
	 for (int i = 0; i < str1.size(); i++) {
		  cout << str1[i];
	 }
	 cout << endl;
}
void Clean(string* str1, string* str2) {
	 auto Pstr1 = *str1;
	 auto Pstr2 = *str2;
	 for (int i = 1; i < Pstr1.size()-1; i++) {
		  if (Pstr1[i-1] == ' ' && Pstr1[i]==' ') {
				continue;
		  }
		  Pstr2 += str1[i];
	 }
	 Print(Pstr2);
}
void Arreglar(string* str1) {
	 auto Pstr1 = *str1;
	 for (int i = 1; i < Pstr1.length(); i++)//Recorre el string en toda su longitud
	 {
		  if (Pstr1[i] != ' ') {
				Pstr1[i] = tolower(Pstr1[i]);
		  }
		  else {
				Pstr1[i] = toupper(Pstr1[++i]);
		  }
	 }
	 for (int i = 0; i < Pstr1.length(); i++) {
		  cout << Pstr1[i];
	 }
}
