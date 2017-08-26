/**
 * Naomi Macias Honti a01282098
 * 12 de enero 2017
 * 72 lineas mas 7 de comentarios. 79 en total.
 * Tiempo no estimado.
 * Llena un cubo de 3x3 diagonalmente, contando desde 1 a 9, sin repetir lugar.
 */
#include <iostream>

using namespace std;

void Desplegar (int iMat[3][3], int N)
{
    cout << endl;
    for (int iR=0; iR<N; iR++)
    {
        for (int iC=0; iC<N; iC++)
        {
            cout << iMat[iC][iR]<< " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    const int iN=3;
    int iMat[iN][iN]= {0};
    int iC=iN%2;
    int iR=0;
    int inum=1;

    while(inum<10)
    {
        if (iC>iN-1)
        {
            iC=0;
        }
        else if (iC<0)
        {
            iC=iN-1;
        }
        if (iR<0)
        {
            iR=iN-1;
        }
        else if (iR>iN-1)
        {
            iR=0;
        }

        if (iMat[iC][iR]!=0)
        {
            iR++;
            if (iR<0)
            {
                iR=iN-1;
            }
            else if (iR>iN-1)
            {
                iR=0;
            }
            iR++;
            iC--;
        }
        else
        {
            iMat[iC][iR]=inum;
            inum++;
            iR--;
            iC++;
        }
    }

    Desplegar(iMat,iN);
    return 0;
}
