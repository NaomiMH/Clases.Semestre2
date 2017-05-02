#ifndef PERSONA_H
#define PERSONA_H

using namespace std;

#include <iostream>

class Persona
{
    public:
        Persona();
        Persona(string, string, string);
        virtual ~Persona();
        string getNombre();
        void setEmail(string);
        void print();

    private:
        string nombre,direccion,email;
};

#endif // PERSONA_H
