/**
 * Naomi Macias Honti a01282098
 * 10 de febrero 2017
 * 121 lineas mas 7 de comentarios. 128 en total.
 * 2 hr 1 min.
 * Lee un archivo con posiciones de asientos, recibe una posicion del cliente y reserva la posicion con una X, guarda los cambios al salir.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

void llenar(fstream &archivo, char asientos[7][20])
{
    char dato;
    int renglon=0;
    while(renglon<7){
        archivo>>dato;
        for (int cont=0; cont<19; cont++){
            archivo>>dato;
            asientos[renglon][cont]=dato;
        }
        renglon++;
    }
}

void regresar(char asientos[7][20])
{
    ofstream archivo;
    archivo.open("JB02142017.txt");
    for (int cont=0;cont<7;cont++)
    {
        archivo<<cont+1<<" ";
        for(int cont2=0;cont2<19;cont2++)
        {
            archivo<< asientos[cont][cont2] << " ";
        }
        archivo<<endl;
    }
    archivo.close();
}

void cambiar(char asientos[7][20],string respuesta)
{
    int numero,columna;
    char letra;
    switch (respuesta[0]){
    case '1':numero=0;break;
    case '2':numero=1;break;
    case '3':numero=2;break;
    case '4':numero=3;break;
    case '5':numero=4;break;
    case '6':numero=5;break;
    case '7':numero=6;break;
    default:numero=-1;break;
    }
    letra=toupper(respuesta[1]);
    switch (letra){
    case 'A':columna=0;break;
    case 'B':columna=1;break;
    case 'C':columna=2;break;
    case 'D':columna=3;break;
    case 'E':columna=4;break;
    case 'F':columna=5;break;
    case 'G':columna=6;break;
    case 'H':columna=7;break;
    case 'I':columna=8;break;
    case 'J':columna=9;break;
    case 'K':columna=10;break;
    case 'L':columna=11;break;
    case 'M':columna=12;break;
    case 'N':columna=13;break;
    case 'O':columna=14;break;
    case 'P':columna=15;break;
    case 'Q':columna=16;break;
    case 'R':columna=17;break;
    case 'S':columna=18;break;
    default: columna=-1;break;
    }
    if (columna==-1 || numero==-1)
        cout << "Error" << endl;
    else if (asientos[numero][columna]!='X'){
        asientos[numero][columna]='X';
        cout << "Se ha reservado con exito" << endl;}
    else
        cout << "El lugar esta ocupado" << endl;
}

void mostrar(char asientos[7][20])
{
    for (int cont=0;cont<7;cont++)
    {
        cout << cont+1 << " ";
        for(int cont2=0;cont2<19;cont2++)
        {
            cout << asientos[cont][cont2] << " ";
        }
        cout << endl;
    }
}

int main()
{
    fstream arch;
    arch.open("JB02142017.txt");

    char asientos[7][20]= {{'*'}};

    llenar(arch,asientos);

    string respuesta;
    do{
        mostrar(asientos);
        cout << "Que asiento quiere? ";
        cin >> respuesta;
        if (respuesta!="T"){
            cambiar(asientos,respuesta);
        }
    }while(respuesta!="T");

    arch.close();
    regresar(asientos);
    return 0;
}
