/**
 * Naomi Macias Honti a01282098
 * 11 de marzo 2017
 * Tiempo no estimado.
 * 1. Implementa la clase Triangulo, 2. y la clase PiramideRegular, despliega los resultados y 3. Se da un resultado en la pantalla que se tiene que adivinar.
 */
 #include <iostream>

using namespace std;

#include "Triangulo.h"
#include "PiramideRegular.h"

int main() {
    //Implementar la clase Triangulo
    cout << "Ejercicio 1." << endl;
    Triangulo *triangulo[3];
    int cont=0;
    while(cont<3){
    triangulo[cont]= new Triangulo(10.5);
    if(cont==0){
        cout << "Triangulo" << endl;
        cout << "Base: " << triangulo[cont]->obtBase() << endl;
        cout << "Altura: " << triangulo[cont]->obtAltura() << endl;
        cout << "Perimetro: " << triangulo[cont]->perimetro() << endl;
        cout << "Area: " << triangulo[cont]->area() << endl;
        cout << endl;

        //Implementar la clase PiramideRegular
        cout << "Ejercicio 2." <<endl;
        PiramideRegular pir(triangulo[cont]->obtBase(),triangulo[cont]->obtAltura());
        cout << "Area de la piramide: " << pir.area(triangulo[cont]) << endl;
    }
    cont++;
    delete triangulo[cont];
    }
    cout << endl;
    //Intentar adivinar la respuesta.
    cout << "Ejercicio 3." << endl << "Respuesta:" << endl;
    int y = 15, *p, *q;
    p = new int (10);
    q = &y;
    cout << *p << " " << *q <<endl;
    *q = 6;
    q = p;
    *p = 2;
    cout << *p << " " << *q <<endl;
    cout << y <<endl;
    q = new int(11);
    y++;
    *p = *p - 1;
    cout << *p <<" " << *q <<endl;
    cout << y << endl;
    return 0;
}
