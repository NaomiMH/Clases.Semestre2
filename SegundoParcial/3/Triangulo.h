#ifndef TRIANGULO_H
#define TRIANGULO_H


class Triangulo
{
    public:
        Triangulo();
        Triangulo(double);
        double perimetro();
        double area();
        double obtBase();
        double obtAltura();
    private:
        double base, altura;
};

#endif // TRIANGULO_H
