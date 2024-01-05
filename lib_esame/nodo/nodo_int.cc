#include "nodo_int.hpp"

nodo* init_nodo(){
  nodo* n = new nodo();
  n -> value = 0;
  n -> next = nullptr;
  return n;
} 

nodo* init_nodo(int value) {
  nodo* n = init_nodo();
  n -> value = value;
  return n;
}

nodo* init_nodo(int value, const nodo* n) {
  nodo* r = init_nodo(value);
  r -> next = const_cast<nodo*>(n);
  return r;
}

nodo* copy_node(const nodo* n) {
  nodo* r = init_nodo();
  r -> value = n -> value;
  r -> next = n -> next;
  return r;
}
