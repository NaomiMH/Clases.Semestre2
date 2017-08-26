/**
 * Naomi Macias Honti a01282098
 * 25 de enero 2017
 * 74 lineas mas 7 de comentarios. 81 en total.
 * 48 min.
 * Lee un documento y crea dos archivos: en uno deja los numeros con sus comas correspondientes y en el otro deja el promedio de las calificaciones de los alumnos.
 */
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void PonerComas ()
{
    ifstream ArchEntr;
    ArchEntr.open("numero.txt");
    ofstream ArchSal;
    ArchSal.open("resultados.txt");

    string numero;
    int longi, div, cant, inic;

    do{
        ArchEntr >> numero;
        longi=numero.length();
        cant=longi%3;
        if(cant>0 && longi>3){
            ArchSal<< numero.substr(0,cant) << ",";
        }
        else{
            ArchSal<< numero.substr(0,longi) << endl;
        }
        inic=longi-(longi-cant);
        for (div=longi/3;div-1>0 && longi>3 ;div--){
            ArchSal<< numero.substr(inic,3)<< ",";
            inic=inic+3;
        }
        if (longi>3)
            ArchSal<< numero.substr(inic,3)<< endl;
    }while(!ArchEntr.eof());

    ArchSal.close();
}

void Calificaciones()
{
    const int cantT=5;

    ifstream ArchEntr;
    ArchEntr.open("matricula.txt");
    ofstream ArchSal;
    ArchSal.open("resultados2.txt");

    int mat, cant, calT, cal;
    double prom;

    do{
        ArchEntr >> mat;
        ArchSal << mat << " ";

        ArchEntr >> cant;
        calT=0;
        for (int cont=1; cont<=cant; cont++){
            ArchEntr>>cal;
            calT+=cal;
        }
        prom=calT*1.0/cantT;
        ArchSal << prom << endl;
    }while(!ArchEntr.eof());

    ArchSal.close();
}

int main()
{
    PonerComas();
    Calificaciones();
    return 0;
}
