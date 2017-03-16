#include "Carrera.h"
#include "Caballos.h"

Carrera::Carrera(int numero)
{
    cantidad=numero;
}

void Carrera::agregarCaballo(Caballos *caballo, int cont)
{
    jugadores[cont]=caballo;
}

void Carrera::avanzar(const int margen)
{
    if(!ganador()){
        contador=0;
        while(contador<cantidad){
            jugadores[contador]->avanzar(margen);
            contador++;
        }
    }
    else
        cout << "No avanzo." << endl;
}

bool Carrera::ganador()
{
    contador=0;
    while(contador<cantidad){
        if(jugadores[contador]->obtPosicion()>=500){
            inum=contador;
            for(int cont2=contador; cont2<cantidad; cont2++){
                if(jugadores[cont2]->obtPosicion()>jugadores[contador]->obtPosicion() && jugadores[cont2]->obtPosicion()>jugadores[inum]->obtPosicion())
                    inum=cont2;
            }
            return true;
        }
        contador++;
    }
    return false;
}

void Carrera::terminar()
{
    cout << "Posiciones finales en la carrera: " << endl;
    for(contador=0;contador<cantidad;contador++)
    cout << "Caballo #" << contador+1 << "\t" << jugadores[contador]->obtNombre() << "\t" << jugadores[contador]->obtPosicion() << endl;
    cout << "El ganador es " << jugadores[inum]->obtNombre() << endl;
}

void Carrera::borrarCaballos()
{
    contador=0;
    while(contador<cantidad){
        delete jugadores[contador];
        contador++;
    }
}
