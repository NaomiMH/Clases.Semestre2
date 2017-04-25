#ifndef CARRRERA_H
#define CARRRERA_H

using namespace std;

#include "Animales.h"
#include "Caballo.h"
#include "Camello.h"
#include "Jirafa.h"

class Carrrera
{
    public:
        Carrrera();
        ~Carrrera();
        void carrera();
        bool ganadorB();
        string ganadorN();

    private:
        int cantidad,margen,ganador;
        Animales *animales[10];
};

#endif // CARRRERA_H
