#include <iostream>
#include "pila.hpp"
 
using namespace std;
 
static listaPila pila;
 
static bool pila_vuota () {//funzione privata
    return (pila == NULL);    
}
 

void pila_init() {
    pila = NULL;
}
 
 
template<typename T>
bool pila_top (T &n) {
    
    bool risultatoOperazione;
    if (pila_vuota()) {
        risultatoOperazione = false;
    }
    else {
        n=pila->value;
        risultatoOperazione = true;
    }
    return risultatoOperazione;
}
 
 
template<typename T>
bool pila_push(T n) {
    bool risultatoOperazione;
    listaPila nuovoNodo = new (nothrow) nodoPila<T>();
    if (nuovoNodo == nullptr) {
        risultatoOperazione = false;
    } else {
        nuovoNodo->value = n;
        nuovoNodo->next = pila;
        pila = nuovoNodo;
        risultatoOperazione = true;
    }
    return risultatoOperazione;
}

 
 
bool pila_pop () {
    
    bool risultatoOperazione;
    if (pila_vuota()) {
        risultatoOperazione = false;
    }
    else {
        listaPila primoNodo = pila;
        pila = pila->next;
        delete primoNodo;
        risultatoOperazione = true;
    }
    return risultatoOperazione;
}
 
void pila_deinit() {
    int tmp;
    while(pila_top(tmp)) {
        pila_pop();
    }
}
 
void pila_print() {
 
  if (!pila_vuota()) {
    listaPila nodoCorrente = pila;
    do {
      cout << nodoCorrente->value << endl;
      nodoCorrente = nodoCorrente->next;
    } while (nodoCorrente != NULL);
  }
}
