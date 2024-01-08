#ifndef LISTA_CIRCOLARE_H
#define LISTA_CIRCOLARE_H

struct nodo {
    int value;
    nodo * next;
};

typedef nodo* lista;

void init_lista(lista & l);
void delete_lista(lista & l);
bool is_empty(lista l);
void insert(lista & l, int value);
void insert_tail(lista & l, int value);
void insert_ordinato(lista & l, int value);
void remove(lista & l, int value);
void print_lista(lista l);
nodo * search(lista l, int value);
nodo * search_ric(lista l, int value);

#endif 