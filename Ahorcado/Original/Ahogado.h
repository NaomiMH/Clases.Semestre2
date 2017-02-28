///Programador: Guillermo Jimenez
///Fecha: Septiembre 2016

#ifndef AHORCADO
#define AHORCADO

#include <string>
#include <iostream>
using namespace std;

///Asume que la palabra tiene 7 caracteres
///El programa termina cuando se cometen 7 fallos
class Ahorcado{
public:
   Ahorcado(string palabra);
   bool ganoJuego(); ///Se adivinaron ya todas las letras?
   bool continuarJuego();///Se encontraron ya todas las letras o se cometieron 7 fallos?
   void validaIntento(char letra); ///Buscar todas las ocurrecias de la letra en la palabra
   void muestraEscenario();
private:
   string sPalabra;    ///La palabra a adivinar
   string sIntentadas; ///Cuales letras se han intentado
   string sx;         ///Muestra X en las letras aun no adivinadas
   int iEncontradas;   ///Total de letras encontradas hasta el momento
   int iFallos;        ///Total de fallos hasta el momento

};

#endif //AHORCADO
