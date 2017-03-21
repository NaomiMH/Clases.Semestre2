#include "Tortuga.h"
#include <cmath>

Tortuga::Tortuga()
{

}

int Tortuga::avanzando()
{
    probabilidad=floor((rand()%100)+1);
    if(probabilidad<50)
        pasos=3;
    else if (probabilidad<70)
        pasos=-6;
    else
        pasos=1;
    posicion=posicion+pasos;
    if(posicion>70)
        posicion=70;
    else if(posicion<1)
        posicion=1;
    return posicion;
}

int Tortuga::posicionP()
{
    return posicion;
}

void Tortuga::reiniciar()
{
    posicion=1;
}
