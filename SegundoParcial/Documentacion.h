#ifndef DOCUMENTACION_H
#define DOCUMENTACION_H

#include <string>
#include <iostream>

using namespace std;

class Documentacion
{
    public:
        Documentacion();
        bool checarExistencia();
        void empezarArchivo();
        void terminandoArchivo();
        void llenarinformacion();
        void crearArchivo();

    private:
        string datos, dato, instruccion, nombre, archivoE, archivoS;
        int posicion, error, instrucciones;
        string progName, author, date, funcName, desc, param, retur;
};

#endif // DOCUMENTACION_H
