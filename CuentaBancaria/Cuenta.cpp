#include "Cuenta.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Cuenta::Cuenta()
{

}

void Cuenta::leerCuenta(string datos)
{
    unsigned long int multiplo=1;
    posicion=datos.find(";");
    nombre=datos.substr(0,posicion);
    datos.erase(0,posicion+1);
    posicion=datos.find(";");
    dato=datos.substr(0,posicion);
    contador=dato.length()-1;
    numero=0;
    while(contador>=0){
        numero=numero+(dato[contador]-48)*multiplo;
        multiplo=multiplo*10;
        contador--;
    }
    datos.erase(0,posicion+1);
    posicion=datos.find(";");
    dato=datos.substr(0,posicion);
    contador=dato.length()-1;
    saldoC=0;
    multiplo=1;
    while(contador>=0){
        if (contador!=dato.length()-3){
            saldoC=saldoC+(dato[contador]-48)*multiplo;
        }
        multiplo=multiplo*10;
        contador--;
    }
    datos.substr(0,posicion+1);
    fechaC=datos;
}

void Cuenta::extraer()
{
    string cantidad;
    unsigned long int dinero, multiplo;
    cout << "Cantidad a retirar? ($####.##) $";
    cin >> cantidad;
    contador=cantidad.length()-1;
    dinero=0;
    multiplo=1;
    while(contador>=0){
        if (contador!=cantidad.length()-3){
            dinero=dinero+(cantidad[contador]-48)*multiplo;
        }
        multiplo=multiplo*10;
        contador--;
    }
    if (dinero<=saldoC){
        cout << "El dinero sera retirado." << endl;
        saldoC=saldoC-dinero;
    }
    else{
        cout << "La cuenta no tiene el saldo suficiente." << endl;
    }
}

void Cuenta::depositar()
{
    string cantidad;
    unsigned long int dinero,multiplo;
    cout << "Cantidad a depositar? ($####.##) $";
    cin >> cantidad;
    contador=cantidad.length()-1;
    dinero=0;
    multiplo=1;
    while(contador>=0){
        if (contador!=cantidad.length()-3){
            dinero=dinero+(cantidad[contador]-48)*multiplo;
        }
        multiplo=multiplo*10;
        contador--;
    }
    cout << "El dinero sera depositado en su cuenta." << endl;
}

bool Cuenta::checar(unsigned long int cuentaN)
{
    if (numero==cuentaN)
        return true;
    else
        return false;
}

string Cuenta::cheSaldo()
{
    string saldoF;
    char cara;
    saldoF="";
    contador=0;
    int saldo=saldoC;
    while(saldo!=0){
        if (contador!=2)
            cara=(saldo%10)+48;
        else
            cara='.';
        saldo/=10;
        contador++;
        saldoF=cara+saldoF;
    }
    return saldoF;
}

void Cuenta::actualizarFecha()
{
    string mes,dia,ano;
    fechaC="";
    cout << "Introducir dia: ";
    cin >> dia;
    cout << "Introducir mes: ";
    cin >> mes;
    cout << "Introducir ano: ";
    cin >> ano;
    fechaC=dia+ " " + mes + " de " + ano;
}

void Cuenta::crearCuenta(unsigned long int cuentaN)
{
    string saldoI;
    unsigned long int multiplo;
    numero=cuentaN;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Salod inicial: ($####.##) $";
    cin >> saldoI;
    contador=saldoI.length()-1;
    saldoC=0;
    multiplo=1;
    while(contador>=0){
        if (contador!=saldoI.length()-3){
            saldoC=saldoC+(saldoI[contador]-48)*multiplo;
        }
        multiplo=multiplo*10;
        contador--;
    }
    actualizarFecha();
    cout << "La cuenta ha sido creada." << endl;
}

void Cuenta::actualizarInformacion(ofstream& archivo)
{
    archivo<<nombre<< ";" << numero << ";" << cheSaldo() << ";" << fechaC;
}
