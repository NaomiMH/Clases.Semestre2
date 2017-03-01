/**
 * Naomi Macias Honti a01282098
 * 27 de febrero 2017
 * 3 hr.
 * Lee los datos de un archivo csv y permite buscar en base a la informacion obtenida, borrar y crear nuevos datos en la lista que se guardan.
 */
#include <iostream>
#include <fstream>

using namespace std;

#include "ContenedorAlumnos.h"


int main()
{
    ifstream archivo;
    archivo.open("Contenedor.csv");
    ContenedorAlumnos documento;
    documento.cargarDatos(archivo);
    documento.enviarDatos();

    string palabra, parametro, respuesta;
    char letra;

    cout << "Quiere buscar informacion? (si/no) ";
    cin >> respuesta;
    letra=tolower(respuesta[0]);
    if (letra=='s'){
        cout << "Buscar (palabra clave o numero): ";
        cin >> palabra;
        cout << "En (nombre/matricula/carrera): ";
        cin >> parametro;
        documento.buscarDatos(palabra,parametro);
    }

    cout << "Quiere agregar alumnos? (si/no) ";
    cin >> respuesta;
    letra=tolower(respuesta[0]);
    if (letra=='s'){
        documento.agregarDatos();
    }
    cout << "Quiere borrar alumnos? (si/no) ";
    cin >> respuesta;
    letra=tolower(respuesta[0]);
    if (letra=='s'){
        documento.eliminarDatos();
    }
    cout << "Quiere actualizar el archivo? (si/no) ";
    cin >> respuesta;
    letra=tolower(respuesta[0]);
    if (letra=='s'){
        documento.actualizarDatos();
    }
    return 0;
}
