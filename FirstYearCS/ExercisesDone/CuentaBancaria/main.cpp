#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dinero {
private:
   int euro;
   int moneda;
public:
   Dinero() {
      euro = 0;
      moneda = 0;
   }
   Dinero(int valor, int centimos) {
      euro = valor;
      moneda = centimos;
   }
   int Euro() {
      return euro;
   }
   int Moneda() {
      return moneda;
   }
   void Add(Dinero p) {
      euro += p.Euro();
      moneda += p.Moneda();
      if(moneda>=100) {
         euro += 1;
         moneda -=100;
      }
   }
   void Extract(Dinero p) {
      euro -= p.Euro();
      moneda -= p.Moneda();
      if(moneda<0) {
         moneda = 100-p.Moneda();
         euro -= 1;
      }
      if(euro<0) {
         euro = 0;
         moneda = 0;
      }
   }
};

Dinero Aplicar() {
   int valor, centimos;
   cout << "Introduzca un valor ";
   cin >> valor >> centimos;
   while (valor < 0 || centimos < 0) {
      cout << "Error, introduzca un valor valido...";
      cin >> valor >> centimos;
   }
   while (centimos >= 100) {
      valor += 1;
      centimos -= 100;
   }
   Dinero p(valor, centimos);
   return p;
}

void LeerValores(Dinero p) {
   cout << "Tienes " << p.Euro() << " con " << p.Moneda() << endl;
}

void COUT(int action=0,string s="NULL") {
   switch(action) {
   case 0:
      cout << "Que deseas hacer? Ver una operacion exacta[1] o un rango[2]? ";
      break;
   case 1:
      cout << "Introduzca el numero de la transaccion? ";
      break;
   case 2:
      cout << "Introduzca el rango de transacciones: ";
      break;
   case 3:
      cout << s << endl;
   }
}

class CuentaBancaria {
private:
   Dinero brian;
public:
   string operations[10000];
   char action;
   bool seguir = true;
   string s;
   int n=0;

   void Start() {
      cin >> action;
      Operate(action);
   }
   void Ret_Oper() {
      int action, n, m;
      COUT();
      cin >> action;
      switch(action) {
      case 1:
         COUT(1);
         cin >> n;
         COUT(3,operations[n-1]);
         break;
      case 2:
         COUT(2);
         cin >> n >> m;
         for(int i=n-1; i<=m; i++)
            COUT(3,operations[i-1]);
      }
   }
   void Operate(char action) {
      Dinero d1;
      switch(toupper(action)) {
      case 'I':
         d1=Aplicar();
         brian.Add(d1);
         LeerValores(brian);
         Store(d1.Euro(),d1.Moneda(),"+");
         break;
      case 'E':
         d1=Aplicar();
         brian.Extract(d1);
         LeerValores(brian);
         Store(d1.Euro(),d1.Moneda(),"-");
         break;
      case 'O':
         Ret_Oper();
         break;
      case 'X':
         seguir = false;
         break;
      }
   }
   bool DarValorSeguir() {
      return seguir;
   }
   void Store(int euro, int moneda, string action) {
      s="";
      s+=action;
      s+=to_string(euro);
      s+=" euros con ";
      s+=to_string(moneda);
      s+=" centimos ";
      operations[n]=s;
      n++;
   }
};

int main() {
   bool seguir = true;
   CuentaBancaria Brian;
   while(seguir) {
      cout << "Introduzca una accion (I=ingresar, E=extrair, O=Operaciones, X=Quit) ";
      Brian.Start();
      seguir = Brian.DarValorSeguir();
   }
}
