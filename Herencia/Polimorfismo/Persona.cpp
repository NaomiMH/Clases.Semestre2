#include "Persona.h"

Persona::Persona()
{
    nombre="SinNombre";
    direccion = "SinDireccion";
    email= nombre+ "@" + direccion+ ".com";
}

Persona::Persona(string nom, string dir, string ema)
{
    nombre= nom;
    direccion= dir;
    email= ema;
}

Persona::~Persona()
{
    cout << "destructor persona" << endl;
}

string Persona::getNombre()
{
    return nombre;
}

void Persona::setEmail(string ema)
{
    email=ema;
}

void Persona::print()
{
    cout << "Soy persona" << endl;
}
