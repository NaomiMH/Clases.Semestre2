#ifndef PIRAMIDEREGULAR_H
#define PIRAMIDEREGULAR_H

using namespace std;

#include "Triangulo.h"

class PiramideRegular
{
    public:
        PiramideRegular();
        PiramideRegular(double base, double costado);
        double area(Triangulo *tri);
    private:
        double longBase, longCostado, areaBase, areaTotal;

};

#endif // PIRAMIDEREGULAR_H
