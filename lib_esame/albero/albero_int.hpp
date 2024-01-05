//albero di nodi interi

#ifndef ALBERO_HPP
#define ALBERO_HPP
#include <iostream>
typedef nodo* Albero;


struct nodo {
  int value;
  nodo* left;
  nodo* right;
};
#endif
//init_albero
Albero init_albero();
Albero init_albero(int value);
//deinti_albero
void deinit_albero(Albero &a);
//metodi principali
void insert(Albero &a, int value);
//funzione che stampa l'albero in modo da vedere le identazioni ecc dalla root alla foglia
void print_identata(const Albero a);
bool search(const Albero a, int value);
nodo* search_nodo(const Albero a, int value);
void print(const Albero a);
void inorder(const Albero a);
void preorder(const Albero a);
void postorder(const Albero a);
int max(const Albero a);
int min(const Albero a);
int dim_albero(const Albero a);
int depth(const Albero a);
bool is_balanced(const Albero a);
bool is_complete(const Albero a);