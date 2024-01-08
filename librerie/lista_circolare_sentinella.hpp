
#ifndef LISTA_CIRCOLARE_SENTINELLA_HPP
#define LISTA_CIRCOLARE_SENTINELLA_HPP
//header di lista circolare con sentinella

struct nodo{
  int value;
  nodo * next;
};

typedef nodo * lista;

//crea una lista vuota
void init_lista(lista & l);
//delete lista
void delete_lista(lista & l);
//verificare se un lista è vuota
bool is_empty(lista l);
//inserire un elemento in testa
void insert(lista & l, int value);
//inserire un elemento in coda
void insert_tail(lista & l, int value);
//inserire un elemento in ordine
void insert_ordinato(lista & l, int value);
//rimuovere un elemento dalla lista
void remove(lista & l, int value);
//stampa la lista
void print_lista(lista l);
//search di un elemento nella lista (iterativa)
nodo * search(lista l, int value);
//search di un elemento nella lista (ricorsiva)
nodo * search_ric(lista l, int value);
#endif

