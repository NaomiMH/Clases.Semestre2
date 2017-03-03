#ifndef CUENTA_H
#define CUENTA_H

#include <iostream>
#include <string>

using namespace std;

class Cuenta
{
    public:
        Cuenta();
        void leerCuenta(string);
        void extraer();
        void depositar();
        bool checar(unsigned long int);
        string cheSaldo();
        void actualizarFecha();
        void crearCuenta(unsigned long int);
        void actualizarInformacion(ofstream&);

    private:
        unsigned long int numero;
        string nombre, fechaC, dato;
        unsigned long int saldoC;
        int posicion, contador;
};

#endif // CUENTA_H
