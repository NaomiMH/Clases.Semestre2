/**
 * Naomi Macias Honti a01282098
 * 25 de abril 2017
 * Tiempo no estimado.
 * Simula una carrera de Caballos, Camellos y Jirafas que tienen diferentes probabilidades de movimiento.
 */
#include <iostream>

using namespace std;

#include "Carrrera.h"

int main()
{
    Carrrera carrera;
    while(!carrera.ganadorB())
        carrera.carrera();
    cout << "El ganador es ";
    if(carrera.ganadorN()=="Jirafa")
        cout << "la ";
    else
        cout << "el ";
    cout << carrera.ganadorN() << "!" << endl;
    return 0;
}
