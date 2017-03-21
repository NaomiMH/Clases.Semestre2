/**
 * Naomi Macias Honti a01282098
 * 16 de marzo 2017
 * 19 min.
 * Recibe los ingredientes del usuario y arma la pizza pedida, despliega ingredientes y precio final.
 */

#include <iostream>

using namespace std;

class Salchicha {
private:
   float precio;
public:
   Salchicha(){
      precio = 1;
   }
   void print(){
       cout << "   salchicha"<< endl;
   }
   float getPrecio(){ return precio;}
};

class Peperoni {
private:
   float precio;
public:
   Peperoni(){
      precio = 0.5;
   }
   void print(){
       cout << "   peperoni"<< endl;
   }
   float getPrecio(){ return precio;}
};

class Carne {
private:
   float precio;
public:
   Carne(){
      precio = 0.5;
   }
   void print(){
       cout << "   carne"<< endl;
   }
   float getPrecio(){ return precio;}
};

class Pina {
private:
   float precio;
public:
   Pina(){
      precio = 0.5;
   }
   void print(){
       cout << "   pina"<< endl;
   }
   float getPrecio(){ return precio;}
};

class Salami {
private:
   float precio;
public:
   Salami(){
      precio = 0.5;
   }
void print(){
       cout << "   salami"<< endl;
   }
   float getPrecio(){ return precio;}
};

class Pizza {
private:
    Salchicha    *salchicha;
    Peperoni   *peperoni;
    Carne  *carne;
    Pina    *pina;
    Salami *salami;
public:
    Pizza(){
       salchicha = nullptr;
       peperoni = nullptr;
       carne = nullptr;
       pina = nullptr;
       salami = nullptr;
    }
    void print(){
       cout << "\n\n\nSu pizza contiene:" << endl;
       if (salchicha != nullptr) salchicha->print();
       if (peperoni != nullptr) peperoni->print();
       if (carne != nullptr) carne->print();
       if (pina != nullptr) pina->print();
       if (salami != nullptr) salami->print();
    }
    void agregaSalchicha(){
       if (salchicha == nullptr) salchicha = new Salchicha();
    }
    void agregaPeperoni(){
       if (peperoni == nullptr) peperoni = new Peperoni();
    }
    void agregaCarne(){
       if (carne == nullptr) carne = new Carne();
    }
    void agregaPina(){
       if (pina == nullptr) pina = new Pina();
    }
    void agregaSalami(){
       if (salami == nullptr) salami = new Salami();
    }
    float getTotal(){
       float total=50;
       if (salchicha != nullptr){
            total += salchicha->getPrecio();
            delete salchicha;
       }
       if (peperoni != nullptr){
            total += peperoni->getPrecio();
            delete peperoni;
       }
       if (carne != nullptr){
            total += carne->getPrecio();
            delete carne;
       }
       if (pina != nullptr){
            total += pina->getPrecio();
            delete pina;
       }
       if (salami != nullptr){
            total += salami->getPrecio();
            delete salami;
       }
       return total;
    }
};

int main(){
   Pizza pizza;
   int opcion = 0;
   cout << "Bienvenido"<< endl;
   while(opcion != 9){
      cout << "Indique, el numero de un ingrediente, o 9 para terminar." << endl;
      cout << "1 -  Salchicha" << endl;
      cout << "2 -  Peperoni" << endl;
      cout << "3 -  Carne" << endl;
      cout << "4 -  Pina" << endl;
      cout << "5 -  Salami" << endl;
      cout << "9 -  Terminar su pedido" << endl;
      cin >> opcion;
      if (opcion == 1) pizza.agregaSalchicha();
      if (opcion == 2) pizza.agregaPeperoni();
      if (opcion == 3) pizza.agregaCarne();
      if (opcion == 4) pizza.agregaPina();
      if (opcion == 5) pizza.agregaSalami();
   }
   pizza.print();
   cout << "Total: "<< pizza.getTotal() << endl;
   cout << "Gracias por comprar con nosotros." << endl;
   return 0;
}

/// Ejercicio: Implementar la clase Pizza con cinco posibles ingredientes opcionales y el costo total
