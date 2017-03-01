#ifndef ALUMNO_H
#define ALUMNO_H


class Alumno
{
    public:
        Alumno();
        void escribirDatos(string, string&, string&, string&, string&);
        void escribirDocumento(ofstream&,string, string, string, string);
        bool comprobarDatos(string, string);
        void escribirArchivo(ofstream&,string,string,string,string);

    private:
        int posicion, contador;
        string dato, palabraC,respuesta;
};

#endif // ALUMNO_H
