#include "Camello.h"
#include <cmath>
#include <cstdlib>

Camello::Camello(string respuesta): Animales(respuesta){}

void Camello::avanzar(int margen)
{
    int avanzando,probabilidad;
    avanzando=floor((rand()%margen)+1);
    probabilidad=floor(rand()%100);
    if(probabilidad>70)
        avanzando=0-avanzando;
    else
        avanzando=avanzando*5/2;
    avanzarA(avanzando);
}

bool Camello::ganador()
{
    if(obtPos()>500)
        return true;
    return false;
}
