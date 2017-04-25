/**
 * Naomi Macias Honti a01282098
 * 16 de marzo 2017
 * Tiempo no estimado.
 * Simula una carrera de hasta 10 caballos, muestra las posiciones finales y al ganador.
 */
 #include <iostream>

using namespace std;

#include "Caballos.h"
#include "Carrera.h"

int main()
{
    Caballos *caballo;

    int cantidad=0;

    do{
        cout << "Cantidad de caballos? ";
        cin >> cantidad;
        if (cantidad>10 || cantidad<1)
            cout << "Error en cantidad." << endl;
    }while(cantidad>10 || cantidad<1);
    Carrera carrera(cantidad);
    string respuesta;
    cout << "Quiere nombrarlos? ";
    cin >> respuesta;
    int contador=0;
    cin.ignore();
    if(respuesta[0]=='s' && cantidad > 0){
        while(contador<cantidad){
            cout << "Caballo #" << contador+1 << " ";
            getline(cin,respuesta);
            caballo = new Caballos(respuesta);
            carrera.agregarCaballo(caballo, contador);
            contador++;
        }
    }
    else if (cantidad > 0){
        string nombre;
        while(contador<cantidad){
            nombre=contador+1+48;
            caballo = new Caballos(nombre);
            carrera.agregarCaballo(caballo, contador);
            contador++;
        }
    }
    else{
        cout << "Error en cantidad." << endl;
        return 0;
    }

    cout << "Margen: ";
    int margen;
    cin >> margen;

    do{
        carrera.avanzar(margen);
    }while(!carrera.ganador());

    carrera.terminar();

    carrera.borrarCaballos();
    delete caballo;

    return 0;
}
