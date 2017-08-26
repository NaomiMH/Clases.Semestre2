#ifndef CPU_H
#define CPU_H

using namespace std;

#include <iostream>
#include <fstream>
#include <string>

class CPU
{
    public:
        CPU(string);
        void leerArch();
        void trans();
        void ejec();

    private:
        int variables[10],codigo[20]={0},cont,cant,PC,AC,IR;
        string lineas[20],nombre,dato;
        ifstream archE;
};

#endif // CPU_H
