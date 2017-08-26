/**
 * Naomi Macias Honti a01282098
 * 17 de enero 2017
 * 87 lineas mas 7 de comentarios. 94 en total.
 * 43 min.
 * Comienza una secuencia aleatoria de 3 'V's las cuales van bajando renglon por renglon hasta desaparecer, esto se repite hasta presionar 'q'.
 */
#include <iostream>
#include <cstdlib>
#include <thread>
#include <conio.h>

using namespace std::chrono;
using namespace std;
const int iR=20;
const int iC=30;

void LlenarTabla(char (&array)[iR][iC])
{
    int icol;
    for (int icont=0;icont<iR;icont++)
    {
        for (int icont=0;icont<3;icont++)
        {
            icol=rand()%iC;
            (array)[0][icol]= 'V';
        }
    }
}

void BajarRenglon(char (&array)[iR][iC])
{
    for (int iren=iR-1; iren>0; iren--)
    {
        for (int icol=0; icol<iC; icol++)
        {
            (array)[iren][icol]= (array)[iren-1][icol];
        }
    }
}

void LlenarRenglon(char (&array)[iR][iC])
{
    int icol;
    for (int icontc=0; icontc<iC; icontc++)
    {
        (array)[0][icontc]=' ';
    }

    for (int icont=0;icont<3;icont++)
    {
        icol=rand()%iC;
        (array)[0][icol]= 'V';
    }
}

void Desplegar(char (&array)[iR][iC])
{
    for (int iren=0; iren<iR; iren++)
    {
        for (int icol=0; icol<iC; icol++)
        {
            cout << (array)[iren][icol];
        }
        cout << endl;
    }
}

int main()
{
    char cArr[iR][iC]={ { } };
    char ctec;

    cout << "Presiona 'q' en cualquier momento para terminar" << endl;
    this_thread::sleep_for(milliseconds{2000});
    system("cls");

    LlenarTabla(cArr);

    do{
        LlenarRenglon(cArr);
        BajarRenglon(cArr);
        Desplegar(cArr);

        this_thread::sleep_for(milliseconds{1000});
        if (kbhit())
            ctec=toupper(getch());
        system("cls");
    }while (ctec!='Q');

    system("cls");
    return 0;
}
