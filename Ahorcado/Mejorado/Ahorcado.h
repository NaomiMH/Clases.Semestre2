#ifndef AHORCADO
#define AHORCADO

#include <string>
#include <iostream>

using namespace std;

class Ahorcado{
    public:
        void iniciar(string);
        void mostrarEscenario();
        void comprobarLetra(char);
        int estadoJuego();

    private:
        string palabra, intentosL;
        int palabraN, encontradas, fallos, contador;
};

#endif //AHORCADO
