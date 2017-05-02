#ifndef ALUMNO_H
#define ALUMNO_H

using namespace std;

#include "Persona.h"

class Alumno: public Persona
{
    public:
        Alumno();
        Alumno(int,int,int,int,int,string,string,string);
        ~Alumno();
        void setCalif(int,int);
        int getProm();
        void print();

    private:
        int calificaciones[5];
};

#endif // ALUMNO_H
