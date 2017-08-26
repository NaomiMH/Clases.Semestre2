#include "CPU.h"

CPU::CPU(string nom)
{
    nombre=nom+".obj";
    archE.open(nombre);
}

void mostrar2(int matriz[20])
{
    int cont=0;
    while (cont<20){
        if (matriz[cont]!=0)
            cout << matriz[cont] << endl;
        cont++;
    }
}

void CPU::leerArch()
{
    cant=0;
    while(!archE.eof()){
        getline(archE,dato);
        dato.erase(dato.length()-1);
        lineas[cant]=dato;
        cant++;
    }
}

void CPU::trans()
{
    cout << "Transformando." << endl;
    cont=0;
    char temp;
    int temp2;
    while(cont<cant){
        dato=lineas[cont];
        switch(dato[0])
        {
        case 'A':
            {
                if(dato.find("ADD")!=-1){
                    dato.erase(0,4);
                    temp=dato[1]-48;
                    temp2=420+temp;
                    codigo[cont]=temp2;
                }
                break;
            }
        case 'B':
            {
                if(dato.find("BRAN")!=-1){
                    dato.erase(0,5);
                    temp=dato[0];
                    temp=dato[0]-48;
                    temp2=temp*10;
                    temp=dato[1];
                    temp=dato[1]-48;
                    temp2=700+temp+temp2;
                    codigo[cont]=temp2;
                }else if(dato.find("BRAZ")!=-1){
                    dato.erase(0,5);
                    temp=dato[0];
                    temp=dato[0]-48;
                    temp2=temp*10;
                    temp=dato[1];
                    temp=dato[1]-48;
                    temp2=800+temp+temp2;
                    codigo[cont]=temp2;
                }
                break;
            }
        case 'H':
            {
                if(dato.find("HALT")!=-1){
                    codigo[cont]=999;
                }
                break;
            }
        case 'I':
            {
                if(dato.find("IN")!=-1){
                    dato.erase(0,3);
                    temp=dato[1];
                    temp=dato[1]-48;
                    temp2=20+temp;
                    codigo[cont]=temp2;
                }
                break;
            }
        case 'J':
            {
                if(dato.find("JUMP")!=-1){
                    dato.erase(0,5);
                    temp=dato[0];
                    temp=dato[0]-48;
                    temp2=temp*10;
                    temp=dato[1];
                    temp=dato[1]-48;
                    temp2=600+temp+temp2;
                    codigo[cont]=temp2;
                }
                break;
            }
        case 'L':
            {
                if(dato.find("LDA")!=-1){
                    dato.erase(0,4);
                    temp=dato[1];
                    temp=dato[1]-48;
                    temp2=220+temp;
                    codigo[cont]=temp2;
                }
                break;
            }
        case 'O':
            {
                if(dato.find("OUT")!=-1){
                    dato.erase(0,4);
                    temp=dato[1];
                    temp=dato[1]-48;
                    temp2=120+temp;
                    codigo[cont]=temp2;
                }
                break;
            }
        case 'S':
            {
                if(dato.find("STA")!=-1){
                    dato.erase(0,4);
                    temp=dato[1];
                    temp=dato[1]-48;
                    temp2=320+temp;
                    codigo[cont]=temp2;
                }else if(dato.find("SUB")!=-1){
                    dato.erase(0,4);
                    temp=dato[1];
                    temp=dato[1]-48;
                    temp2=520+temp;
                    codigo[cont]=temp2;
                }
                break;
            }
        default:{cout<<":(("<<endl;codigo[cont]=-1;break;}
        }
        cont++;
    }
}

void avance(int n1,int n2,int n3)
{
    cout << "PC " <<n1+1<< "\tIR ";
    if(n2<100)
        cout <<"0";
    cout <<n2<< "\tAC " <<n3<<endl;
}

void CPU::ejec()
{
    int temp,temp2;
    cout << "Ejecutando." << endl;
    PC=0;
    while(PC!=999){
        if(codigo[PC]!=-1){
            IR=codigo[PC];
            avance(PC,IR,AC);
            temp=IR/100;
            temp2=IR%100;
            if(temp==0)
                cin>>variables[temp2-20];
            else if(temp==1)
                cout<<variables[temp2-20]<<endl;
            else if(temp==2)
                AC=variables[temp2-20];
            else if(temp==3)
                variables[temp2-20]=AC;
            else if(temp==4)
                AC=AC+variables[temp2-20];
            else if(temp==5)
                AC=AC-variables[temp2-20];
            else if(temp==6)
                PC=temp2-2;
            else if(temp==7 && AC<0)
                PC=temp2-2;
            else if(temp==8 && AC==0)
                PC=temp2-2;
            else if(temp==9)
                PC=998;
        }
        PC++;
    }
}
