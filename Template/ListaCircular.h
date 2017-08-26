#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

using namespace std;

#include <iostream>

template <typename T, int N>
class ListaCircular
{
    public:
        ListaCircular() {primero = ultimo = 0;}
        ~ListaCircular();
        void agrega(T*);
        T* extrae();

    private:
        int primero,ultimo;
        T *dato[N];
};

template <typename T, int N>
ListaCircular<T, N>::~ListaCircular()
{
    while( primero != ultimo){
        delete dato[primero];
        primero = (primero+1)%N;
    }
}

template <typename T, int N>
void ListaCircular<T, N>::agrega(T *elem)
{
    dato[ultimo] = elem;
    ultimo = (ultimo+1)%N;
}

template <typename T, int N>
T* ListaCircular<T, N>::extrae()
{
    T* temp = dato[primero];
    primero = (primero+1)%N;
    return temp;
}

#endif // LISTACIRCULAR_H
