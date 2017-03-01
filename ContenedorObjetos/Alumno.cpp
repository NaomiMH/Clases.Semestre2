#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

#include "Alumno.h"

Alumno::Alumno()
{
    posicion=0;
}

void Alumno::escribirDatos(string dato, string &nombre, string &matricula, string &carrera, string &correo)
{

    posicion=dato.find(";");
    matricula=dato.substr(0,posicion);
    dato.erase(0,posicion+1);
    posicion=dato.find(";");
    nombre=dato.substr(0,posicion);
    dato.erase(0,posicion+1);
    posicion=dato.find(";");
    carrera=dato.substr(0,posicion);
    dato.erase(0,posicion+1);
    posicion=dato.find(";");
    correo=dato.substr(0,posicion);
}

void Alumno::escribirDocumento(ofstream &archivo, string nombre, string matricula, string carrera, string correo)
{
    archivo <<matricula << ", ";
    archivo << nombre << ", ";
    archivo << carrera << ", ";
    archivo << correo <<"," << endl;

}

bool Alumno::comprobarDatos(string palabra, string comparacion)
{
    dato="";
    palabraC="";
    contador =0;
    while (contador<comparacion.length()){
        dato+=tolower(comparacion[contador]);
        contador++;
    }
    contador=0;
    while (contador<palabra.length()){
        palabraC+=tolower(palabra[contador]);
        contador++;
    }
    if (palabraC==dato)
        return true;
    else{
        if (dato.find(palabraC)!=-1)
            return true;
        else
            return false;
    }
}

void Alumno::escribirArchivo(ofstream &archivo, string nombre, string matricula, string carrera, string correo)
{
    archivo << matricula << ";";
    archivo << nombre << ";";
    archivo << carrera << ";";
    if (correo==""){
        archivo << matricula << "@itesm.mx";
    }
    else
        archivo << correo << endl;
}
