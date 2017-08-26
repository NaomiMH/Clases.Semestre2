#include "InetAddress.h"

InetAddress::InetAddress()
{
    hostname="";
    ip="";
    ipArr[0]=-1;
    ipArr[1]=-1;
    ipArr[2]=-1;
    ipArr[3]=-1;
}

InetAddress::InetAddress(string archIP, string archHost)
{
    ip=archIP;
    hostname=archHost;
}

string InetAddress::obtHost()
{
    return hostname;
}

string InetAddress::obtIP()
{
    return ip;
}

void InetAddress::cambHost(string usuHost)
{
    hostname=usuHost;
    cout << "Nuevo Hostname actualizado." << endl;
}

void InetAddress::cambIP()
{
    string camb;
    char cambC;
    cont=0;
    ip="";
    int num;
    while(cont<4){
        camb="";
        num=ipArr[cont];
        if (num==0){
            cambC='0';
            camb=cambC;
        }
        while(num>0){
            cambC=((num%10)+48);
            num=num/10;
            camb=cambC+camb;
        }
        ip=ip+camb;
        cont++;
        if(cont!=4)
            ip=ip+".";
    }
    cout << "Nueva IP actualizada." << endl;
}
