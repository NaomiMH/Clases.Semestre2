#ifndef CAMELLO_H
#define CAMELLO_H

using namespace std;

#include <iostream>
#include "Animales.h"

class Camello : public Animales
{
    public:
        Camello(string);
        void avanzar(int);
        bool ganador();

    private:
};

#endif // CAMELLO_H
