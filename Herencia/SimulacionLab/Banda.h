#ifndef BANDA_H
#define BANDA_H

using namespace std;

#include <iostream>
#include "Equipo.h"

class Banda : public Equipo
{
    public:
        Banda(): Equipo(){}
        Banda(int longitud){lon=longitud;}
        ~Banda() {cout << "destructor banda" << endl;}
        void info(string);

    private:
        int lon;
};

void Banda::info(string nombre)
{
    cout << "Avanza banda" << endl;
}

#endif // BANDA_H
