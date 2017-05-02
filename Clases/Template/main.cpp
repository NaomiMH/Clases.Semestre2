/**
 * Naomi Macias Honti a01282098
 * 2 de mayo 2017
 * 62 min.
 * Crea un arreglo en una clase apartir de un template, agrega, elimina y busca datos e imprime el arreglo.
 */
#include <iostream>

using namespace std;

#include "GenericArray.h"

int main()
{
    GenericArray<int,50> arr;
    arr.insertar(15);
    arr.insertar(7);
    arr.insertar(10);
    arr.insertar(5);
    arr.insertar(9);

    arr.imprimir();

    cout << "*******" << endl;

    arr.insertar(6);
    int pos;
    pos=arr.buscar(6);
    arr.imprimir();
    if(pos!=-1)
        cout << "Se encontro el numero" << endl;
    else
        cout << "No se encontro el numero" << endl;
    arr.borrar(6);
    pos=arr.buscar(6);
    arr.imprimir();
    if(pos!=-1)
        cout << "Se encontro el numero" << endl;
    else
        cout << "No se encontro el numero" << endl;

    return 0;
}
