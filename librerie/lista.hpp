
#ifndef LISTA_HPP



#define LISTA_HPP
typedef int T;

struct nodo{
  static T val;
  static nodo* next;
};

 struct lista {
  nodo* head;
  int dim;
  lista();
  ~lista();
};

#endif
