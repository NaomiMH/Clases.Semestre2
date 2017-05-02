/**
 * Naomi Macias Honti a01282098
 * 17 de febrero 2017
 * Tiempo no estimado.
 * Uso de la clase Reloj.h.
 */
#include <iostream>

using namespace std;

#include "Reloj.h"

int main() {
   Reloj miReloj;
   miReloj.setTime(4,30,0);
   miReloj.printTime();
   miReloj.incrementMinutes();
   miReloj.printTime();
   return 0;
}
