#ifndef ENSAMBLADOR_H
#define ENSAMBLADOR_H

using namespace std;

#include <iostream>
#include <fstream>
#include <string>

class Ensamblador
{
    public:
        Ensamblador(string);
        virtual ~Ensamblador();
        void crearCod();
        void agreLin(int,int);
        void quitLin(int,int);
        void cambIfWhi(int);
        void escrArch();

    private:
        string nombre,linea[20],IR;
        ifstream archivoE;
        ofstream archivoS;
        int cont,cant;
        char memC[10];
};

#endif // ENSAMBLADOR_H
