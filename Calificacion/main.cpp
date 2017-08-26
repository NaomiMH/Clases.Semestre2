/**
 * Naomi Macias Honti a01282098
 * 27 de enero 2017
 * 34 lineas mas 7 de comentarios. 41 en total.
 * 35 min.
 * Lee datos de un archivo externo y muestra el promedio por renglon.
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    ifstream ArchEntr;
    ArchEntr.open("saep-2016.csv");

    string slinea;
    getline(ArchEntr,slinea);

    int isum, inum, icant;
    double dprom;

    while(!ArchEntr.eof()){
        icant=0;
        isum=0;
        while(slinea.length()>0){
            inum=atoi(slinea.c_str());
            icant++;
            isum=isum+inum;
            slinea.erase(0,2);
        }
        dprom=isum*1.0/icant;
        cout << "prom " << dprom << endl;
        getline(ArchEntr,slinea);
    }
    return 0;
}
