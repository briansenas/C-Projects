#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cmath>
#include "player.h"
#include "environment.h"

using namespace std;

const double masinf=9999999999.0, menosinf=-9999999999.0;


// Constructor
Player::Player(int jug){
    jugador_=jug;
}

// Actualiza el estado del juego para el jugador
void Player::Perceive(const Environment & env){
    actual_=env;
}

double Puntuacion(int jugador, const Environment &estado){
    double suma=0;

    for (int i=0; i<7; i++)
      for (int j=0; j<7; j++){
         if (estado.See_Casilla(i,j)==jugador){
            if (j<3)
               suma += j;
            else
               suma += (6-j);
         }
      }

    return suma;
}


// Funcion de valoracion para testear Poda Alfabeta
double ValoracionTest(const Environment &estado, int jugador){
    int ganador = estado.RevisarTablero();

    if (ganador==jugador)
       return 99999999.0; // Gana el jugador que pide la valoracion
    else if (ganador!=0)
            return -99999999.0; // Pierde el jugador que pide la valoracion
    else if (estado.Get_Casillas_Libres()==0)
            return 0;  // Hay un empate global y se ha rellenado completamente el tablero
    else
          return Puntuacion(jugador,estado);
}

// ------------------- Los tres metodos anteriores no se pueden modificar

double Puntuacion2(int jugador,bool defensive,const Environment &estado) {
    double suma = 0;
    int other = -1;
    if(jugador==1)
        other = 2;
    else
        other = 1;
    int points = 20, rpoints = 20;
    int seg1 = 100, seg2 = 50, vacio = 1, diag1 = 30, diag2 = 15;
    if(defensive)
        vacio = 10;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if(i>=4 and estado.See_Casilla(i-1,j)!=jugador)
                rpoints = 5;
            points = rpoints;
            if (estado.See_Casilla(i, j) == jugador) {
                suma+=points;
                //DERECHA
                if(j%3==0) {
                    if (j < 4 and estado.See_Casilla(i, j + 1) == jugador) {
                        suma += seg1 + points;
                        if (j < 3 and estado.See_Casilla(i, j + 2) == jugador) {
                            suma += seg2 + points;
                        }
                    }
                }
                //ARRIBA
                if(i<4 and estado.See_Casilla(i+1,j)==jugador){
                    suma+=seg1 +  points;
                    if(i < 3 and estado.See_Casilla(i + 2, j)==jugador)
                        suma+=seg2 + points;
                }
                //DIAGONALDERECHA
                if(i<4 and j<4 and estado.See_Casilla(i+1,j+1)==jugador){
                    suma+=diag1 + points;
                    if(j<3 and i<3 and estado.See_Casilla(i+2,j+2)==jugador)
                        suma+=diag2 + points;
                }
                //DIAGONALIZQUIERDA
                if(i<4 and j>2 and estado.See_Casilla(i+1,j-1)==jugador){
                    suma+=diag1 + points;
                    if(j>3 and i<3 and estado.See_Casilla(i+2,j-2)==jugador)
                        suma+=diag2 + points;
                }
                //DERECHA VACIO
                if (j < 4 and estado.See_Casilla(i, j + 1) == 0) {
                    suma += vacio;
                }
                else{
                    //DIAGONALDERECHA VACIO
                    if(i<4 and j<4 and estado.See_Casilla(i+1,j+1)==0){
                        suma+=vacio;
                    }
                }
                //IZQUIERDA VACIO
                if (j > 2 and estado.See_Casilla(i, j - 1) == 0) {
                    suma += vacio;
                }else{
                    //DIAGONALIZQUIERDA VACIO
                    if(i<4 and j>2 and estado.See_Casilla(i+1,j-1)==0){
                        suma+=vacio ;
                    }
                }
                //ARRIBA VACIO
                if(i<4 and estado.See_Casilla(i+1,j)==0){
                    suma += vacio ;
                }
            }
       }
    }

    return suma;
}


