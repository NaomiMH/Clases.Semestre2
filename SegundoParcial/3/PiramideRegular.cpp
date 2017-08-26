#include "PiramideRegular.h"

PiramideRegular::PiramideRegular()
{
    longBase=0;
    longCostado=0;
}

PiramideRegular::PiramideRegular(double base, double costado)
{
    longBase=base;
    longCostado=costado;
}

double PiramideRegular::area(Triangulo *tri)
{
    areaBase=longBase*longBase;
    areaTotal=areaBase+tri->area()*4;
    return areaTotal;
}
