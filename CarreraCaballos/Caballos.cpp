#include "Caballos.h"
#include <cmath>
#include <cstdlib>

Caballos::Caballos(string respuesta)
{
    nombre = respuesta;
    posicion = 0;
}

void Caballos::avanzar(int margen)
{
    int avanzando;
    avanzando=floor((rand()%margen)+1);
    posicion=posicion+avanzando;
}

int Caballos::obtPosicion()
{
    return posicion;
}

string Caballos::obtNombre()
{
    return nombre;
}
