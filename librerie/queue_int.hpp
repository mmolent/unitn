#include "nodo_int.hpp"
#ifndef QUEUE_HPP
#define QUEUE_HPP

typedef queue* Queue;
typedef nodo* queue;

#if N_NODE == 1
struct queue {
  nodo* head;
  nodo* tail;
};
#endif

#if N_NODE == 2
struct queue {
  nodo* head;
  nodo* tail;
  queue() : head(nullptr), tail(nullptr) {}
  queue(nodo* n) : head(n), tail(n) {}
  queue(const queue& q) : head(q.head), tail(q.tail) {}
  queue& operator=(const queue& q) {
    if(this != &q) {
      head = q.head;
      tail = q.tail;
    }
    return *this;
  }
  ~queue() {
    while(head != nullptr) {
      nodo* tmp = head;
      head = head -> next;
      delete tmp;
    }   
    head = nullptr;
    tail = nullptr;
  }
};
#endif
Queue init_queue();
Queue init_queue(const queue);
Queue init_queue(const Queue);
void deinit_queue(Queue &);

//funzioni principali per la coda
void enqueue(Queue &, int); //inserisce un elemento in coda alla coda
int dequeue(Queue &); //rimuove un elemento dalla testa della coda
int front(const Queue); //restituisce il valore dell'elemento in testa alla coda
bool is_empty(const Queue); //restituisce true se la coda è vuota, false altrimenti
int size(const Queue); //restituisce la dimensione della coda


#endif