
#ifndef LISTA_HPP



#define LISTA_HPP
typedef int T;

struct nodo{
  T val;
  nodo* next;
  nodo* prev;
};

 struct lista {
  nodo* head;
  int dim;

  lista();
  lista(T );
  ~lista();
  void lista_print();
  void lista_add(T val);
};

static void lista_deinit(nodo* l){
  if(l != nullptr) {
    lista_deinit(l -> next);
    delete l;
  }
}

#endif
