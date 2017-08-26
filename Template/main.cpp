#include <iostream>

using namespace std;

#include "ListaCircular.h"
#include "Alumno.h"

int main()
{
    ListaCircular<Alumno, 50> alumnos;
    Alumno* alumno;
    alumno = new Alumno("Juan");
    alumnos.agrega(alumno);

    alumno = new Alumno("Pepito");
    alumnos.agrega(alumno);

    alumno = new Alumno("Antonio");
    alumnos.agrega(alumno);

    alumno = new Alumno("JJJJJ");
    alumnos.agrega(alumno);

    alumno = alumnos.extrae();
    alumno->imprime();
    delete alumno;

    alumno = alumnos.extrae();
    alumno->imprime();
    delete alumno;

    return 0;
}
