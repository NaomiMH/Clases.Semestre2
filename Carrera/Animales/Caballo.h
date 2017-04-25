#ifndef CABALLO_H
#define CABALLO_H

using namespace std;

#include <iostream>
#include "Animales.h"

class Caballo : public Animales
{
    public:
        Caballo(string);
        void avanzar(int);
        bool ganador();

    private:

};

#endif // CABALLO_H
