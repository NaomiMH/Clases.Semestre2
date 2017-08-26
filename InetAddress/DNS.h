#ifndef DNS_H
#define DNS_H

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include "InetAddress.h"

class DNS
{
    public:
        DNS();
        virtual ~DNS();

        void leerArchivo();
        void escrArchivo();

        void mostInAd();
        void obtIP();
        void obtHost();
        void busHost();
        void busIP();

        void menu();
        void agregar();
        void eliminar();
        void cambiarHost();
        void cambiarIP();
        void modInAd();

    private:
        InetAddress *ia[100];
        ofstream archivoS;
        ifstream archivoE;
        int cont,cant;
        string resp;
        bool admin=false;
};

#endif // DNS_H
