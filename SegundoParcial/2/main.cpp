/**
 * Naomi Macias Honti a01282098
 * 8 de marzo 2017
 * Tiempo no estimado.
 * Carrera entre la liebre y la tortuga, van pendiente arriba despues de una lluvia, por lo que el camino esta resbaladizo, tienen diferentes probabilidades de avanzar asi como de resbalarse.
 */
#include <iostream>

using namespace std;

#include "Carrera.h"

int main()
{
    Carrera carrera;
    string respuesta,enter;

    do{
        cout << "A quien apoyas? (liebre/tortuga) ";
        cin >> respuesta;

        carrera.reiniciar();

        cout << "\nPUM!!!" << endl;
        cout << "Y ARRANCAN!!!" << endl << endl;
        cin.ignore();

        while(!carrera.ganadorB()){
            cout << "********************************************************************************" << endl << endl;
            carrera.avanzar();
            carrera.escenario();

            if(!carrera.ganadorB()){
                cout << "\nDale a enter para continuar";
                getline(cin,enter);
            }
            cout << endl << endl;
        }

        if (carrera.ganadorC()=='a')
            cout << "Empate!" << endl;
        else if (carrera.ganadorC()=='l'){
            if (respuesta[0]=='l')
                cout << "Felicidades, g";
            else
                cout << "G";

            cout << "ano la liebre!!" << endl;
        }
        else if (carrera.ganadorC()=='t'){
            if (respuesta[0]=='t')
                cout << "Felicidades, g";
            else
                cout << "G";
            cout << "ano la tortuga!" << endl;
        }
        else if (carrera.ganadorC()=='e')
            cout << "Error en carrera." << endl;
        else
            cout << "Error en ganador." << endl;

        cout << "\n\nQuieres volver a intentarlo? (si/no) ";
        cin >> respuesta;
        if (respuesta[0]=='s')
            cout << endl << endl << endl;
    }while (respuesta[0]=='s');

    return 0;
}
