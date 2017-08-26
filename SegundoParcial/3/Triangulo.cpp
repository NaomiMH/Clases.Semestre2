#include "Triangulo.h"
#include <cmath>

Triangulo::Triangulo()
{
    base=0;
    altura=0;
}

Triangulo::Triangulo(double num)
{
    altura=num;
    base=(2.0*altura)/(pow(3,1/2));
}

double Triangulo::perimetro()
{
    double per;
    per=base+base+base;
    return per;
}

double Triangulo::area()
{
    double are;
    are= (base*altura)/2.0;
    return are;
}

double Triangulo::obtBase()
{
    return base;
}

double Triangulo::obtAltura()
{
    return altura;
}
