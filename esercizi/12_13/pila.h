#ifndef PILA_H
#define PILA_H

#include <iostream>
using namespace std;

struct cella {
    int indiceRiga;
    int indiceColonna;
};

struct nodo {
	cella value;
	nodo* next;
};
typedef nodo* lista;

void init();
void deinit();
bool push(cella);
bool top(cella &);
bool pop();
bool vuota();


#endif