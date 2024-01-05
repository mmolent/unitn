#ifndef NODO_HPP
#define NODO_HPP
#define N_NODE 1
#if N_NODE == 1
struct nodo {
  int value;
  nodo* next;
};
#endif
#if N_NODE == 2
struct nodo {
  int value;
  nodo* next;

  
  nodo() : value(0), next(nullptr) {} //costruttore di default
  nodo(int v) : value(v), next(nullptr) {} //costruttore con un argomento
  nodo(int v, nodo* n) : value(v), next(n) {} //costruttore

  nodo(const nodo& n) : value(n.value), next(n.next) {} //costruttore di copia
  nodo& operator=(const nodo& n) { //operatore di assegnazione
    if(this != &n) {
      value = n.value;
      next = n.next;
    }
    return *this;
  }
  ~nodo() { //distruttore
    value = 0;
    next = nullptr;
  }

};
#endif
nodo* init_nodo(); //restituisce un nodo inizializzato con valore zero
nodo* init_nodo(int ); //restituisce un puntatore a nodo con vaolre passato come arg funzione
nodo* init_nodo(int, const nodo*); //crea un nodo con un valore passato per argomento e che punta ad un nodo passato per argomento

void deinit_nodo(nodo* & n); //dealloca un nodo e modifica a null il puntarore usato per allocarlo

nodo* copy_nodo(const nodo* n); //restituisce un puntatore ad un nodo avente lo stesso valore del nodo passato
void copy_node(const nodo* n1, nodo* &n2); //copia nel secondo nodo il primo nodo passato per argomento

#endif 
