#include <iostream>
#include "pila.h"


using namespace std;


/**
 * Ricordare che il file "pila.h" contiene la definizione della struct "cella" (qui sotto riportata)
 * 
 * struct cella {
 *   int indiceRiga;
 *   int indiceColonna;
 * };
 */
void risolviLabirinto(int [][5], int, int);


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale  

    // E' possibile modificare la matrice per effettuare dei test   
    int labirinto[5][5] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 1 },
        { 0, 1, 0, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 }
    };

    // E' possibile modificare la cella di arrivo per effettuare dei test (la cella di partenza invece è sempre [0,0])   
    cout<<"Percorso: ";
    risolviLabirinto(labirinto, 4, 3);
   
    return 0;

}

bool ricercaPercorso(int m[][5], int x, int y, int x_arrivo, int y_arrivo, lista percorso){
  //caso base: se sono arrivato alla cella di arrivo, ho trovato il percorso
  if(x == x_arrivo && y == y_arrivo){
    //stampa o pusho anche la cella di arrivo
    cella c;
    c.indiceRiga = x;
    c.indiceColonna = y;
    push(c);
    return true;
  }
  //caso base: se la cella è un muro, non posso andare avanti
  if(x < 0 || y < 0 || x >= 5 || y >= 5 || m[x][y] == 0){
    return false;
  }
  //caso base: se la cella è già stata visitata, non posso andare avanti
  if(m[x][y] == 2){
    return false;
  }
  //marco la cella come visitata
  m[x][y] = 2;
  //push della cella
  cella c;
  c.indiceRiga = x;
  c.indiceColonna = y;
  push(c);
  //ricorsivamente cerco di arrivare alla cella di arrivo tramite la funzione cerca(...);
  //deinit necessaria solo se non trovo il percorso: dato che se lo trovo faccio top e poi pop 
  if(ricercaPercorso(m, x+1, y, x_arrivo, y_arrivo, percorso)){
    return true;
  }
  if(ricercaPercorso(m, x-1, y, x_arrivo, y_arrivo, percorso)){
    return true;
  }
  if(ricercaPercorso(m, x, y+1, x_arrivo, y_arrivo, percorso)){
    return true;
  }
  if(ricercaPercorso(m, x, y-1, x_arrivo, y_arrivo, percorso)){
    return true;
  }
  return false;
}

void risolviLabirinto(int m[][5], int x, int y){
  //inizializiamo pile di supporto. 
  lista percorso;//pila contenente il percorso da stampare
  //booleano per indicare se ho trovato un percorso
  bool risolubile = false;
  //inizializzazione pila di supporto
  init();
  if(!ricercaPercorso(m, 0, 0, x, y, percorso)){
    cout<<"Non esiste un percorso"<<endl;
    deinit(); //deinizializzo la pila
  }
  else{
    cella t;
    while(top(t)){ //finchè la pila non è vuota 
      cout<<"["<<t.indiceRiga<<","<<t.indiceColonna<<"] ";//stampo la cella
      pop();//la tolgo dalla pila
    }
    cout<<endl;
  }
  
}
