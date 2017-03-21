#include "Liebre.h"
#include "cmath"

Liebre::Liebre()
{
    mordida=false;
}

int Liebre::avanzando(int oponente)
{
    probabilidad=floor((rand()%100)+1);
    if(probabilidad<20)
        pasos=0;
    else if (probabilidad<40)
        pasos=9;
    else if (probabilidad<50)
        pasos=-12;
    else if (probabilidad<80)
        pasos=1;
    else
        pasos=-2;
    posicion=posicion+pasos;
    if(posicion>=70)
        posicion=70;
    else if(posicion<=1)
        posicion=1;
    else if(oponente==posicion){
        posicion=posicion-1;
        mordida=true;
    }
    else
        mordida=false;
    return posicion;
}

int Liebre::posicionP()
{
    return posicion;
}

bool Liebre::empate()
{
    if (mordida)
        return true;
    else
        return false;
}

void Liebre::reiniciar()
{
    posicion=0;
}
