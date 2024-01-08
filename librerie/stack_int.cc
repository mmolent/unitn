#include "stack_int.hpp"

Stack init_stack() {
  Stack s = new stack();
  s -> head = nullptr;
  return s;
}

Stack init_stack(const stack n) {
  Stack s = new stack();
  s -> head = n.head;
  return s;
}

Stack init_stack(const Stack s) {
  Stack r = new stack();
  r -> head = s -> head;
  return r;
}

void deinit_stack(Stack &s) {
  while(s -> head != nullptr) {
    nodo* tmp = s -> head;
    s -> head = s -> head -> next;
    delete tmp;
  }
  delete s;
  s = nullptr;
}

void push(Stack &s, int value) {
  nodo* n = init_nodo(value, s -> head);
  s -> head = n;
}

int pop(Stack &s) {
  if(s -> head == nullptr) {
    return 0;
  }
  int value = s -> head -> value;
  nodo* tmp = s -> head;
  s -> head = s -> head -> next;
  delete tmp;
  return value;
}

int top(const Stack s) {
  if(s -> head == nullptr) {
    return 0;
  }
  return s -> head -> value;
}

bool is_empty(const Stack s) {
  return s -> head == nullptr;
}

int size(const Stack s) {
  int count = 0;
  nodo* tmp = s -> head;
  while(tmp != nullptr) {
    count++;
    tmp = tmp -> next;
  }
  return count;
}

