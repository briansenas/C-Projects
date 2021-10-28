#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Aqui definimos todas las variables que vayamos utilizar:
    double x, y, velocity, elevation, height, reach, time, impact_x, impact_y, rotation;
    int laps; //Para quitar los decimales de manera que la rectificación funcione!
    double const PI = 3.14159265358;
    double const G = 9.80665;
    double const angle_conv = PI/180;

    //Empezamos a pedir los valores iniciales:
    cout << "Introduzca dos valores con las posiciones del canyon (x,y): ";
    cin >> x >> y;

    cout << "Introduzca la velocidad inicial de lanzamiento(m/s): ";
    cin >> velocity;

    cout << "Introduzcca el angulo de elevacion (0-90): ";
    cin >> elevation;
    if(elevation > 90 || elevation < 0){
        cout << "Error, introduzca un valor entre 0-90: " << endl;
        return 0;
    }
    elevation *= angle_conv;

    //CALCULOS RELACIONADOS CON EL ANGULO DE ROTACION
    cout << "Introduzca el angulo de rotacion[-180,180]: ";
    cin >> rotation;
    if(rotation > 180){
        laps = (rotation+180)/360;
        rotation -= laps*360;
        cout << "angulo rectificado: " << rotation << endl;
    }
    if(rotation < -180){
        laps = (-rotation+180)/360;
        rotation += laps*360;
        cout << "angulo rectificado: " << rotation << endl;
    }
    rotation *= angle_conv;


    cout << "========= Resultado de los calculos ===========" << endl;

    time = (2*velocity*sin(elevation))/G;
    cout << "Tiempo de vuelo: " << time << " segundos" << endl;

    height = ((pow(velocity*sin(elevation),2))/(2*G));
    cout << "Altura maxima alcanzada: " << height << " metros" << endl;

    reach = (pow(velocity,2)*sin(2*elevation))/G;
    cout << "El alcanze maximo del proyectil es: " << reach << " metros" << endl;

    impact_x = x + reach*sin(rotation);
    impact_y = y + reach*cos(rotation);
    cout << "El impacto final se encuentra en: " << impact_x << " , " << impact_y << " (x,y)" << endl;


    cout << "=========== Comprobacion de objetivo ============" << endl;

    //Para el juego ejercicio 2.3:
    double target_x, target_y;
    cout << "Introduzca dos valores para una posicion para nuestro target: ";
    cin >> target_x >> target_y;

    //Valores para la cercania
    double min_d, max_d;
    cout << "Cuales son las distancias min/max? ";
    cin >> max_d >> min_d;

    double distancia;
    distancia = sqrt(pow((impact_x-target_x),2) + pow((impact_y-target_y),2));

    //Comprobacion de impacto
    if(distancia < min_d){
        cout << "Impacto en lleno a una distancia de " << distancia << " metros" << endl;
    }
    if(distancia > min_d && distancia < max_d){
        cout << "Impacto parcial a una distancia de " << distancia << " metros" << endl;
    }
    else {
        cout << "No hemos impactado con el objetivo, estuvimos a " << distancia << " metros" << endl;
    }





}
