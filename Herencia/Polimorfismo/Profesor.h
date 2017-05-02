#ifndef PROFESOR_H
#define PROFESOR_H

using namespace std;

#include "Persona.h"

class Profesor : public Persona
{
    public:
        Profesor();
        Profesor(int,string,string,string);
        ~Profesor();
        void setSal(int);
        int getPag();
        void print();

    private:
        double salario;
};

#endif // PROFESOR_H
