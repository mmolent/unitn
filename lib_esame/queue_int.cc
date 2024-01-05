#include "queue_int.hpp"

Queue init_queue() {
  Queue q = new queue();
  q -> head = nullptr;
  q -> tail = nullptr;
  return q;
}

Queue init_queue(const queue q) {
  Queue r = new queue();
  r -> head = const_cast<nodo*>(q.head);
  r -> tail = const_cast<nodo*>(q.tail);
  return r;
}

Queue init_queue(const Queue q) {
  Queue r = new queue();
  r -> head = q -> head;
  r -> tail = q -> tail;
  return r;
}

void deinit_queue(Queue &q) {
  while(q -> head != nullptr) {
    nodo* tmp = q -> head;
    q -> head = q -> head -> next;
    delete tmp;
  }
  delete q;
  q = nullptr;
}

void enqueue(Queue &q, int value) {
  nodo* n = init_nodo(value);
  if(q -> head == nullptr) {
    q -> head = n;
    q -> tail = n;
  } else {
    q -> tail -> next = n;
    q -> tail = n;
  }
}

int dequeue(Queue &q) {
  if(q -> head == nullptr) {
    return 0;
  }
  int value = q -> head -> value;
  nodo* tmp = q -> head;
  q -> head = q -> head -> next;
  delete tmp;
  return value;
}

int front(const Queue q) {
  if(q -> head == nullptr) {
    return 0;
  }
  return q -> head -> value;
}

bool is_empty(const Queue q) {
  return q -> head == nullptr;
}

int size(const Queue q) {
  int count = 0;
  nodo* tmp = q -> head;
  while(tmp != nullptr) {
    count++;
    tmp = tmp -> next;
  }
  return count;
}