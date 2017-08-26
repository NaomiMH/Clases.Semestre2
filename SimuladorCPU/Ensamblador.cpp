#include "Ensamblador.h"

Ensamblador::Ensamblador(string nom)
{
    nombre= nom+".asm";
    archivoE.open(nombre);
    nombre= nom+".obj";
    archivoS.open(nombre);
}

Ensamblador::~Ensamblador()
{
    archivoS.close();
}

void mostrar3(string matriz[20])
{
    int cont=0;
    while (cont<20){
        if (matriz[cont]!="")
            cout << matriz[cont] << endl;
        cont++;
    }
}

void Ensamblador::agreLin(int linEmp, int linAgr)
{
    int cont3,cont4;
    if (20<cant+linAgr)
        cout << "Se avisa que puede haber perdida de memoria." << endl;
    cont3=cant;
    cont4=linAgr+cant;
    linAgr=0;
    cant=cont4;
    while(cont4-linAgr>linEmp){
        linea[cont4-linAgr]=linea[cont3-linAgr];
        linea[cont3-linAgr]="*";
        linAgr++;
    }
}

void Ensamblador::quitLin(int linEmp, int linAgr)
{
    int cont3,cont4;
    cant=cant-linAgr;
    cont3=linEmp;
    cont4=cont3+linAgr;
    linEmp=linAgr;
    linAgr=0;
    while(linEmp>0){
        linea[cont3+linAgr]=linea[cont4+linAgr];
        linea[cont4+linAgr]=" ";
        linAgr++;
        linEmp--;
    }
}

void Ensamblador::crearCod()
{
    string dato;
    cant=0;
    int pos,mem,cont2;
    char temp;
    bool estado;
    cin.ignore();

    while (!archivoE.eof()){
        getline(archivoE,linea[cant]);
        pos=linea[cant].find(";");
        if (pos != -1)
            linea[cant].erase(pos,1);
        dato=linea[cant];
        while(dato[0]==' ')
            dato.erase(0,1);
        if(dato[0]!= 'L' && dato[0]!= 'I'){
            do{
                pos=dato.find(" ");
                if (pos != -1)
                    dato.erase(pos,1);
            }while(pos!=-1);
        }
        linea[cant]=dato;
        cant++;
    }

    mem=0;
    pos=0;
    cont=0;
    cout << "Convirtiendo." << endl;

    while(cont<cant){
        pos=linea[cont].find("Leer");
        if (pos!=-1){
            linea[cont].erase(pos,5);
            dato=linea[cont];
            temp=dato[0];
            cont2=0;
            estado=false;
            pos=-1;
            while(cont2<mem && !estado){
                dato=memC[cont2];
                pos=dato.find(temp);
                if(pos!=-1)
                    estado=true;
                cont2++;
            }
            if (estado)
                cont2--;
            if (pos==-1){
                memC[mem]=temp;
                mem++;
                cont2= mem-1;
            }
            temp=cont2+48;
            dato=temp;
            temp=50;
            dato=temp+dato;
            dato="IN "+dato;
            linea[cont]=dato;
        }

        pos=linea[cont].find("Imprimir");
        if (pos!=-1){
            linea[cont].erase(pos,9);
            dato=linea[cont];
            temp=dato[0];
            cont2=0;
            estado=false;
            pos=-1;
            while(!estado){
                dato=memC[cont2];
                pos=dato.find(temp);
                if(pos!=-1)
                    estado=true;
                cont2++;
            }
            cont2--;
            temp=cont2+48;
            dato=temp;
            temp=50;
            dato=temp+dato;
            dato="OUT "+dato;
            linea[cont]=dato;
        }

        pos=linea[cont].find("Fin");
        if (pos!=-1){
            linea[cont]="HALT";
        }

        pos=linea[cont].find("=");
        if (pos==1){
            IR=linea[cont];
            dato=IR;
            temp=dato[pos+1];
            cont2=0;
            estado=false;
            pos=-1;
            while(!estado){
                dato=memC[cont2];
                pos=dato.find(temp);
                if(pos!=-1)
                    estado=true;
                cont2++;
            }
            cont2--;
            temp=cont2+48;
            dato=temp;
            temp=50;
            dato=temp+dato;
            dato="LDA "+dato;
            agreLin(cont,1);
            linea[cont]=dato;
            cont++;

            dato=IR;
            if(dato.length()>3){
                agreLin(cont,1);
                temp=dato[dato.length()-1];
                cont2=0;
                estado=false;
                pos=-1;
                while(!estado){
                    dato=memC[cont2];
                    pos=dato.find(temp);
                    if(pos!=-1)
                        estado=true;
                    cont2++;
                }
                cont2--;
                temp=cont2+48;
                dato=temp;
                temp=50;
                dato=temp+dato;

                if(IR.find("-")!=-1)
                    dato="SUB "+dato;
                else
                    dato="ADD "+dato;
                linea[cont]=dato;
                cont++;
            }

            dato=IR;
            temp=dato[0];
            cont2=0;
            estado=false;
            pos=-1;
            while(!estado && cont2<10){
                dato=memC[cont2];
                pos=dato.find(temp);
                if(pos!=-1)
                    estado=true;
                cont2++;
            }
            cont2--;
            temp=cont2+48;
            dato=temp;
            temp=50;
            dato=temp+dato;
            dato="STA "+dato;
            linea[cont]=dato;
        }
        cont++;
    }
    cambIfWhi(mem);
}

