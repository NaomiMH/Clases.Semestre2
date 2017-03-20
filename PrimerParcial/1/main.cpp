/**
 * Naomi Macias Honti a01282098
 * 7 de febrero 2017
 * 69 lineas mas 7 de comentarios. 76 en total.
 * 60 min.
 * Lee una matriz escrito en un txt, rota la matriz verticalmente y muestra la secuencia en pantalla.
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

void llenar(int matriz[20][20], int largo, ifstream &archivo)
{
    int linea;
    for(int cont2=0;cont2<largo;cont2++){
        for(int cont=0;cont<largo;cont++){
            archivo >> linea;
            matriz[cont2][cont]=linea;
        }
    }
}

void desplegar(int matriz[20][20], int largo)
{
    cout << endl;
    for(int cont=0;cont<largo;cont++){
        for(int cont2=0;cont2<largo;cont2++){
            cout << matriz[cont][cont2] << " ";
        }
        cout << endl;
    }
}

void bajarRenglon(int matriz[20][20],int largo)
{
    int arreg[20]={0};
    for(int cont=0;cont<largo;cont++){
        arreg[cont]=matriz[0][cont];
    }

    for(int cont2=1;cont2<largo;cont2++){
        for(int cont3=0;cont3<largo;cont3++){
            matriz[cont2-1][cont3]=matriz[cont2][cont3];
        }
    }

    for(int cont4=0;cont4<largo;cont4++){
        matriz[largo-1][cont4]=arreg[cont4];
    }
}

int main()
{

    ifstream archEntr;
    archEntr.open("matriz.txt");

    int largo, pos;
    largo=0;
    archEntr>>largo;

    int matriz[20][20]={{0}};

    llenar(matriz,largo,archEntr);

    for(int cont=0; cont<largo-1;cont++){
        bajarRenglon(matriz,largo);
        desplegar(matriz,largo);
    }

    return 0;
}
