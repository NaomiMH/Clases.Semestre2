#include <iostream>
#include <fstream>

using namespace std;

#include "Cuenta.h"

int main()
{
    int cantidad=0;
    unsigned long int cuenta;
    ifstream archivoE;
    ofstream archivoS;
    string datos, respuesta;
    int contador;
    bool estado=false;

    Cuenta *Cinventario[20];

    archivoE.open("CuentasBancarias.csv");

    getline(archivoE,datos);

    while(!archivoE.eof())
    {
        Cinventario[cantidad]= new Cuenta;
        getline(archivoE,datos);
        Cinventario[cantidad]->leerCuenta(datos);
        cantidad++;
    }
    archivoE.close();

    cout << "Numero de cuenta: (solo hasta ocho digitos) ";
    cin >> cuenta;
    contador=0;
    while(estado==false && contador<cantidad){
        if (Cinventario[contador]->checar(cuenta))
            estado=true;
        else
            estado=false;
        contador++;
    }
    if (estado){
        cout << "La cuenta existe." << endl;
        cout << "Su saldo es de $" << Cinventario[contador]->cheSaldo() << endl;
        cout << "Desea depositar o retirar? " << endl;
        cin >> respuesta;
        if(respuesta[0]=='d'){
            Cinventario[contador]->depositar();
            Cinventario[contador]->actualizarFecha();
        }
        else if (respuesta[0]=='r'){
            Cinventario[contador]->extraer();
            Cinventario[contador]->actualizarFecha();
        }
        else
            cout << "Error de instruccion.";
    }
    else{
        cout << "La cuenta no existe." << endl;
        cout << "Quiere crear una cuenta? (si/no) ";
        cin >> respuesta;
        if(respuesta[0]=='s'){
            Cinventario[cantidad]= new Cuenta;
            Cinventario[cantidad]->crearCuenta(cuenta);
            cantidad++;
        }
    }
    contador=0;
    archivoS.open("CuentasBancarias.csv");
    archivoS<<"Nombre;Cuenta Bancaria;Saldo;Ultimo movimiento" << endl;
    while(contador<cantidad){
        Cinventario[contador]->actualizarInformacion(archivoS);
        delete Cinventario[contador];
        contador++;
        if(contador<cantidad)
            archivoS<< endl;
    }
    archivoS.close();
    return 0;
}