void Ensamblador::cambIfWhi(int mem)
{
    string dato,temp3,temp4;
    int pos,cont2, temp2;
    bool estado;
    char temp;

    cont=cant-1;
    while(cont>=0){
        pos=linea[cont].find("{");
        if(pos!=-1){
            dato=linea[cont];
            pos=dato.find("while");
            if(dato.find("while")!=-1){
                cont2=cont;
                estado=false;
                while(cont2<cant && !estado){
                    pos=linea[cont2].find("}");
                    if(pos!=-1)
                        estado=true;
                    cont2++;
                }
                cont2--;

                if(dato.find("!=")!=-1){
                    temp=dato[6];
                    temp2=0;
                    estado=false;
                    pos=-1;
                    while(!estado && temp2<10){
                        dato=memC[temp2];
                        pos=dato.find(temp);
                        if(pos!=-1)
                            estado=true;
                        temp2++;
                    }
                    temp2--;
                    temp=temp2+48;
                    dato=temp;
                    temp=50;
                    dato=temp+dato;
                    dato="LDA "+dato;
                    IR=linea[cont];
                    agreLin(cont,1);
                    cont2++;
                    linea[cont]=dato;
                    cont++;
                    linea[cont]=IR;

                    temp2=(cont+1)%10;
                    temp=temp2+48;
                    dato=temp-1;
                    temp2=(cont+1)/10;
                    temp=temp2+48;
                    temp3=temp+dato;
                    dato="JUMP "+temp3;
                    linea[cont2]=dato;

                    for(int cont3=0; cont3<cant; cont3++){
                        pos=linea[cont3].find("if");
                        if (pos!=-1)
                            cont2=cont2+2;
                    }

                    temp2=(cont2+1)%10;
                    temp=temp2+48;
                    dato=temp+1;
                    temp2=(cont2+1)/10;
                    temp=temp2+48;
                    temp3=temp+dato;
                    dato="BRAZ "+temp3;
                    linea[cont]=dato;

                }
                else if(dato.find("==")!=-1){
                    cout << ":(1" << endl;
                }
                else if(dato.find("<")!=-1){
                    cout << ":(2" << endl;
                }
                else if(dato.find(">")!=-1){
                    cout << ":(3" << endl;
                }
            }else if (dato.find("if")!=-1){
                cout << ":(4" << endl;
            }
        }
        cont--;
    }
    cont=0;
    while(cont<cant){
        pos=linea[cont].find("if");
            if(pos!=-1){
                dato=linea[cont];

                cont2=cont;
                estado=false;
            while(cont2<cant && !estado){
                pos=linea[cont2].find("else");
                if(pos!=-1)
                    estado=true;
                cont2++;
            }
            cont2--;

            IR=linea[cont];
            temp3=linea[cont+1];
            temp4=linea[cont2+1];

            if(dato.find("!=")!=-1){
                cout << ":(5" << endl;
            }
            else if(dato.find("==")!=-1){
                cout << ":(6" << endl;
            }
            else if(dato.find("<")!=-1){
                linea[cont+1]=temp4;

                linea[cont+3]=temp3;
                cont2=cont+3;

                dato=IR;
                temp=dato[3];
                temp2=0;
                estado=false;
                pos=-1;
                while(!estado && temp2<10){
                    dato=memC[temp2];
                    pos=dato.find(temp);
                    if(pos!=-1)
                        estado=true;
                    temp2++;
                }
                temp2--;
                temp=temp2+48;
                dato=temp;
                temp=50;
                dato=temp+dato;
                dato="LDA "+dato;
                agreLin(cont,1);
                linea[cont]=dato;
                cont++;
                cont2++;

                agreLin(cont,1);
                dato=IR;
                temp=dato[5];
                temp2=0;
                estado=false;
                pos=-1;
                while(!estado && temp2<10){
                    dato=memC[temp2];
                    pos=dato.find(temp);
                    if(pos!=-1)
                        estado=true;
                    temp2++;
                }
                temp2--;
                temp=temp2+48;
                dato=temp;
                temp=50;
                dato=temp+dato;
                dato="SUB "+dato;
                linea[cont]=dato;
                cont++;
                cont2++;

                temp2=(cont2+2)%10;
                temp=temp2+48;
                dato=temp;
                temp2=(cont2+2)/10;
                temp=temp2+48;
                dato=temp+dato;
                dato="JUMP "+dato;
                linea[cont+2]=dato;

                temp2=(cont2+1)%10;
                temp=temp2+48;
                dato=temp;
                temp2=(cont2+1)/10;
                temp=temp2+48;
                dato=temp+dato;
                dato="BRAN "+dato;
                linea[cont]=dato;
            }
            else if(dato.find(">")!=-1){
                cout << ":(8" << endl;
            }
        }
        cont++;
    }
}

void Ensamblador::escrArch()
{
    cont=0;
    while(cont<cant){
        archivoS<<linea[cont] << ";";
        if(cont!=cant-1)
            archivoS<<endl;
        cont++;
    }
}
