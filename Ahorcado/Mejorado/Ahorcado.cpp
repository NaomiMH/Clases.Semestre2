#include <iostream>
#include <string>
#include "Ahorcado.h"

string palabraX[15]={""};

Ahorcado::Ahorcado(){

}

void Ahorcado::iniciar(string palabraP)
{
    palabra = palabraP;
    palabraN=palabra.length();
    intentosL = "";
    encontradas=0;
    fallos=0;
    contador=0;
    while(contador<15){
        palabraX[contador]="X";
        contador++;
    }
}

void Ahorcado::mostrarEscenario(){
    string escenario[] = {"", "  O", "  O\n /", "  O\n /|", "  O\n /|\\", "  O\n /|\\ \n  |", "  O\n /|\\ \n  | \n /", "  O\n /|\\ \n  | \n / \\"};
    cout << escenario[fallos] << endl;
    cout << "_____________________" << endl;

    cout << "Encontradas: ";
    contador=0;
    while(contador<palabraN){
        cout << palabraX[contador];
        contador++;
    }
    cout << endl;
    cout << "Intentadas: " << intentosL << endl;
}

///Busca todas las instancias de la 'letra' en la 'palabra'
void Ahorcado::comprobarLetra(char letra){
    bool estado = false; ///Entro por lo menos una letra en la palabra?
    if(intentosL.find(letra)==-1){
        intentosL += letra;
        contador=0;
        while(contador<palabraN){
            if (palabra[contador]==letra){
                palabraX[contador] = letra;
                palabra[contador] = '-';
                estado = true;
                encontradas++;
            }
            contador++;
        }
        if (!estado)
            fallos++;
    }
    else
        cout << "\nEsa letra ya fue utilizada, intenta otra." << endl;
}

int Ahorcado::estadoJuego(){
    if(fallos>7)
        return 0;
    else if (encontradas==palabraN)
        return 1;
    else
        return 3;
}
