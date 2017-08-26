#ifndef ALUMNO_H
#define ALUMNO_H


class Alumno
{
    public:
        Alumno() {}
        Alumno(string n) {nombre=n;}
        ~Alumno() {}
        void imprime(){cout << "Nombre: " << nombre << endl;}

    private:
        string nombre;
};

#endif // ALUMNO_H
