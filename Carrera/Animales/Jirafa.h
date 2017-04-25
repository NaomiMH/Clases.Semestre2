#ifndef JIRAFA_H
#define JIRAFA_H

using namespace std;

#include <iostream>
#include "Animales.h"

class Jirafa : public Animales
{
    public:
        Jirafa(string);
        void avanzar(int);
        bool ganador();

    private:

};

#endif // JIRAFA_H
