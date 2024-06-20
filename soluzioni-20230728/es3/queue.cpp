#include "queue.h"
#include <cstddef>

struct _SNode {
  int val;
  struct _SNode * next;
};

struct Queue {
  _SNode * first;
  _SNode * last;
};

Queue * init() {
  Queue * res = new Queue;
  res->first = res->last = NULL;
  return res;
}

bool isEmpty(Queue * s) {
  return s->first == NULL;
}

void put(Queue * s, int i) {
  _SNode * n = new _SNode {i, NULL};
  if (s->last != NULL) {
    s->last->next = n;
  }
  s->last = n;
  if (s->first == NULL) s->first = n;
}

int get(Queue *s) {
  int r = s->first->val;
  _SNode * t = s->first;
  s->first = s->first->next;
  if (s->first == NULL) s->last = NULL;
  delete t;
  return r;
}

void quit(Queue * & s) {
  for(_SNode * l = s->first; l!=NULL;) {
    _SNode * t = l;
    l=l->next;
    delete t;
  }
  delete s;
  s = NULL;
}
