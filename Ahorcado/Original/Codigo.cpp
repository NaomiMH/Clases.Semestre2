#include <string>
#include <iostream>
#include "Ahorcado.h"

using namespace std;

///Todas las palabras tienen 7 caracteres
string palabras[] = {"sandias", "manzana", "papayas", "melones","naranja","durazno","platano"};

int main(){
   Ahorcado *ahorcado;
   string seguir, palabra;
   char letra;
   int pal = 0;  ///Indice de la palabra a adivinar
   do {
      palabra = palabras[pal++];  ///Toma la siguiente palabra del arreglo
      ahorcado = new Ahorcado(palabra);
      cout << "Adivina la palabra!" << endl;
      ahorcado->muestraEscenario();
      while (ahorcado->continuarJuego()) {
         cout << "Dame una letra: ";
         cin >> letra;
         ahorcado->validaIntento(letra);
         ahorcado->muestraEscenario();
      }

      if(ahorcado->ganoJuego())
         cout << "Felicidades!!! Adivinaste la palabra!!!"<< endl;
      else
         cout << "Lo siento. La palabara era: " << palabra << endl;

      delete ahorcado; ///Destruye la instancia de ahorcado

      cout << "\nDeseas jugar de nuevo? s/n"<< endl;
      cin >> seguir;
   } while(seguir == "s");

   return 0;
}
/* EJERCICIO:
       Modifica el programa para que tome la lista de palabras de diferentes longitudes desde el archivo "palabras.txt".
       No sabemos cuantas palabras contiene el archivo.
       La longitud máxima de una palabra sería 15.
       Una secuencia distinta de numeros aleatorios puede establecerse con: srand (time(NULL)).
       En cada ocasión, la palabra debe seleccionarse al azar (rand() % listSize).
       La cantidad de intentos fallidos debe mantenerse siempre en 7.
       No debe repetirse una misma palabra a un jugador en la sesión.
*/
