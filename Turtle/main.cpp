/**
 * Naomi Macias Honti a01282098
 * 21 de abril 2017
 * Tiempo no estimado.
 * Lee un archivo con instrucciones para crear un dibujo en un arreglo que muestra y lo guarda las instrucciones (comentario pasos) en un archivo.
 */
#include <iostream>

using namespace std;

#include "Turtle.h"

int main() {
   Turtle turtle("solidGun.txt");
   int instr=0;

   turtle.clearArea() ; //Clear the drawing area
   while (instr != 9)
      instr = turtle.move();

   turtle.printArea();
   return 0;
}
