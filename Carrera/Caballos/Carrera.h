#ifndef CARRERA_H
#define CARRERA_H

using namespace std;

#include "Caballos.h"
#include <iostream>

class Carrera
{
    public:
        Carrera(int);
        void agregarCaballo(Caballos*, int);
        void avanzar(const int);
        bool ganador();
        void terminar();
        void borrarCaballos();
    private:
        int contador,inum;
        int cantidad=0;
        int pista=0;
        Caballos *jugadores[10];
};

#endif // CARRERA_H
