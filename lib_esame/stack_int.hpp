#include "nodo_int.hpp"
#ifndef STACK_HPP
#define STACK_HPP


typedef stack* Stack;
typedef nodo* stack;

#if N_NODE == 1
struct stack {
  nodo* head;
};
#endif

#if N_NODE == 2
struct stack {
  nodo* head;
  stack() : head(nullptr) {}
  stack(nodo* n) : head(n) {}
  stack(const stack& s) : head(s.head) {}
  stack& operator=(const stack& s) {
    if(this != &s) {
      head = s.head;
    }
    return *this;
  }
  ~stack() {
    while(head != nullptr) {
      nodo* tmp = head;
      head = head -> next;
      delete tmp;
    }   
    head = nullptr;
  }
};
#endif


Stack init_stack();
Stack init_stack(const stack n);
Stack init_stack(const Stack s);
void deinit_stack(Stack &s);

//metodi principali per lo stack
void push(Stack &s, int value); //inserisce un elemento in cima allo stack
int pop(Stack &s); //rimuove un elemento dalla cima dello stack
int top(const Stack s); //restituisce il valore dell'elemento in cima allo stack
bool is_empty(const Stack s); //restituisce true se lo stack è vuoto, false altrimenti
int size(const Stack s); //restituisce la dimensione dello stack


#endif