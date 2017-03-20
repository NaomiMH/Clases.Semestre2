/**
 * Naomi Macias Honti a01282098
 * 7 de febrero 2017
 * 47 lineas mas 7 de comentarios. 54 en total.
 * 42 min.
 * Lee un archivo .csv, lee los datos y muestra la cantidad de alumnos inscritos en cada una de las diferentes materias.
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    ifstream archEntr;
    archEntr.open("alumnosEM2017.csv");

    string clases[20]={" "};
    int alumnos[20]={0};
    string linea;
    int coma;
    int numClases=0;
    bool exist;

    while(!archEntr.eof()){
        getline(archEntr,linea);
        coma=linea.find(",");
        linea.erase(0,coma+1);
        coma=linea.find(",");
        linea.erase(0,coma+1);
        exist=false;
        for(int cont=0;cont<numClases;cont++){
            if(clases[cont]==linea)
            {
                alumnos[cont]+=1;
                exist=true;
            }
        }
        if(!exist){
            clases[numClases]=linea;
            alumnos[numClases]+=1;
            numClases++;
        }
    }

    for(int cont=0;cont<numClases;cont++){
        cout<<clases[cont]<<" "<<alumnos[cont]<<endl;
    }

    return 0;
}
