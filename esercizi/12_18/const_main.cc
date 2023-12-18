#include <iostream>
#include <fstream>
#include "12_18.hpp"

nodo * nuovo_nodo(int );
void stampa_lista(nodo * );
void stampa_lista_inversa(nodo * );
void inserisci_in_testa(nodo * &, int );
void inserisci_in_coda(nodo * &, int );


int main(int argc, char **argv) {
  //normalmente:
  int a = 0; // a is an integer
  const int ca = 3.14; // ca is a const integer
  //con puntatore:
  int * pa = &a; // pa is a pointer to an integer
  const int * pca = &ca; // cpa is a pointer to a const integer
  int * const cpa = pa; // pca is a const pointer to an integer, same as int const *cpa = pa;
  const int * const cpca = pa; // cpca is a const pointer to a const integer
  //con puntatore a puntatore:
  int * * ppa = &pa; // ppa is a pointer to a pointer to an integer
  int * * const cppa = ppa; // cppa is a const pointer to a pointer to an integer
  int * const * pcpa = &cpa; // pcpa is a pointer to a const pointer to an integer
  int * const * const cpcpa = &cpa; // cpcpa is a const pointer to a const pointer to an integer
  const int * * ppca = &pca; // ppca is a pointer to a pointer to a const integer
  const int * * const cppca = &pca; // cppca is a const pointer to a pointer to a const integer
  const int * const * pcpca = &cpca; // pcpca is a pointer to a const pointer to a const integer
  const int * const * const cpcpca = &cpca; // cpcpca is a const pointer to a const pointer to a const integer

  return 0;
}

nodo * nuovo_nodo(int valore){
  nodo * nuovo = new nodo;
  nuovo->value = valore;
  nuovo->next = nullptr;
  return nuovo;
}

void stampa_lista(nodo * lista){
  nodo * scorri = lista;
  while(scorri != nullptr){
    std::cout << scorri->value << " ";
    scorri = scorri->next;
  }
  std::cout << std::endl;
}

void stampa_lista_inversa(nodo * lista){
  if(lista == nullptr){
    return;
  }
  stampa_lista_inversa(lista->next);
  std::cout << lista->value << " ";
}

