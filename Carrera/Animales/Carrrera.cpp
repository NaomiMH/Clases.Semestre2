#include "Carrrera.h"

Carrrera::Carrrera()
{
    cantidad=3;
    margen=10;
    int cont=0;
    while(cont<cantidad){
        if(cont%3==0)
            animales[cont]= new Caballo("Caballo");
        else if(cont%3==1)
            animales[cont]= new Jirafa("Jirafa");
        else if(cont%3==2)
            animales[cont]= new Camello("Camello");
        cont++;
    }
}

Carrrera::~Carrrera()
{
    int cont=0;
    while(cont<cantidad){
        delete animales[cont];
        cont++;
    }
}

void Carrrera::carrera()
{
    int cont=0;
    while(cont<cantidad){
        animales[cont]-> avanzar(margen);
        cont++;
    }
}

bool Carrrera::ganadorB()
{
    int cont=0;
    bool estado=false;
    while(!estado && cont<cantidad){
        if(animales[cont]->ganador())
            estado=true;
        cont++;
    }
    if(estado){
        ganador=cont-1;
        return true;
    }
    return false;
}

string Carrrera::ganadorN()
{
    return animales[ganador]->obtNom();
}
