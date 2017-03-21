/**
 * Naomi Macias Honti a01282098
 * 28 de febrero 2017
 * 2 hr 30 min.
 * Recibe el nombre de un archivo cpp y hace la documentacion del archivo en otro con formato html.
 */
 #include <iostream>
 #include <fstream>

using namespace std;

#include "Documentacion.h"

int main()
{
    string respuesta;
    Documentacion documento;
    documento.crearArchivo();
    documento.llenarinformacion();
    return 0;
}
