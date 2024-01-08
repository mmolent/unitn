#include <iostream>
#include "lista_circolare_sentinella.hpp"

//implementazione delle funzioni riferendosi ad una lista circolare con sentinella

//crea una lista vuota
void init_lista(lista & l){
  l = new nodo;
  l->next = l;
}

//delete lista
void delete_lista(lista & l){
  if(!is_empty(l)){
    nodo * tmp = l->next;
    while(tmp != l){
      nodo * tmp2 = tmp;
      tmp = tmp->next;
      delete tmp2;
    }
    delete l;
  }
}

//verificare se un lista è vuota
bool is_empty(lista l){
  return l->next == l;
}

//inserire un elemento in testa
void insert(lista & l, int value){
  nodo * tmp = new nodo;
  tmp->value = value;
  tmp->next = l->next;
  l->next = tmp;
}

//inserire un elemento in coda
void insert_tail(lista & l, int value){
  nodo * tmp = new nodo;
  tmp->value = value;
  tmp->next = l;
  nodo * tmp2 = l;
  while(tmp2->next != l){
    tmp2 = tmp2->next;
  }
  tmp2->next = tmp;
}

//inserire un elemento in ordine

void insert_ordinato(lista & l, int value){
  nodo * tmp = new nodo;
  tmp->value = value;
  nodo * tmp2 = l;
  while(tmp2->next != l && tmp2->next->value < value){
    tmp2 = tmp2->next;
  }
  tmp->next = tmp2->next;
  tmp2->next = tmp;
}

//rimuovere un elemento dalla lista
void remove(lista & l, int value){
  nodo * tmp = l;
  while(tmp->next != l && tmp->next->value != value){
    tmp = tmp->next;
  }
  if(tmp->next != l){
    nodo * tmp2 = tmp->next;
    tmp->next = tmp2->next;
    delete tmp2;
  }
}

//stampa la lista
void print_lista(lista l){
  nodo * tmp = l->next;
  while(tmp != l){
    std::cout << tmp->value << " ";
    tmp = tmp->next;
  }
  std::cout << std::endl;
}

//search di un elemento nella lista (iterativa)
nodo * search(lista l, int value){
  nodo * tmp = l->next;
  while(tmp != l && tmp->value != value){
    tmp = tmp->next;
  }
  return tmp;
}

//search di un elemento nella lista (ricorsiva)
nodo * search_ric(lista l, int value){
  if(l == l->next || l->value == value){
    return l;
  }
  return search_ric(l->next, value);
}
