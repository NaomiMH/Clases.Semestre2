#include <iostream>

using namespace std;

#include <windows.h>
#include <fstream>
#include "Banda.h"
#include "Estacion.h"

ifstream archE;
string instrucciones[20];
int cant;
Banda C(70);
Banda T(40);
Estacion S();

void leerInstr()
{
    string linea;
    getline(archE,linea);
    int cont=0, pos;
    while(linea!=""){
        pos=linea.find(">");
        instrucciones[cont]=linea.substr(0,pos);
        cont++;
        if(pos!=-1)
            linea.erase(0,pos+1);
        else
            linea="";
    }
    cant=cont;
}

void proceso()
{
    int cont=0;
    string ins;
    while(cont<cant){
        ins=instrucciones[cont];
        if(ins[0]=='C')
            C.info(ins);
        else if(ins[0]=='T')
            T.info(ins);
        else
            S.instr(ins);
        cont++;
    }
}

int main()
{
    archE.open("simulacion.txt");
    leerInstr();
    proceso();
    return 0;
}
