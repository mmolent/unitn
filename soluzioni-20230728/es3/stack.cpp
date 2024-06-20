#include "stack.h"
#include <cstddef>

struct _SNode {
  int val;
  struct _SNode * next;
};

struct Stack {
  _SNode * first;
};

Stack * init() {
  Stack * res = new Stack;
  res->first = NULL;
  return res;
}

bool isEmpty(Stack * s) {
  return s->first == NULL;
}

void push(Stack * s, int i) {
  s->first = new _SNode {i, s->first};
}

int pop(Stack *s) {
  int r = s->first->val;
  _SNode * t = s->first;
  s->first = s->first->next;
  delete t;
  return r;
}

void quit(Stack * & s) {
  for(_SNode * l = s->first; l!=NULL;) {
    _SNode * t = l;
    l=l->next;
    delete t;
  }
  delete s;
  s = NULL;
}