// Funcion heuristica (ESTA ES LA QUE TENEIS QUE MODIFICAR)
double Valoracion(const Environment &estado,int max, int jugador) {
    int ganador = estado.RevisarTablero();
    int other = -1;
    if(max==1)
        other = 2;
    else
        other = 1;

    if (ganador==max)
        return masinf+5; // Gana el jugador que pide la valoracion
        //return 99999999.0; // Gana el jugador que pide la valoracion
    else if (ganador==other)
        //return menosinf-5; // Pierde el jugador que pide la valoracion
        return -99999999.0; // Gana el jugador que pide la valoracion
    else if (estado.Get_Casillas_Libres()==0)
        return 0;  // Hay un empate global y se ha rellenado completamente el tablero
    else{
        if(jugador==1)
            other = 2;
        else
            other = 1;
        bool defensive = false;
        if(max==2)
            defensive = true;
        return Puntuacion2(jugador,defensive,estado)-Puntuacion2(other,defensive,estado);
        //return Puntuacion2(max,defensive,estado) - Puntuacion2(other,defensive,estado); //Change other as != max
    }
}

// Esta funcion no se puede usar en la version entregable
// Aparece aqui solo para ILUSTRAR el comportamiento del juego
// ESTO NO IMPLEMENTA NI MINIMAX, NI PODA ALFABETA
void JuegoAleatorio(bool aplicables[], int opciones[], int &j){
    j=0;
    for (int i=0; i<8; i++){
        if (aplicables[i]){
           opciones[j]=i;
           j++;
        }
    }
}


// Invoca el siguiente movimiento del jugador
Environment::ActionType Player::Think(){
    const int PROFUNDIDAD_MINIMAX = 6;  // Umbral maximo de profundidad para el metodo MiniMax
    const int PROFUNDIDAD_ALFABETA = 8; // Umbral maximo de profundidad para la poda Alfa_Beta

    Environment::ActionType accion; // acción que se va a devolver
    bool aplicables[8]; // Vector bool usado para obtener las acciones que son aplicables en el estado actual. La interpretacion es
                        // aplicables[0]==true si PUT1 es aplicable
                        // aplicables[1]==true si PUT2 es aplicable
                        // aplicables[2]==true si PUT3 es aplicable
                        // aplicables[3]==true si PUT4 es aplicable
                        // aplicables[4]==true si PUT5 es aplicable
                        // aplicables[5]==true si PUT6 es aplicable
                        // aplicables[6]==true si PUT7 es aplicable
                        // aplicables[7]==true si BOOM es aplicable



    double valor; // Almacena el valor con el que se etiqueta el estado tras el proceso de busqueda.
    double alpha, beta; // Cotas de la poda AlfaBeta

    int n_act; //Acciones posibles en el estado actual


    n_act = actual_.possible_actions(aplicables); // Obtengo las acciones aplicables al estado actual en "aplicables"
    int opciones[10];

    // Muestra por la consola las acciones aplicable para el jugador activo
    //actual_.PintaTablero();
    cout << "Acciones aplicables ";
    (jugador_==1) ? cout << "Verde: " : cout << "Azul: ";
    for (int t=0; t<8; t++)
      if (aplicables[t])
         cout << " " << actual_.ActionStr( static_cast< Environment::ActionType > (t)  );
    cout << endl;


    /*//--------------------- COMENTAR Desde aqui
    cout << "\n\t";
    int n_opciones=0;
    JuegoAleatorio(aplicables, opciones, n_opciones);

    if (n_act==0){
      (jugador_==1) ? cout << "Verde: " : cout << "Azul: ";
      cout << " No puede realizar ninguna accion!!!\n";
      //accion = Environment::actIDLE;
    }
    else if (n_act==1){
           (jugador_==1) ? cout << "Verde: " : cout << "Azul: ";
            cout << " Solo se puede realizar la accion "
                 << actual_.ActionStr( static_cast< Environment::ActionType > (opciones[0])  ) << endl;
            accion = static_cast< Environment::ActionType > (opciones[0]);

         }
         else { // Hay que elegir entre varias posibles acciones
            int aleatorio = rand()%n_opciones;
            cout << " -> " << actual_.ActionStr( static_cast< Environment::ActionType > (opciones[aleatorio])  ) << endl;
            accion = static_cast< Environment::ActionType > (opciones[aleatorio]);
         }

    *///--------------------- COMENTAR Hasta aqui


    //--------------------- AQUI EMPIEZA LA PARTE A REALIZAR POR EL ALUMNO ------------------------------------------------


    // Opcion: Poda AlfaBeta
    // NOTA: La parametrizacion es solo orientativa
    // valor = Poda_AlfaBeta(actual_, jugador_, 0, PROFUNDIDAD_ALFABETA, accion, alpha, beta);
    //cout << "Valor MiniMax: " << valor << "  Accion: " << actual_.ActionStr(accion) << endl;
    int act;
    //valor = MiniMax(actual_,jugador_, PROFUNDIDAD_MINIMAX, act);
    alpha = menosinf;
    beta = masinf;
    valor = PodaAlfaBeta( actual_,  jugador_, PROFUNDIDAD_ALFABETA, alpha, beta, act);
    accion = Environment::ActionType(act);
    cout << "Jugador: " << jugador_ << " Valor: " << valor << "  Accion: " << actual_.ActionStr(accion) << endl;
    return accion;
}



