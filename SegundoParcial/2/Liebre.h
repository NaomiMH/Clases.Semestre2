#ifndef LIEBRE_H
#define LIEBRE_H

using namespace std;

#include <iostream>
#include <cstdlib>

class Liebre
{
    public:
        Liebre();
        int avanzando(int);
        int posicionP();
        bool empate();
        void reiniciar();
    private:
        int probabilidad,pasos;
        int posicion=1;
        bool mordida;
};

#endif // LIEBRE_H
