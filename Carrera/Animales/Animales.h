#ifndef ANIMALES_H
#define ANIMALES_H

using namespace std;

#include <iostream>

class Animales
{
    public:
        Animales(string nomb){nombre=nomb;}
        void avanzarA(int avance){posicion=posicion+avance;}
        int obtPos(){return posicion;}
        string obtNom(){return nombre;}
        virtual void avanzar(int)=0;
        virtual bool ganador()=0;

    private:
        string nombre;
        int posicion;
};

#endif // ANIMALES_H
