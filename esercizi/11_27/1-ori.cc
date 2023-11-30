/*
Scrivere la dichiarazione e la definizione di una funzione unisciListe, che prende
in input due puntatori a due liste concatenate contenenti float, e restituisce il
primo nodo di una nuova lista concatenata, che contiene prima gli elementi della
prima lista e poi gli elementi della seconda.
Una volta scritta questa funzione, scrivere una seconda funzione scorriLista, che
prende in input un puntatore a una lista concatenata, rimuove gli elementi maggiori
di 0, e restituisce la somma degli elementi appena rimossi.

Il programma deve terminare correttamente, e per fare ciò la memoria va corretta-
mente deallocata. Implementare la funzione deallocaLista, in modo che si occupi

di questa mansione.
Note:
Scaricare il file 1-ori.cc da Google Drive e inserire la corretta implementazione
delle funzioni unisciListe, scorriLista e deallocaLista. Il file arriva già
fornito con alcune funzioni ausiliarie per le liste ed un main.

Il programma deve essere in grado di riconoscere il contesto dell’input. In partico-
lare:

• se una delle due liste è vuota, verrà restituito un puntatore all’altra;
• se entrambe sono vuote, verrà restituito un puntatore a NULL;
• se vengono dati puntatori a nodi centrali (e non all’inizio della lista), il
programma dovrà restituire un errore.
Le dimensioni delle liste in input sono generate casualmente e non è possibile fare
assunzioni sulle dimensioni.
• Ricordarsi (importante!) di deallocare la memoria.
• È consentito definire ed implementare funzioni ausiliarie che possano aiutarvi
nella soluzione del problema.
• All’interno di questo programma non è ammesso l’utilizzo di variabili globali
o di tipo static e di funzioni di libreria al di fuori di quelle definite in
iostream.
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Anche se c'è questa costante che limita la dimensione degli array,
// è fatta solo per evitare di far girare i vostri programmi per decine
// di minuti. Non programmate con dimensioni fisse, per favore.
const int UPPER_BOUND_DIM = 10;
const int UPPER_BOUND_VAL = 50;

struct nodo {
  float valore;
  nodo* pred;
  nodo* succ;
};

typedef nodo* lista;

float randVal();
lista generaLista();
void stampaLista(nodo* nodoCorrente);
nodo* creaNodo(float cartaDaInserire);

// ------------------------
// Inserire qui le dichiarazioni delle funzioni richieste
// ------------------------

lista unisciListe(lista & l1, lista &l2);
float scorriLista(lista l);
void deallocaLista(lista &l);

// IMPORTANTE. Non modificare il main.
int main() {
  srand(time(NULL));

  lista lista1 = generaLista();
  lista lista2 = generaLista();

  cout << "Lista 1: ";
  stampaLista(lista1);
  cout << endl;

  cout << "Lista 2: ";
  stampaLista(lista2);
  cout << endl;

  lista listaUnita = unisciListe(lista1, lista2);

  cout << "Liste unite: ";
  stampaLista(listaUnita);
  cout << endl;

  float somma = scorriLista(listaUnita);

  cout << "Liste filtrate: ";
  stampaLista(listaUnita);
  cout << endl;
  cout << "Somma degli elementi > 0: " << somma << endl;

  // E' compito della funzione scorriLista liberare
  // la memoria dei nodi intermedi! Non decommentare
  // queste righe, altrimenti verrà rseba a prendervi con l'ascia.
  deallocaLista(listaUnita);

  return 0;
}

// IMPORTANTE. Non modificare questa funzione.
nodo* creaNodo(float val) {
  nodo *n = new nodo;
  n->valore = val;
  n->pred = NULL;
  n->succ = NULL;
  return n;
}

// IMPORTANTE. Non modificare questa funzione.
float randVal() {
  float valore = (float)rand() / (float)(RAND_MAX / UPPER_BOUND_VAL);
  if (rand() % 2 == 0) {
    valore *= -1;
  }

  return valore;
}

// IMPORTANTE. Non modificare questa funzione.
nodo* generaLista() {
  int size = rand() % UPPER_BOUND_DIM;

  nodo *nodoIniziale = creaNodo(randVal());
  nodo *nodoPredecente = nodoIniziale;
  nodo *nodoCorrente = NULL;

  for (int i = 1; i < size; i++) {
    nodoCorrente = creaNodo(randVal());
    nodoPredecente->succ = nodoCorrente;
    nodoCorrente->pred = nodoPredecente;
    nodoPredecente = nodoCorrente;
  }

  return nodoIniziale;
}

// IMPORTANTE. Non modificare questa funzione.
void stampaLista(nodo* nn) {
  while (nn != NULL) {
    cout << nn->valore << " ";
    nn = nn->succ;
  }
  cout << endl;
}

// ------------------------
// Inserire qui le definizioni delle funzioni richieste
// ------------------------

