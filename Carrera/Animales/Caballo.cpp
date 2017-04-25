#include "Caballo.h"
#include <cmath>
#include <cstdlib>

Caballo::Caballo(string respuesta): Animales(respuesta){}

void Caballo::avanzar(int margen)
{
    int avanzando,probabilidad;
    avanzando=floor((rand()%(margen/2))+1);
    avanzando= avanzando+(margen/2);
    avanzarA(avanzando);
}

bool Caballo::ganador()
{
    if(obtPos()>500)
        return true;
    return false;
}
