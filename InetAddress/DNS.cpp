#include "DNS.h"
#include <cmath>

DNS::DNS()
{
    cant=0;
}

DNS::~DNS()
{
    cont=0;
    while(cont<=cant-1){
        delete ia[cont];
        cont++;
    }
}

void DNS::leerArchivo()
{
    archivoE.open("InetAddress.txt");
    string datoIP,datoHost;
    while(!archivoE.eof()){
        archivoE>>datoHost;
        archivoE>>datoIP;
        ia[cant]= new InetAddress(datoIP,datoHost);
        cant++;
    }
    archivoE.close();
}

void DNS::escrArchivo()
{
    archivoS.open("InetAddress.txt");
    cont=0;
    while(cont<=cant-1){
        archivoS<< ia[cont]->obtHost() << endl;
        archivoS<< ia[cont]->obtIP();
        if (cont!= cant-1)
            archivoS << endl;
        cont++;
    }
    archivoS.close();
}

void DNS::mostInAd()
{
    cout << "Hostname\t\t\tDireccion IP" << endl;
    cout << "---------------------------------------" << endl;
    cont=0;
    while(cont<cant){
        if(admin)
            cout << cont+1 << ". ";
        cout << ia[cont]->obtHost() << "\t\t" << ia[cont]->obtIP() << endl;
        cont++;
    }
}

void DNS::obtIP()
{
    cout << "Hostname: (completo) ";
    cin >> resp;
    cin.ignore();
    cont=0;
    string comp;
    bool estado=false;
    while(cont<cant){
        comp=ia[cont]->obtHost();
        if(comp==resp){
            cout << "IP solicitada: " << ia[cont]->obtIP() << endl;
            estado=true;
        }
        cont++;
    }
    if(!estado)
        cout << "La IP del Hostname no fue encontrada." << endl;
}

void DNS::obtHost()
{
    cout << "IP: (completo) ";
    cin >> resp;
    cin.ignore();
    cont=0;
    string comp;
    bool estado=false;
    while(cont<cant){
        comp=ia[cont]->obtIP();
        if(comp==resp){
            cout << "Hostname solicitado: " << ia[cont]->obtHost() << endl;
            estado=true;
        }
        cont++;
    }
    if(!estado)
        cout << "El Hostname de la IP no fue encontrado." << endl;
}

void DNS::busHost()
{
    cout << "Palabra clave: (minusculas) ";
    cin >> resp;
    cin.ignore();
    cout << endl;
    cont=0;
    string comp;
    int pos[cant]={-1};
    int exi;
    bool estado=false;
    while(cont<cant){
        comp=ia[cont]->obtHost();
        exi=comp.find(resp);
        if(exi!=-1){
            pos[cont]=1;
            estado=true;
        }
        cont++;
    }

    if(estado){
        cout << "Se encontraron los siguientes Hostnames." << endl;
        cont=0;
        while(cont<cant){
            if(pos[cont]==1){
                cout << endl;
                cout << "Hostname\t" << ia[cont]->obtHost() << endl;
                cout << "IP\t\t" << ia[cont]->obtIP() << endl;
            }
            cont++;
        }
    }
    else
        cout << "No se encontro ningun Hostname." << endl;
}

void DNS::busIP()
{
    cout << "Numero clave: ";
    cin >> resp;
    cin.ignore();
    cout << endl;
    cont=0;
    string comp;
    int pos[cant]={-1};
    int exi;
    bool estado=false;
    while(cont<cant){
        comp=ia[cont]->obtIP();
        exi=comp.find(resp);
        if(exi!=-1){
            pos[cont]=1;
            estado=true;
        }
        cont++;
    }

    if(estado){
        cout << "Se encontraron las siguientes IPs." << endl;
        cont=0;
        while(cont<cant){
            if(pos[cont]==1){
                cout << endl;
                cout << "IP\t\t" << ia[cont]->obtIP() << endl;
                cout << "Hostname\t" << ia[cont]->obtHost() << endl;
            }
            cont++;
        }
    }
    else
        cout << "No se encontro ninguna IP." << endl;
}

void DNS::menu()
{
    cout << "1. Cambiar una IP." << endl;
    cout << "2. Cambiar un Hostname." << endl;
    cout << "3. Eliminar un Hostname e IP." << endl;
    cout << "4. Agregar un Hostname e IP." << endl;
    cout << "5. Mostrar lista de Hostnames e IPs." << endl;
    cout << "0. Salir." << endl;
}

void DNS::eliminar()
{
    cout << "Introduzca el numero del dato que quiere eliminar." << endl;
    admin=true;
    mostInAd();
    admin=false;
    int res;
    cout << "Dato #";
    cin >> res;
    cin.ignore();
    delete ia[res-1];
    cont=res;
    while(cont<cant){
        ia[cont-1]=ia[cont];
        cont++;
    }
    cant--;
}

