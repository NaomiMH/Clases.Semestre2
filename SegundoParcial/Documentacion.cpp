#include "Documentacion.h"
#include <fstream>
#include <iostream>
#include <ctype.h>
#include <string>

ifstream cpp;
ofstream html;

Documentacion::Documentacion()
{
    //c
}

bool Documentacion::checarExistencia()
{
    ifstream cpp;
    cpp.open(archivoE);
    string dato="";
    cpp>> dato;
    cpp.close();
    if(dato!=""){
        archivoS=nombre+".html";
        return true;
    }
    else
        return false;
}

void Documentacion::empezarArchivo()
{
    html.open(archivoS);
    html<< "<!DOCTYPE html>\n<html>\n<head>\n<title>\nDocumentaci&oacute;n del archivo " << archivoE << "\n</title>\n</head>\n<body>\n";
    cout << "Creando archivo " << archivoS << "." << endl << endl;
}

void Documentacion::terminandoArchivo()
{
    cout << "Terminando archivo." << endl << endl;
    html<< "</body>\n</html>";
    html.close();
    cout << "Archivo terminado." << endl;
}

void Documentacion::llenarinformacion()
{
    empezarArchivo();
    instrucciones=0;
    error=0;
    cout << "Reconocimiento de instrucciones." << endl << endl;
    cpp.open(archivoE);
    while(!cpp.eof()){
        getline(cpp,datos);
        if(datos[0]=='@'){
            posicion=datos.find(" ");
            instruccion=datos.substr(1,posicion-1);
            datos.erase(0,posicion+1);
            switch (instruccion[3]){
            case 'e':{
                date=datos;
                instrucciones++;
                html<< "<strong>Fecha de elaboraci&oacute;n </strong>" << date << "<br>\n";
                break;
            }
            case 'g':{
                progName=datos;
                instrucciones++;
                html<< "<h2>\nPrograma: " << progName << "<br>\n</h2>\n";
                break;
            }
            case 'h':{
                author=datos;
                instrucciones++;
                html<< "<strong>Autor: </strong>" << author << "<br>\n";
                break;
            }
            case 'a':{
                param=datos;
                instrucciones++;
                html<< "<strong>Parametro: </strong>" << param << "<br>\n";
                break;
            }
            case 'u':{
                retur=datos;
                instrucciones++;
                html<< "<strong>Valor de retorno: </strong>" << retur << "<br>\n";
                break;
            }
            case 'c':{
                if (instruccion=="desc"){
                    desc=datos;
                    html<< "<strong>Descripci&oacute;n: </strong>" << desc << "<br>\n";
                }
                else{
                    funcName=datos;
                    html<< "<h3>\n<hr><br>Funci&oacute;n: " << funcName << "<br>\n</h3>\n";
                }
                instrucciones++;
                break;
            }
            default:{
                cout << "Error, instruccion invalida encontrada." << endl;
                error++;
                break;
            }
            }
        }
    }
    cout << "Instrucciones encontradas: "<< instrucciones << endl;
    cout << "Errores: " << error << endl << endl << endl;

    terminandoArchivo();
}

void Documentacion::crearArchivo()
{

    do{
        cout << "Cual es el nombre del documento? (sin extension) ";
        cin >> nombre;
        archivoE= nombre + ".cpp";
        if (!checarExistencia()){
            cout << "El archivo no ha sido encontrado." << endl << endl;
        }
    }while(!checarExistencia());
    cout << "\n\nEl archivo se ha encontrado." << endl << endl;
    cout << "Archivo a leer: " << archivoE << endl;
    cout << "Archivo a escribir: " << archivoS << endl << endl << endl;
}
