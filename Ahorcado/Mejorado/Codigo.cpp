/**
 * Naomi Macias Honti a01282098
 * 28 de febrero 2017
 * 56 lineas mas 7 de comentarios. 63 en total.
 * 1 hr 30 min.
 * Agarra un listado de palabras con una longitud maxima de 15 de un archivo txt, muestra el escenario donde estan los intentos previos y lo que se ha encontrado de la palabra. Recibe un caracter del usuario y comprueba si ya fue usado, si esta en la palabra o si ya perdiste las 7 vidas.
 */
 #include <iostream>
 #include <fstream>

 using namespace std;

 #include "Ahorcado.h"

 int main(){
    ifstream archivo;
    archivo.open("Palabras.txt");
    int cantidad=0;
    archivo>>cantidad;
    string palabras[cantidad];
    int contador=0;
    while(!archivo.eof()){
        archivo>>palabras[contador];
        contador++;
    }
    archivo.close();

    Ahorcado documento;
    string palabra, respuesta;
    char letra;
    cout << "Adivina la palabra!" << endl << endl;
    int juego=1;
    do{
        cout << "Palabra #" << juego << endl;
        palabra=palabras[juego-1];
        documento.iniciar(palabra);

        while(documento.estadoJuego()==3)
        {
            documento.mostrarEscenario();
            cout << "Dame una letra: ";
            cin >> letra;
            documento.comprobarLetra(letra);
        }
        if (documento.estadoJuego()==1){
            cout << "\n\nFelicidades Ganaste!! La palabra final es " << palabra << endl << endl;
        }
        else if (documento.estadoJuego()==0){
            cout << "\n\nLo siento, no lo has logrado. La palabra era " << palabra << endl << endl;
        }
        cout << "Quieres volver a jugar? (si/no) ";
        cin >> respuesta;
        cout << endl;
        juego++;
    }while(respuesta[0]=='s' || juego>cantidad);

    if (juego>cantidad){
        cout << "\n\nLo sentimos, las palabras se han terminado." << endl << endl;
    }

    return 0;
}
