#include <iostream>
#include <iomanip>

using namespace std;

#include "Reloj.h"

Reloj::Reloj()
{
    hr=0;
    minutos=0;
    sec=0;
}

void Reloj::setTime(int h, int m, int s) {
   hr = h;
   minutos = m;
   sec = s;
}

void Reloj::printTime() const {
   cout << setfill('0') << std::setw (2);
   cout << hr << ":" << minutos << ":" << sec << endl;
}

void Reloj::getTime(int& hr, int& minutos, int& sec) const {
   hr  = this->hr;
   minutos = this->minutos;
   sec = this->sec;
}

bool Reloj::equalTime(const Reloj& r) const {
   return (hr  == r.hr) &&
          (minutos == r.minutos) &&
          (sec == r.sec);
}

void Reloj::incrementHours(){
   hr = (hr + 1) % 24;
}

void Reloj::incrementMinutes() {
   if (minutos == 59)
      incrementHours();
   minutos = (minutos + 1) % 60;
}

void Reloj::incrementSeconds(){
   if (sec == 59)
      incrementMinutes();
   sec = (sec + 1) % 60;
}
