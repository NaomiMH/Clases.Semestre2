/**
@progName Funcion Factorial
@author Guillermo Jimenez
@date 20 de Enero de 2017
*/

#include <iostream>

using namespace std;

/**
@funcName factorial
@desc funcion que calcula el factorial de un numero
@param iNum valor al que se le va a encontrar el factorial. Debe ser entero positivo.
@return factorial del valor iNum
*/

int factorial(int iNum)
{
    int iFac=1;
    //Calculate the factorial with a FOR loop
    for (int iC=1; iC<=iNum; iC++){
        iFac = iFac*iC;
    }
    return iFac; //This value is returned to caller
}

/**
@funcName validaEntero
@desc Funcion que no recibe parametro, pide al usuario un valor y valida que sea entre 1 y 10
@return regresa un valor entero entre 1 y 10 que le pide al usuario
*/

int validaEntero()
{
    int iNum;
    do{
        cout << "Numero ";
        cin >> iNum;
    }while(iNum < 1 || iNum > 10);
    return iNum;
}

/**
@funcName main
*/

int main()
{
    int iNumero, iResult;
    iNumero = validaEntero();
    iResult = factorial(iNumero);
    cout << "Factorial = " << iResult << endl;
    return 0;
}
