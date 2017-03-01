#ifndef CONTENEDORALUMNOS_H
#define CONTENEDORALUMNOS_H

#include <string>
#include "Alumno.h"

class ContenedorAlumnos
{
    public:
        ContenedorAlumnos();
        void enviarDatos();
        void cargarDatos(ifstream&);
        void buscarDatos(string, string);
        void agregarDatos();
        void eliminarDatos();
        void actualizarDatos();

    private:
        string dato,respuesta;
        Alumno datos;
        int cantidad,contador, error, contador2;
        string nombreP, matriculaP, carreraP, correoP;
        char inicial;
        bool estado;
};

#endif // CONTENEDORALUMNOS_H
