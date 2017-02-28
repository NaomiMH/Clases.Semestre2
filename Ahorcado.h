#ifndef AHORCADO
#define AHORCADO

#include <string>
#include <iostream>

using namespace std;

///El programa termina cuando se cometen 7 fallos
class Ahorcado{
    public:
        Ahorcado();
        void iniciar(string);
        void mostrarEscenario();
        void comprobarLetra(char);
        int estadoJuego();

    private:
        string palabra, intentosL;
        int palabraN, encontradas, fallos, contador;
};

#endif //AHORCADO
