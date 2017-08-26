#include <iostream>

using namespace std;

#include "Ensamblador.h"
#include "CPU.h"

int main()
{
    string resp;
    cout << "Nombre del documento: ";
    cin >> resp;
    {
        Ensamblador doc(resp);
        doc.crearCod();
        doc.escrArch();
    }
    cout << "Recuperando." << endl;
    CPU doc2(resp);
    doc2.leerArch();
    doc2.trans();
    doc2.ejec();
    return 0;
}
