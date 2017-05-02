#include "Alumno.h"

Alumno::Alumno():Persona()
{
    calificaciones[0]=80;
    calificaciones[1]=55;
    calificaciones[2]=60;
    calificaciones[3]=100;
    calificaciones[4]=90;
}

Alumno::Alumno(int cal1,int cal2, int cal3, int cal4, int cal5,string nom, string dir, string ema):Persona(nom,dir,ema)
{
    calificaciones[0]=cal1;
    calificaciones[1]=cal2;
    calificaciones[2]=cal3;
    calificaciones[3]=cal4;
    calificaciones[4]=cal5;
}

Alumno::~Alumno()
{
    cout << "destructor alumno" << endl;
}

void Alumno::setCalif(int con, int cal)
{
    calificaciones[con]=cal;
}

int Alumno::getProm()
{
    int prom=0, cont=0;
    while(cont<5){
        prom=prom+calificaciones[cont];
        cont++;
    }
    prom=prom/5;
    return prom;
}

void Alumno::print()
{
    cout << "Soy un alumno" << endl;
}