void DNS::agregar()
{
    cout << "Introduzca el Hostname: (completo) ";
    cin >> resp;

    cont=0;
    string comp;
    int exi;
    bool estado=false;
    while(cont<cant){
        comp=ia[cont]->obtHost();
        exi=comp.find(resp);
        if(exi!=-1)
            estado=true;
        cont++;
    }
    if(estado)
        cout << "Ese Hostname si existe." << endl;
    else{
        do{
            string resp2;
            cout << "Introduzca la IP: (###.###.###.###) ";
            cin >> resp2;

            cont=0;
            estado=false;
            while(cont<cant){
                comp=ia[cont]->obtIP();
                exi=comp.find(resp2);
                if(exi!=-1)
                    estado=true;
                cont++;
            }
            bool error=false;
            if(estado)
                cout << "Esa IP esta en uso." << endl;
            else if(resp2.length()>15 || resp2.length()<0)
                cout << "Longitud de IP invalida." << endl;
            else{
                int pos, ipN=0;
                string ipL;
                char camb;

                cout << "Primer Numero." << endl;
                pos=resp2.find(".");
                if(pos==-1)
                    error=true;
                ipL=resp2.substr(0,pos);
                resp2.erase(0,pos+1);
                pos=ipL.length()-1;
                while(pos>=0){
                    camb=ipL[pos]-48;
                    cout << ipN << endl;
                    cout << camb+0 << "\t" << pow(10,pos) << "\t" << (camb*pow(10,pos)) << endl;
                    ipN=ipN+(camb*pow(10,pos));
                    cout << ipN << endl;
                    pos--;
                }
                cout << "Numero final " << ipN << endl;
                if(ipN>255 || ipN<0)
                    error=true;

                cout << "Segundo Numero." << endl;
                ipN=0;
                pos=resp2.find(".");
                if(pos==-1)
                    error=true;
                ipL=resp2.substr(0,pos);
                resp2.erase(0,pos+1);
                pos=ipL.length()-1;
                while(pos>=0){
                    camb=ipL[pos]-48;
                    ipN=ipN+(camb*pow(10,pos));
                    pos--;
                }
                cout << "Numero final " << ipN << endl;
                if(ipN>255 || ipN<0)
                    error=true;


                cout << "Tercer Numero." << endl;
                ipN=0;
                pos=resp2.find(".");
                if(pos==-1)
                    error=true;
                ipL=resp2.substr(0,pos);
                resp2.erase(0,pos+1);
                pos=ipL.length()-1;
                while(pos>=0){
                    camb=ipL[pos]-48;
                    ipN=ipN+(camb*pow(10,pos));
                    pos--;
                }
                cout << "Numero final " << ipN << endl;
                if(ipN>255 || ipN<0)
                    error=true;


                cout << "Cuarto Numero." << endl;
                ipN=0;
                pos=resp2.find(".");
                if(pos==-1)
                    pos=resp2.length();
                ipL=resp2.substr(0,pos);
                resp2.erase(0,pos+1);
                pos=ipL.length()-1;
                while(pos>=0){
                    camb=ipL[pos]-48;
                    ipN=ipN+(camb*pow(10,pos));
                    pos--;
                }
                cout << "Numero final " << ipN << endl;
                if(ipN>255 || ipN<0)
                    error=true;
            }
            if(error)
                cout << "Recuerde que la IP tiene que tener cuatro numeros diferentes separados por puntos y dentro del margen (0-255)." << endl;
            else
                admin=true;
        }while(!admin);
        admin=false;
    }
}

void DNS::cambiarIP()
{
    cout << "Introduzca el numero del dato IP que quiere modificar." << endl;
    admin=true;
    mostInAd();
    admin=false;
    int res;
    cout << "Dato #";
    cin >> res;
    cin.ignore();
    int num;
    cout << "Introduzca el primer numero de la IP: (###) ";
    cin >> num;
    cin.ignore();
    if(num>=0 && num<=255){
        ia[res-1]->ipArr[0]=num;
        cout << "Introduzca el segundo numero de la IP: (###) ";
        cin >> num;
        cin.ignore();
        if(num>=0 && num<=255){
            ia[res-1]->ipArr[1]=num;
            cout << "Introduzca el tercer numero de la IP: (###) ";
            cin >> num;
            cin.ignore();
            if(num>=0 && num<=255){
                ia[res-1]->ipArr[2]=num;
                cout << "Introduzca el cuarto numero de la IP: (###) ";
                cin >> num;
                cin.ignore();
                if(num>=0 && num<=255){
                    ia[res-1]->ipArr[3]=num;
                    ia[res-1]->cambIP();
                }
            }
        }
    }
    else
        cout << "Tiene que ser un numero dentro del rango (0-255)." << endl;
}

void DNS::cambiarHost()
{
    cout << "Introduzca el numero del dato IP que quiere modificar." << endl;
    admin=true;
    mostInAd();
    admin=false;
    int res;
    cout << "Dato #";
    cin >> res;
    cin.ignore();
    cout << "Introduzca el nuevo Hostname: (completo) ";
    cin >> resp;
    ia[res-1]->cambHost(resp);
}

void DNS::modInAd()
{
    cout << "Seleccione la accion a realizar." << endl;
    resp="";
    do{
        menu();
        cin >> resp;
        cin.ignore();
        cout << endl;
        switch(resp[0]){
        case 49: {cambiarIP(); break;}
        case 50: {cambiarHost(); break;}
        case 51: {eliminar(); break;}
        case 52: {cout << "Incompleto." << endl/*agregar()*/; break;}
        case 53: {mostInAd(); break;}
        case 48: {cout << "Saliendo."; break;}
        default: {cout << "Error." << endl; break;}
        }
        cout << endl << endl;
    }while(resp[0]!=48);
}
