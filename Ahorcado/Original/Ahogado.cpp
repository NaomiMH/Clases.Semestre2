#include "Ahorcado.h"

Ahorcado::Ahorcado(string palabra){
   sPalabra = palabra;  ///Palabara a adivinar
   sIntentadas = "";
   sx = "XXXXXXX";
   iEncontradas = 0;
   iFallos = 0;
}

void Ahorcado::muestraEscenario(){
   string sEscenario[] = {"", "  O", "  O\n /", "  O\n /|", "  O\n /|\\", "  O\n /|\\ \n  |", "  O\n /|\\ \n  | \n /", "  O\n /|\\ \n  | \n / \\"};
   cout << sEscenario[iFallos] << endl;
   cout << "Encontradas: " << sx << endl;
   cout << "Intentadas: " << sIntentadas << endl;
}
///Busca todas ls instancias de la 'letra' en la 'palabra'
void Ahorcado::validaIntento(char letra){
   int iPos;
   bool bEncontro = false; ///Entro por lo menos una letra en la palabra?
   sIntentadas += letra; ///Coloca la nueva letra al final
   while((iPos = sPalabra.find(letra)) != -1){ ///Busca letra en la palabra desde el principio de la palabra
      sx[iPos] = letra;      ///Substituyela en lugar de la X por la letra encontrada
      sPalabra[iPos] = '-';   ///Elimina la letra adivinada por el jugador
      bEncontro = true;    ///Encontro por lo menos una letra en la palabra
      iEncontradas++;        ///Total de letras encontradas en la palabra
   }
   if (!bEncontro) ///Si no encontro ninguna letra en la palabra a adiviar
      iFallos++; ///No encontro la letra, incrementar el numero de fallos
}

///El juego termina cuando se adivine la palabra completa o se cometan 7 errores
bool Ahorcado::continuarJuego(){
   if( (iFallos < 7) && (iEncontradas < 7) )
      return true;
   return false;
}

 ///El jugador gano el juego cuando se hayan adivinado las 7 letras de la palabra
bool Ahorcado::ganoJuego(){
   if(iEncontradas == 7)
      return true;
   return false;
}
