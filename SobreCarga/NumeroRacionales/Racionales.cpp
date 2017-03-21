#include "Racionales.h"

Racionales operator + (const Racionales& ab, const Racionales& cd)
{
    //suma: a/b + c/d  se define como (a * d + b * c) / (b * d)
    Racionales res;
    res.a= (ab.a * cd.b) + (ab.b * cd.a);
    res.b= (ab.b * cd.b);
    return res;
}

Racionales operator - (const Racionales& ab, const Racionales& cd)
{
    //resta: a/b - c/d  se define como (a * d - b * c) / (b * d)
    Racionales res;
    res.a= (ab.a * cd.b) - (ab.b * cd.a);
    res.b= (ab.b * cd.b);
    return res;
}

Racionales operator * (const Racionales& ab, const Racionales& cd)
{
    //multiplicación: (a/b) * (c/d)  se define como (a * c) / (b * d)
    Racionales res;
    res.a= (ab.a * cd.a);
    res.b= (ab.b * cd.b);
    return res;
}

Racionales operator / (const Racionales& ab, const Racionales& cd)
{
    //division: (a/b) / (c/d) => (a * d) / (c * b)
    Racionales res;
    res.a= (ab.a * cd.b);
    res.b= (ab.b * cd.a);
    return res;
}

bool operator < (const Racionales& ab, const Racionales& cd)
{
    //menorQue: (a/b) < (c/d) se define como (a * d) < (c * b)
    return ((ab.a * cd.b) < (ab.b * cd.a));
}

bool operator == (const Racionales& ab, const Racionales& cd)
{
    //igualA: (a/b) == (c/d) se define como (a * d) == (c * b)
    return ((ab.a * cd.b) == (ab.b * cd.a));
}

ostream& operator <<(ostream& salida, const Racionales& num)
{
    salida << num.a << "/" << num.b;
    return salida;
}
