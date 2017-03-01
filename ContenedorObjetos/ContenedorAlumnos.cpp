#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>

using namespace std;

#include "ContenedorAlumnos.h"
#include "Alumno.h"

string nombre[100]={" "};
string matricula[100]={" "};
string carrera[100]={" "};
string correo[100]={" "};

ContenedorAlumnos::ContenedorAlumnos()
{
    dato="";
    cantidad=0;
}

void ContenedorAlumnos::enviarDatos()
{
    ofstream archivo;
    archivo.open("informacion.txt");
    contador=0;
    while(contador<cantidad)
    {
        datos.escribirDocumento(archivo,nombre[contador],matricula[contador],carrera[contador],correo[contador]);
        contador++;
    }
    archivo.close();
}

void ContenedorAlumnos::cargarDatos(ifstream &archivo)
{
    while(!archivo.eof()){
        cantidad++;
        getline(archivo,dato);
        datos.escribirDatos(dato, nombreP, matriculaP, carreraP, correoP);
        matricula[cantidad-1]=matriculaP;
        nombre[cantidad-1]=nombreP;
        carrera[cantidad-1]=carreraP;
        correo[cantidad-1]=correoP;
    }
}

void ContenedorAlumnos::buscarDatos(string palabra, string parametro)
{
    contador=0;
    inicial=toupper(parametro[5]);
    int posiciones[100]={0};
    error=0;
    contador2=0;

    while(contador<cantidad)
    {
        switch (inicial)
        {
        case 'E':{
            if (datos.comprobarDatos(palabra,nombre[contador])){
                posiciones[contador2]=contador;
                contador2++;
            }
            break;
        }
        case 'R':{
            if (datos.comprobarDatos(palabra,carrera[contador])){
                posiciones[contador2]=contador;
                contador2++;
            }
            break;
        }
        case 'C':{
            if (datos.comprobarDatos(palabra,matricula[contador])){
                posiciones[contador2]=contador;
                contador2++;
            }
            break;
        }
        default:{error=1; break;}
        }
        contador++;
    }
    if (error==1)
        cout << "Error de parametro" << endl;
    contador=0;
    if (contador2>0){
        cout << "\nSe han encontrado " << contador2 << " resultados." << endl;
        cout << "Desplegar informacion? (si/no) ";
        cin >> respuesta;
        inicial=tolower(respuesta[0]);
        if (inicial=='s'){
            cout << endl;
            while(contador<contador2){
                cout << "Alumno #" << contador+1 << ":" << endl;
                cout << "Nombre: " << nombre[posiciones[contador]] << endl;
                cout << "Matricula: " << matricula[posiciones[contador]] << endl;
                cout << "Carrera: " << carrera[posiciones[contador]] << endl;
                cout << endl;
                contador++;
            }
        }
    }
    else
        cout << "\nNo se ha encontrado resultados." << endl;
}

void ContenedorAlumnos::agregarDatos()
{
    cout << "Nombre completo del alumno? (Respete mayusculas y espacios) " << endl;
    cin.ignore();
    getline(cin,nombreP);
    contador=0;
    estado=true;
    while(estado){
        if(datos.comprobarDatos(nombreP,nombre[contador]) || contador==cantidad){
            estado=false;
        }
        else
            contador++;
    }
    if (datos.comprobarDatos(nombreP,nombre[contador])){
        cout << "Error en nombre"<< endl;
    }
    else{
        cout << "Numero de matricula? (A0#######) ";
        cin >> matriculaP;
        contador=0;
        estado=true;
        while(estado){
            if(datos.comprobarDatos(matriculaP,matricula[contador]) || contador==cantidad){
                estado=false;
            }
            else
                contador++;
        }
        if (datos.comprobarDatos(matriculaP,matricula[contador]) || matriculaP.length()!=9){
            cout << "Error en matricula"<< endl;
        }
        else{
            cout << "Iniciales de la carrera? (solo tres caracteres) ";
            cin >> carreraP;
            if (carreraP.length()!=3){
                cout << "Error en carrera" << endl;
            }
            else{
                dato=carreraP;
                carreraP=toupper(dato[0])+toupper(dato[1])+toupper(dato[2]);
                correoP=matriculaP+"@itesm.mx";
                nombre[cantidad]=nombreP;
                matricula[cantidad]=matriculaP;
                carrera[cantidad]=carreraP;
                correo[cantidad]=correoP;
                cantidad++;
                cout << carreraP;
                cout << "Se ha agregado correctamente." << endl;
            }
        }
    }
}

void ContenedorAlumnos::eliminarDatos()
{
    cout << "Ingrese el nombre completo o matricula:" << endl << "(Nombre Snombre Apellido1 Apellido2 / A0#######) ";
    cin.ignore();
    cout << endl;
    getline(cin,dato);
    if(dato[1]=='0'){
        contador=0;
        estado=true;
        while(estado){
            if(datos.comprobarDatos(dato,matricula[contador]) || contador==cantidad){
                estado=false;
            }
            else
                contador++;
        }
        if (datos.comprobarDatos(dato,matricula[contador])){
            nombre[contador]=nombre[cantidad-1];
            matricula[contador]=matricula[cantidad-1];
            carrera[contador]=carrera[cantidad-1];
            correo[contador]=correo[cantidad-1];
            cantidad--;
        }
        else
            cout << "Error en dato" << endl;
    }
    else{
        contador=0;
        estado=true;
        while(estado){
            if(datos.comprobarDatos(dato,nombre[contador]) || contador==cantidad){
                estado=false;
            }
            else {contador++;}
        }
        if (datos.comprobarDatos(dato,nombre[contador])){
            nombre[contador]=nombre[cantidad-1];
            matricula[contador]=matricula[cantidad-1];
            carrera[contador]=carrera[cantidad-1];
            correo[contador]=correo[cantidad-1];
            cantidad--;
            cout << "Se ha borrado correctamente." << endl;
        }
        else
            cout << "Error en dato" << endl;
    }
}

void ContenedorAlumnos::actualizarDatos()
{
    ofstream archivo;
    archivo.open("Contenedor.csv");
    contador=0;
    while(contador<cantidad)
    {
        if (contador==cantidad-1){
            correoP="";
        }
        else{
            correoP=correo[contador];
        }
        datos.escribirArchivo(archivo,nombre[contador],matricula[contador],carrera[contador],correoP);
        contador++;
    }
    archivo.close();
    cout << "El archivo se ha actualizado.";
}
