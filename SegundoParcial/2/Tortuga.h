#ifndef TORTUGA_H
#define TORTUGA_H

using namespace std;

#include <iostream>
#include <cstdlib>

class Tortuga
{
    public:
        Tortuga();
        int avanzando();
        int posicionP();
        void reiniciar();
    private:
        int probabilidad, pasos;
        int posicion=1;
};

#endif // TORTUGA_H
