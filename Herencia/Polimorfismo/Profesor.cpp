#include "Profesor.h"

Profesor::Profesor():Persona()
{
    salario=0;
}

Profesor::Profesor(int sal,string nom, string dir, string ema):Persona(nom,dir,ema)
{
    salario=sal;
}

Profesor::~Profesor()
{
    cout << "Destructor profesor" << endl;
}

void Profesor::setSal(int sal)
{
    salario=sal;
}

int Profesor::getPag()
{
    return salario*24;
}

void Profesor::print()
{
    cout << "Soy un profesor" << endl;
}
