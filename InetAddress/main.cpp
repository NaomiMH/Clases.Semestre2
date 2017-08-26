/**
 * Naomi Macias Honti a01282098
 * 24 de marzo 2017
 * 3 hr 30 min.
 * Recibe un archivo del cual busca cierta informacion solicitada, ya sea buscar por palabra clave o algo especifico, tambien se puede modificar, eliminar y agregar informacion al archivo.
 */
#include <iostream>
#include <fstream>

using namespace std;

#include "DNS.h"

void menu()
{
    cout << "1. Obtener la IP de un Hostname (con direccion completa)." << endl;
    cout << "2. Obtener el Hostname de una IP (con direccion completa)." << endl;
    cout << "3. Buscar un Hostname (con direccion incompleta)." << endl;
    cout << "4. Buscar una IP (con direccion incompleta)." << endl;
    cout << "5. Mostrar lista de Hostnames e IPs." << endl;
    cout << "6. Modificar archivo." << endl;
    cout << "0. Salir." << endl;
}

int main()
{
    cout << "Bienvenido a InetAddress." << endl << endl;
    cout << "Para continuar eliga una opcion:" << endl;
    string res;
    DNS datos;
    datos.leerArchivo();
    do{
        menu();
        cin >> res;
        cin.ignore();
        cout << endl;
        switch(res[0]){
        case 49: {datos.obtIP(); break;}
        case 50: {datos.obtHost(); break;}
        case 51: {datos.busHost(); break;}
        case 52: {datos.busIP(); break;}
        case 53: {datos.mostInAd(); break;}
        case 54: {datos.modInAd(); break;}
        case 48: {cout << "Saliendo."; break;}
        default: {cout << "Error." << endl; break;}
        }
        cout << endl << endl;
    }while(res[0]!=48);

    cout << "Quieres guardar los cambios? (si/no) ";
    cin >> res;
    if(res[0]=='s')
        datos.escrArchivo();

    return 0;
}
