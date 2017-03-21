#ifndef RACIONALES_H
#define RACIONALES_H
#include <iostream>

using namespace std;

class Racionales
{
    public:
        Racionales(){a=b=0;}
        Racionales(double a2, double b2){a=a2;b=b2;}

        friend Racionales operator + (const Racionales& ab, const Racionales& cd);
        friend Racionales operator - (const Racionales& ab, const Racionales& cd);
        friend Racionales operator * (const Racionales& ab, const Racionales& cd);
        friend Racionales operator / (const Racionales& ab, const Racionales& cd);
        friend bool operator < (const Racionales& ab, const Racionales& cd);
        friend bool operator == (const Racionales& ab, const Racionales& cd);

        friend ostream& operator <<(ostream& outs, const Racionales& num);
    private:
        double a, b;
};

#endif // RACIONALES_H
