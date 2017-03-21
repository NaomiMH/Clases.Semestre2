#ifndef CARRERA_H
#define CARRERA_H

using namespace std;

#include "Tortuga.h"
#include "Liebre.h"

class Carrera
{
    public:
        Carrera();
        void limpiarPista();
        void escenario();
        bool ganadorB();
        char ganadorC();
        void avanzar();
        void reiniciar();
    private:
        char pistaL[70];
        char pistaT[70];
        int contador,posicion;
        Tortuga tortuga;
        Liebre liebre;
};

#endif // CARRERA_H
