#include "Carrera.h"

Carrera::Carrera()
{

}

void Carrera::limpiarPista()
{
    contador=0;
    while(contador<70){
        pistaL[contador]='-';
        pistaT[contador]='-';
        contador++;
    }
}

void Carrera::escenario()
{
    contador=0;
    while(contador<70){
        cout << pistaL[contador];
        contador++;
    }
    cout << endl;
    contador=0;
    while(contador<70){
        cout << pistaT[contador];
        contador++;
    }
    cout << endl;
    if (liebre.empate())
        cout << "OUCH!!!" << endl;
}

bool Carrera::ganadorB()
{
    if(liebre.posicionP()==70 || tortuga.posicionP()==70)
        return true;
    else
        return false;
}

char Carrera::ganadorC()
{
    if (liebre.posicionP()==70 && tortuga.posicionP()==70)
        return 'a';
    else if (liebre.posicionP()==70)
        return 'l';
    else if (tortuga.posicionP()==70)
        return 't';
    else
        return 'e';
}

void Carrera::avanzar()
{
    limpiarPista();
    posicion=tortuga.avanzando();
    pistaT[posicion-1]='T';
    posicion=liebre.avanzando(posicion);
    pistaL[posicion-1]='L';
}

void Carrera::reiniciar()
{
    limpiarPista();
    liebre.reiniciar();
    tortuga.reiniciar();
}
