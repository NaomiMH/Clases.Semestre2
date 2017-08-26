#ifndef INETADDRESS_H
#define INETADDRESS_H

using namespace std;


#include <iostream>
#include <fstream>

class InetAddress
{
    public:
        InetAddress();
        InetAddress(string archIP, string archHost);

        string obtHost();
        string obtIP();
        void cambHost(string);
        void cambIP();
        int ipArr[4];

    private:
        string hostname, ip;
        int cont;
};

#endif // INETADDRESS_H