double Player::MiniMax(Environment V, int max, const int depth,int& act){
    if(depth==0 or V.JuegoTerminado()) {
        //return ValoracionTest(V,max) ;
        return Valoracion(V,max,V.JugadorActivo());
    }

    if(V.JugadorActivo()==max){
        double maxEval = menosinf;
        double eval = 0;
        Environment *temp = new Environment[8];
        int sz = V.GenerateAllMoves(temp);
        int  index = rand()%sz;
        for(int i=0;i<sz;i++) {
            eval = MiniMax(temp[i],max,depth - 1, act);
            if (eval > maxEval ) {
                index = i;
                maxEval = eval;
            }
        }
        act = temp[index].Last_Action(V.JugadorActivo());
        return maxEval;
    }else{
        double minEval = masinf;
        double eval = 0;
        Environment *temp = new Environment[8];
        int sz = V.GenerateAllMoves(temp);
        for(int i=0;i<sz;i++) {
            eval = MiniMax(temp[i],max,depth - 1, act);
            if (eval <  minEval ) {
                minEval = eval;
            }
        }
        return minEval;
    }
}

void PutPrints(double * prints, int sz){
    cout << "###################################" << endl;
    for(int i=0;i<sz;i++){
        cout << "PUT " << i << " : " << prints[i] << endl;
    }
    cout << "###################################" << endl;
}

double Player::PodaAlfaBeta(Environment V, int max, const int depth, double alpha, double beta, int &act){
    if(depth==0 or V.JuegoTerminado()) {
        return Valoracion(V,max,V.JugadorActivo());
        //return ValoracionTest(V,max);
    }

    if(V.JugadorActivo()==max){
        double maxEval = menosinf;
        //double prints[8];
        double eval = 0;
        Environment *temp = new Environment[8];
        int sz = V.GenerateAllMoves(temp);
        int index = rand()%sz;
        for(int i=0;i<sz;i++) {
            eval = PodaAlfaBeta(temp[i],max,depth - 1,alpha,beta,act);
            //prints[i] = eval;
            if (eval > maxEval) {
                index = i;
                maxEval = eval;
            }
            if(eval>alpha)
                alpha = eval;
            if(beta<=alpha) {
                break;
            }
        }
        /*if(depth>=8) {
            cout << "SIZE: " << sz << endl;
            PutPrints(prints, sz);
        }*/
        act = temp[index].Last_Action(V.JugadorActivo());
        return maxEval;
    }else{
        double minEval = masinf;
        double eval = 0;
        Environment *temp = new Environment[8];
        int sz = V.GenerateAllMoves(temp);
        for(int i=0;i<sz;i++) {
            eval = PodaAlfaBeta(temp[i],max,depth - 1,alpha,beta,act);
            if (eval<minEval) {
                minEval = eval;
            }
            if(eval<beta )
                beta = eval;
            if(beta<=alpha) {
                break;
            }
        }
        return minEval;
    }
}



