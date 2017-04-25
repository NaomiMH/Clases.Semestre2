#ifndef CABALLOS_H
#define CABALLOS_H

using namespace std;

#include <iostream>

class Caballos
{
    public:
        Caballos(string);
        void avanzar(int);
        int obtPosicion();
        string obtNombre();
    private:
        string nombre;
        int posicion;
};

#endif // CABALLOS_H
