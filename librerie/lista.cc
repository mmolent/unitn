#include <iostream>
#include <new>
#include "lista.hpp"
lista::lista() {
  this -> head = nullptr;
  this -> dim = 0;
};

lista::lista(T val) {
  nodo* h = new (std::nothrow) nodo{val, nullptr, nullptr};
  if (h != nullptr) {
    this -> head = h; 
    this -> dim = 1;
  }
}

lista::~lista() {
  lista_deinit(this -> head);
  delete this;
}

void lista::lista_print() {
  nodo* t = this -> head;
  while (t != nullptr){
    std::cout << t -> val << " ";
    t = t -> next;
  }
  std::cout << std::endl;
}
