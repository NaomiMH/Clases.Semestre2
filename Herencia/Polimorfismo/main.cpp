/**
 * Naomi Macias Honti a01282098
 * 1 de mayo 2017
 * 30 min.
 * Implementar las clases Persona, Alumno y Profesor tal como ilustra la figura. Incluir constructores default y con parámetros en todos los casos. Incluir destructores para todas las clases. Incluir métodos accesores y modificadores para todos los atributos. Implementar un programa que cree instancias de los tres tipos de clases.
 */
#include <iostream>

using namespace std;

#include "Persona.h"
#include "Alumno.h"
#include "Profesor.h"

int main()
{
    Alumno a;
    Profesor pr;
    Persona pe;

    pe.print();
    pr.print();
    a.print();


    return 0;
}
