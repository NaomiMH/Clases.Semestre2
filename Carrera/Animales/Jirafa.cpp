#include "Jirafa.h"
#include <cmath>
#include <cstdlib>

Jirafa::Jirafa(string respuesta): Animales(respuesta){}

void Jirafa::avanzar(int margen)
{
    int avanzando,probabilidad;
    avanzando=floor((rand()%margen)+1);
    probabilidad=floor(rand()%100);
    if(probabilidad>40)
        avanzando=avanzando;
    else
        avanzando=avanzando*5/3;
    avanzarA(avanzando);
}

bool Jirafa::ganador()
{
    if(obtPos()>500)
        return true;
    return false;
}
