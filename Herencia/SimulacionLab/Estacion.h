#ifndef ESTACION_H
#define ESTACION_H

using namespace std;

#include <iostream>
#include "Equipo.h"

class Estacion:public Equipo
{
    public:
        Estacion(): Equipo() {}
        ~Estacion() {cout<<"destruccion estacion" << endl;}
        void instr(string nombre){cout << "Avanzar Estacion" << endl;}

    private:
        int tie;
};

//void Estacion::instr(string nombre)
//{
//    cout << "Avanzar Estacion" << endl;
//}

#endif // ESTACION_H
