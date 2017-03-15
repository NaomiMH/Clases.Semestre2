/**
 * Naomi Macias Honti a01282098
 * 20 de enero 2017
 * Tiempo no estimado.
 * Lee de un archivo dos matrices, procesa la suma, resta, multiplicacion y transpuestas de las matrices, las muestra en pantalla y guarda los resultados en un archivo.
 */
#include <iostream>
#include <fstream>

using namespace std;

void Desplegar(int iMat[20][20], int inum, ofstream &ArchSal)
{

    for(int icontR=0; icontR<inum; icontR++){
        for(int icontC=0; icontC<inum; icontC++){
            cout << iMat[icontR][icontC] << " ";
            ArchSal << iMat[icontR][icontC] << " ";
        }
        ArchSal << endl;
        cout << endl;
    }
}

void Suma(int iMat1[20][20], int inum, int iMat2[20][20], ofstream &ArchSal)
{
    int iMat3[20][20]={{0}};
    for(int icontR=0; icontR<inum; icontR++){
        for(int icontC=0; icontC<inum; icontC++){
            iMat3[icontR][icontC]=iMat1[icontR][icontC]+iMat2[icontR][icontC];
        }
    }
    Desplegar(iMat3, inum, ArchSal);
}

void Resta(int iMat1[20][20], int inum, int iMat2[20][20], ofstream &ArchSal)
{
    int iMat3[20][20]={{0}};
    for(int icontR=0; icontR<inum; icontR++){
        for(int icontC=0; icontC<inum; icontC++){
            iMat3[icontR][icontC]=iMat1[icontR][icontC]-iMat2[icontR][icontC];
        }
    }
    Desplegar(iMat3, inum, ArchSal);
}

void Transpuesta(int iMat[20][20], int inum, ofstream &ArchSal)
{
    int iMat2[20][20]={{0}};
    for(int icontR=0; icontR<inum; icontR++){
        for(int icontC=0; icontC<inum; icontC++){
            iMat2[icontR][icontC]=iMat[icontC][icontR];
        }
    }
    Desplegar(iMat2,inum, ArchSal);
}

void Multiplicacion(int iMat1[20][20], int inum, int iMat2[20][20], ofstream &ArchSal)
{
    int iMat3[20][20]={{0}};
    int isuma;
    for(int icont1=0;icont1<inum;icont1++){
        for(int icont2=0; icont2<inum;icont2++){
            isuma=0;
            for(int icont3=0;icont3<inum;icont3++){
                isuma=isuma+iMat1[icont2][icont3]*iMat2[icont3][icont2];
            }
            iMat3[icont1][icont2]=isuma;
        }
    }
    Desplegar(iMat3,inum, ArchSal);
}

int main()
{
    ifstream ArchEntr;
    ArchEntr.open("matrices.txt");
    ofstream ArchSal;
    ArchSal.open("resultados.txt");

    int iMatA[20][20]={{0}};
    int iMatB[20][20]={{0}};

    int inumA, inum;
    ArchEntr>>inumA;

    for(int icontR=0; icontR<inumA; icontR++){
        for (int icontC=0; icontC<inumA;icontC++){
            ArchEntr>> inum;
            iMatA[icontR][icontC]=inum;
        }
    }
    int inumB;
    ArchEntr>> inumB;
    for(int icontR=0; icontR<inumB; icontR++){
        for(int icontC=0; icontC<inumB; icontC++){
            ArchEntr>>inum;
            iMatB[icontR][icontC]=inum;
        }
    }
    ArchSal << "A\n";
    Desplegar(iMatA,inumA, ArchSal);
    cout << endl;
    ArchSal <<"\nB\n";
    Desplegar(iMatB,inumB, ArchSal);
    cout << endl;
    cout << "Suma\n";
    ArchSal << "\nSuma\n";
    Suma(iMatA,inumA,iMatB, ArchSal);
    cout << endl;
    cout << "Resta\n";
    ArchSal << "\nResta\n";
    Resta(iMatA,inumA,iMatB, ArchSal);
    cout << endl;
    cout << "Transpuesta\n";
    ArchSal << "\nTranspuesta\n";
    Transpuesta(iMatA,inumA, ArchSal);
    cout << endl;
    ArchSal << endl;
    Transpuesta(iMatB,inumB, ArchSal);
    cout << endl;
    cout << "Multiplicacion\n";
    ArchSal << "\nMultiplicacion\n";
    Multiplicacion(iMatA,inumA,iMatB, ArchSal);
    ArchSal.close();
    return 0;
}
