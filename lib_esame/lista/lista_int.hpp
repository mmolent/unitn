#ifndef LISTA_HPP
#define LISTA_HPP
#include "nodo_int.hpp"
#include <iostream>
typedef nodo* lista;
typedef const nodo* const_lista;

//deinizializza la lista e dealloca la memoria
void deinit_lista(lista &l);
//print della lista
void print_lista(const lista l);
//aggiunta elememnto in lista con un dto valore in coda
void addtailelem_lista(lista &l, int value);
//aggiunta elememnto in lista con un dto valore in testa
void addheadelem_lista(lista &l, int value);
//inserimento di un valore ordinato in una lista ordinata
void addorderedelem_lista(lista &l, int value);
//concatena due liste
void concat_lista(lista &l1, lista &l2);
//rimuove l'elemento in testa alla lista
void removeheadelem_lista(lista &l);
//rimuove l'elemento in coda alla lista
void removetailelem_lista(lista &l);
//rimuovere l'elelmento con indirizzo passato per argomento
void removeelem_lista(lista &l, int value);
//restituisce il valore dell'elemento in testa alla lista
int getheadelem_lista(const nodo* const &l);
//restituisce il valore dell'elemento in coda alla lista
int gettailelem_lista(const lista l);
//restituisce true se la lista è vuota, false altrimenti
bool is_empty_lista(const lista l);
//restituisce la dimensione della lista
int size_lista(lista l);
//restituisce una copia della lista passata per argomento
lista copy_lista(const lista l);
//riordinamento della lista
void sort_lista(lista &l);
//restituisce true se la lista è ordinata, false altrimenti
bool is_sorted_lista(const lista l);
//restituisce l'indirizzo del nodo che contiene il valore passato per argomento
lista findvalue_lista(const lista l, int value);
//funzione che stampa l'intero oggetto lista
void print_lista(const lista l);
//overriding dell'operatore << per stampare la lista
ostream& operator<<(ostream& os, const lista& l);
#endif

//pass by reference to change
//const to avoid changing
