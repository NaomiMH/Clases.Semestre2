/**
 * Naomi Macias Honti a01282098
 * 21 de marzo 2017
 * 42 min.
 * Toma dos numeros racionales y los pasa por varias funciones sobrecargadas (+ - * / < == <<).
 */
#include <iostream>
#include "Racionales.h"

using namespace std;

int main()
{
    Racionales r1(3,4);
    Racionales r2(1,2);
    Racionales r3;

    cout << "Racional 1: ";
    cout << r1 << endl << endl;

    cout << "Racional 2: ";
    cout << r2 << endl << endl;

    r3= r1+r2;
    cout << "Suma: " << r3 << endl;

    r3= r1-r2;
    cout << "Resta: " << r3 << endl;

    r3= r1*r2;
    cout << "Multiplicacion: " << r3 << endl;

    r3= r1/r2;
    cout << "Divicion: " << r3 << endl;

    if(r1<r2)
        cout << "Racional 1 es menor que Racional 2." << endl;
    else
        cout << "Racional 1 es mayor que Racional 2." << endl;

    if(r1==r2)
        cout << "Racional 1 y 2 son iguales." << endl;
    else
        cout << "Racional 1 y 2 son diferentes." << endl;

    return 0;
}
