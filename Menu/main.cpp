/**
 * Naomi Macias Honti a01282098
 * 31 de enero 2017
 * 55 lineas mas 7 de comentarios. 62 en total.
 * 27 min.
 * Lee un archivo xml de comida y precios y muestra los de determinado tipo.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    ifstream ArchEntr;
    ArchEntr.open("SinNombre.xml");

    string slinea;
    getline(ArchEntr,slinea);
    getline(ArchEntr,slinea);
    getline(ArchEntr,slinea);

    int iborrar;
    string snombre, stipo, sprecio, sbuscar;

    sbuscar="Europeo";
    cout << "Tipo: " << sbuscar << endl << endl;

    while(!ArchEntr.eof()){
        getline(ArchEntr,slinea);

        iborrar=slinea.find(">");
        slinea.erase(0,iborrar+1);
        iborrar=slinea.find("</");
        snombre=slinea.substr(0,iborrar);

        getline(ArchEntr,slinea);

        iborrar=slinea.find(">");
        slinea.erase(0,iborrar+1);
        iborrar=slinea.find("</");
        stipo=slinea.substr(0,iborrar);

        getline(ArchEntr,slinea);

        iborrar=slinea.find(">");
        slinea.erase(0,iborrar+1);
        iborrar=slinea.find("</");
        sprecio=slinea.substr(0,iborrar);

        if(stipo==sbuscar){
            cout << "Nombre: " << snombre << endl << "Precio: " << sprecio << endl << endl;
        }
        getline(ArchEntr,slinea);
        getline(ArchEntr,slinea);
    }
    return 0;
}
