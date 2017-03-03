/**
 * Naomi Macias Honti a01282098
 * 17 de enero 2017
 * 59 lineas mas 7 de comentarios. 66 en total.
 * 27 min.
 * Recibe una velocidad y calcula el tiempo y la distancia con la que caera el objeto, si llega cerca a 3 metros atrapas el pokemon.
 */
#include <iostream>
#include <cmath>

using namespace std;

const int ialt=2;
const double dgrav=9.81;
const int idis=3;

double SacarTiempo()
{
    double dtiem;
    dtiem=sqrt(2*ialt/dgrav);
    return dtiem;
}

double SacarDistancia(double dtiem, double dvel)
{
    double ddis;
    ddis=dtiem*dvel;
    return ddis;
}

int main()
{
    double dvel, ddis, dtiem;
    dtiem=SacarTiempo();
    bool bsal=true;

    do{
        cout << "Velocidad: ";
        cin >> dvel;

        ddis=SacarDistancia(dtiem,dvel);

        for (double dcont=ddis/11; dcont<=ddis; dcont+=(ddis/11))
        {
            cout << "\nPosicion: " << dcont << endl;
        }

        if (ddis>idis-0.1 && ddis<idis+0.1)
        {
            cout << "\nFelicidades le has dado al pokemon" << endl;
            bsal=false;
        }
        else if (ddis>idis+0.1)
        {
            cout << "\nFallaste el pokemon esta DESPUES" << endl;
        }
        else if (ddis<idis-0.1)
        {
            cout << "\nFallaste el pokemon esta Antes" << endl;
        }
        cout << endl << endl;
    }while (bsal);

    return 0;
}
