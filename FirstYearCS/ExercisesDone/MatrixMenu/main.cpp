// Matrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void Mostrar(vector<vector<int>> vec1, int szvec1);
void Create(vector<vector<int>>& vec1, int szvec1);
void RandomGen(vector<vector<int>>& vec1, int szvec1);
void Rotate(vector<vector<int>>& vec1, int szvec1, int rotation);
int Determinante(vector<vector<int>>& vec1, int szvec1);
int cofactor(vector<vector<int>>& matriz, int orden, int fila, int columna);
void PuntoSilla(vector<vector<int>>& vec1,int szvec1);
void Media(vector<vector<int>>& vec1, int szvec1);
void RemovePairs(vector<vector<int>>& vec1, int szvec1);
void ShowPairs(vector<vector<int>>& vec1, int szvec1);
void Traza(vector<vector<int>>& vec1, int szvec1);
void Frecuency(vector<vector<int>>& vec1, int szvec1);

int main()
{
   int det = 0.0;
   int szvec1 = 3, action, rotation;
   bool run = true;
   vector<vector<int>> vec1(szvec1, vector<int> (szvec1,0));

   while (run) {
      cout << "Hola, bienvenido a la manipulación de matrices!" <<
           "\nQue deseas hacer? " << endl;
      cout << "0)Edit the matriz size\n1)Randomize\n" <<
           "2)Create the matrix\n3)Rotate the matrix\n" <<
           "4)Determinante de la matriz\n5)PuntoSilla\n" <<
           "6)Calcular Media\n7)Remove Pairs\n8)ShowPairs\n" <<
           "9)Traza\n10)Frecuency\n11+)QUIT ";
      cin >> action;
      cout << endl;
      switch (action) {
      case 0:
         printf("El tamano de la matriz era %d, cual quieres ahora? ", szvec1);
         cin >> szvec1;
         break;
      case 1:
         RandomGen(vec1, szvec1);
         break;
      case 2:
         Create(vec1, szvec1);
         break;
      case 3:
         printf("1)for +90\n2)for -90\n3)for 180\n4)for OY\n5)for OX\n");
         cin >> rotation;
         Rotate(vec1, szvec1, rotation);
         break;
      case 4:
         det=Determinante(vec1, szvec1);
         printf("El determinante de la matriz me da: %d \n", det);
         break;
      case 5:
         PuntoSilla(vec1, szvec1);
         break;
      case 6:
         Media(vec1, szvec1);
         break;
      case 7:
         RemovePairs(vec1, szvec1);
         break;
      case 8:
         ShowPairs(vec1, szvec1);
         break;
      case 9:
         Traza(vec1, szvec1);
         break;
      case 10:
         Frecuency(vec1, szvec1);
         break;
      case 11:
         run = false;
         break;
      default:
         if (action > 12) {
            run = false;
         }
         break;
      }
   }
}
void Mostrar(vector<vector<int>> vec1, int szvec1)
{
   cout << "\n";
   for (int i = 0; i < szvec1; i++) {
      for (int j = 0; j < szvec1; j++) {
         cout << vec1[i][j] << " ";
      }
      cout << endl;
   }
   cout << "\n";
}
void Create(vector<vector<int>>& vec1, int szvec1)
{
   printf("Sabiendo que el tamano del vector es [%d][%d] \nIntroduzca los numeros seguidos: ",
          szvec1,szvec1);
   for (int i = 0; i < szvec1; i++) {
      for (int j = 0; j < szvec1; j++) {
         cin >> vec1[i][j];
      }
   }
   Mostrar(vec1, szvec1);
}
void RandomGen(vector<vector<int>>& vec1, int szvec1)
{
   srand(time(NULL));
   double a, b, minimo;
   int aleatorio;
   cout << "Cual es el intervalo de números? ";
   cin >> a >> b;
   for (int i = 0; i < szvec1; i++) {
      for (int j = 0; j < szvec1; j++) {
         minimo = (a <= b) ? a : b;
         aleatorio = minimo + (1.0 * rand() / RAND_MAX) * (b - a + 1);
         vec1[i][j] = aleatorio;
      }
   }
   Mostrar(vec1, szvec1);
}
void Rotate(vector<vector<int>>& vec1, int szvec1, int rotate)
{
   int max1 = szvec1 - 1, max2 = szvec1 - 1;
   vector<vector<int>> vec2(szvec1, vector<int>(szvec1, 0));
   switch (rotate) {
   case 1:
      for (int j = 0; j < szvec1; j++) {
         max1 = 0;
         for (int i = 0; i < szvec1; i++) {
            vec2[j][i] = vec1[max1][max2];
            max1 += 1;
         }
         max2 -= 1;
      }
      break;
   case 2:
      for (int j = 0; j < szvec1; j++) {
         max2 = 0;
         for (int i = 0; i < szvec1; i++) {
            vec2[i][j] = vec1[max1][max2];
            max2 += 1;
         }
         max1 -= 1;
      }
      break;
   case 3:
      for (int j = 0; j < szvec1; j++) {
         max2 = szvec1 - 1;
         for (int i = 0; i < szvec1; i++) {
            vec2[j][i] = vec1[max1][max2];
            max2 -= 1;
         }
         max1 -= 1;
      }
      break;
   case 4:
      for (int j = 0; j < szvec1; j++) {
         max1 = 0;
         for (int i = 0; i < szvec1; i++) {
            vec2[i][j] = vec1[max1][max2];
            max1 += 1;
         }
         max2 -= 1;
      }
      break;
   case 5:
      for (int j = 0; j < szvec1; j++) {
         max2 = 0;
         for (int i = 0; i < szvec1; i++) {
            vec2[j][i] = vec1[max1][max2];
            max2 += 1;
         }
         max1 -= 1;
      }
      break;
   }
   Mostrar(vec2, szvec1);
}
int Determinante(vector<vector<int>>& vec1,int szvec1)
{
   int det = 0.0;
   if (szvec1 == 1) {
      det = vec1[0][0];
   } else {
      for (int j = 0; j < szvec1; j++) {
         det = det + vec1[0][j] * cofactor(vec1, szvec1, 0, j);
      }
   }
   return det;
}
int cofactor(vector<vector<int>>& matriz, int orden, int fila, int columna)
{
   vector<vector<int>> submatriz(orden, vector<int> (orden,0));
   int n = orden - 1;

   int x = 0;
   int y = 0;
   for (int i = 0; i < orden; i++) {
      for (int j = 0; j < orden; j++) {
         if (i != fila && j != columna) {
            submatriz[x][y] = matriz[i][j];
            y++;
            if (y >= n) {
               x++;
               y = 0;
            }
         }
      }
   }

   return pow(-1.0, fila + columna) * Determinante(submatriz, n);
}
void PuntoSilla(vector<vector<int>>& vec1, int szvec1)
{
   bool puntosilla;
   vector<int> min_column(szvec1, 0), max_row(szvec1,0);
   for (int i = 0; i < szvec1; i++) {
      max_row[i] = vec1[i][0];
      for (int j = 0; j < szvec1-1; j++) {
         if (vec1[i][j] < vec1[i][j + 1]) {
            max_row[i] = vec1[i][j+1];
         }
      }
   }
   for (int j = 0; j < szvec1; j++) {
      min_column[j] = vec1[0][j];
      for (int i = 0; i < szvec1-1; i++) {
         if (vec1[i][j] > vec1[i + 1][j]) {
            min_column[j] = vec1[i+1][j];
         }
      }
   }
   for (int i = 0; i < szvec1; i++) {
      if (max_row[i] == min_column[i]) {
         puntosilla = true;
         printf("Hay un punto silla en [%d][%d] con valor de %d\n\n", i, i, max_row[i]);
      }
   }
   if(!puntosilla){
      cout << "No hay puntosilla\n\n";
   }

}
void Media(vector<vector<int>>& vec1, int szvec1)
{
   double media = 0, var = 0, desviation = 0;
   int sztotal = szvec1 * szvec1;
   for (int i = 0; i < szvec1; i++) {
      for (int j = 0; j < szvec1; j++) {
         media += vec1[i][j];
      }
   }
   media /= sztotal;
   for (int i = 0; i < szvec1; i++) {
      for (int j = 0; j < szvec1; j++) {
         desviation += abs(vec1[i][j] - media);
      }
   }
   desviation /= sztotal;
   for (int i = 0; i < szvec1; i++) {
      for (int j = 0; j < szvec1; j++) {
         var += abs(vec1[i][j] - media) * abs(vec1[i][j] - media);
      }
   }
   var /= sztotal;

   printf("La media de los valores de la matriz es: %f \n", media);
   printf("La de1sviacion tipica es %f con una varianza de %f\n\n", desviation, var);
}
void RemovePairs(vector<vector<int>>& vec1, int szvec1)
{
   for (int i = 0; i < szvec1; i++) {
      for (int j = 0; j < szvec1; j++) {
         if (vec1[i][j] % 2 == 0) {
            vec1[i][j] = 0;
         }
      }
   }
   Mostrar(vec1, szvec1);
}
void ShowPairs(vector<vector<int>>& vec1, int szvec1)
{
   vector<int> pares;
   int szpairs = 0;
   for (int i = 0; i < szvec1; i++) {
      for (int j = 0; j < szvec1-1; j++) {
         if (vec1[i][j] * vec1[i][j+1] % 2 == 0) {
            pares.push_back(vec1[i][j]);
            pares.push_back(vec1[i][j+1]);
            szpairs += 2;
         }
      }
   }
   for (int j = 0; j < szvec1; j++) {
      for (int i = 0; i < szvec1 - 1; i++) {
         if (vec1[i][j] * vec1[i+1][j] % 2 == 0) {
            pares.push_back(vec1[i][j]);
            pares.push_back(vec1[i+1][j]);
            szpairs += 2;
         }
      }
   }
   for (int i = 0; i < szpairs-1; i+=2) {
      printf("Los valores %d x %d dan un valor par\n", pares[i], pares[i + 1]);
   }
   cout << "\n";
}
void Traza(vector<vector<int>>& vec1, int szvec1)
{
   for (int j = 0; j < szvec1; j++) {
      for (int i = 0; i < szvec1; i++) {
         if (j == i) {
            cout << setw(j + szvec1) << vec1[i][j] << endl;
         }
      }
   }
}
void Frecuency(vector<vector<int>>& vec1, int szvec1)
{
   vector<int> sorted;
   int szmix = szvec1 * szvec1;
   int change;
   vector<int> frecuency(szmix,0);
   vector<int> valor(szmix,0);
   for (int j = 0; j < szvec1; j++) {
      for (int i = 0; i < szvec1; i++) {
         sorted.push_back(vec1[i][j]);
      }
   }
   for(int i = 0; i<szmix; i++) {
      for(int j = i+1; j<szmix; j++) {
         if(sorted[j]<sorted[i]) {
            change = sorted[i];
            sorted[i] = sorted[j];
            sorted[j] = change;
         }
      }
   }
   for(int i = 0; i<szmix; i++)
      cout << sorted[i] << " ";
  int j,i = 0,szfrec = 0;
   while (i<szmix){
      j = i;
      valor[szfrec] = sorted[i];
      while(sorted[i] == sorted[j]){
         frecuency[szfrec]+=1;
         j+=1;
      }
      i=j;
      szfrec+=1;
   }
   for(int i = 0; i < szfrec; i++){
      printf("\nEl valor %d se ha repetido %d veces", valor[i],frecuency[i]);
   }
   cout << "\n\n";
}
