#ifndef GENERICARRAY_H
#define GENERICARRAY_H

using namespace std;

#include <iostream>

template <typename T, int N>
class GenericArray
{
    public:
        GenericArray();
        ~GenericArray() {}
        void imprimir();
        void insertar(T);
        void borrar(T);
        int buscar(T);

    private:
        T arr[N];
        int n;
};

template <typename T, int N>
GenericArray<T,N>::GenericArray()
{
    arr[0]=T(0);
    n=0;
}

template <typename T, int N>
void GenericArray<T,N>::imprimir()
{
    for(int cont=0; cont<n; cont++)
        cout << arr[cont] << " ";
    cout << endl;
}

template <typename T, int N>
void GenericArray<T,N>::insertar(T num)
{
    if(n==0)
        arr[n] = num;
    else{
        int cont = n;
        while ((cont>0) && (arr[cont-1]>= num)) {
            arr[cont] = arr[cont-1];
            cont--;
        }
        arr[cont] = num;
    }
    n++;
}

template <typename T, int N>
void GenericArray<T,N>::borrar(T num)
{
    int pos=-1;
    for(int cont=0; cont<n; cont++){
        if(arr[cont]==num)
            pos=cont;
        if(pos!=-1 && cont!=n-1)
            arr[cont]=arr[cont+1];
    }
    if(pos!=-1)
        n--;
}

template <typename T, int N>
int GenericArray<T,N>::buscar(T num)
{
    int pos=-2;
    for(int cont=0; cont<n; cont++){
        if(arr[cont]==num)
            pos=cont;
    }
    return pos+1;
}

#endif // GENERICARRAY_H
