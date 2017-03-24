/**
 * Naomi Macias Honti a01282098
 * 22 de marzo 2017
 * Tiempo no estimado.
 * Lee Matrices de un archivo, utiliza sobrecarga de operadores y escribe los resultados en otro archivo.
 */

//Operaciones entre matrices cuadradas A y B: suma, resta, transpuesta, multiplicación
//Sobrecarga de operadores: + - * >> <<
//Constructores con parametros default

#include <iostream>
#include <fstream>

using namespace std;

#include "Matrices.h"

int main()
{
    ifstream archivoE;
    ofstream archivoS;
    archivoE.open("matrices.txt");

    Matrices A;
    Matrices B(20);
    Matrices C;

    archivoS.open("resultado.txt");

    archivoE >> A;
    archivoE >> B;

    archivoS << "Matriz A" << endl;
    archivoS << A;

    archivoS << "Matriz B" << endl;
    archivoS << B;

    C = A + B;
    archivoS << "Resultado de la suma de matrices cuadradas A+B" << endl;
    archivoS << C;

    C = B - A;
    archivoS << "Resultado de la resta de matrices cuadradas B-A" << endl;
    archivoS << C ;

    C = A.transpuesta();
    archivoS << "Resultado de la matriz transpuesta de A" << endl;
    archivoS << C ;

    C = A * B;
    archivoS << "Resultado de la multiplicacion de matrices cuadradas A*B" << endl;
    archivoS << C ;

    archivoE.close();
    archivoS.close();
    return 0;
}
