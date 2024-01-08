#include <iostream>
#include <cstring>
#include "coda_lista_concatenata.h"
 
using namespace std;
 
static coda Q;
 
static bool vuota() {
    return Q.head == NULL;
}
 
void init() {
    Q.head = NULL;
}
 
bool enqueue(char *n) {
    bool  risultatoOperazione;
    lista nuovoNodo = new (nothrow) nodo;
    char *tmp       = new (nothrow) char[MAX_DIM];
 
    if (nuovoNodo == NULL) {
        risultatoOperazione = false;
    }
    else {
        strcpy(tmp, n);
        nuovoNodo->nome = tmp;
        nuovoNodo->next = NULL;
 
        if (vuota()) {
            Q.head = nuovoNodo;
        }
        else {
            Q.tail->next = nuovoNodo;
        }
        Q.tail              = nuovoNodo;
        risultatoOperazione = true;
    }
    return risultatoOperazione;
}
 
bool first(char *& n) {
    bool risultatoOperazione;
 
    if (vuota()) {
        risultatoOperazione = false;
    }
    else {
        n                   = Q.head->nome;
        risultatoOperazione = true;
    }
    return risultatoOperazione;
}
 
bool dequeue() {
    bool risultatoOperazione;
 
    if (vuota()) {
        risultatoOperazione = false;
    }
    else {
        lista primoNodo;
        primoNodo = Q.head;
        Q.head    = Q.head->next;
        delete primoNodo;
        risultatoOperazione = true;
    }
    return risultatoOperazione;
}
 
void deinit() {
    char *tmp;
 
    while (first(tmp)) {
        delete[] tmp;
        dequeue();
    }
}
 
void print() {
    if (!vuota()) {
        lista nodoCorrente = Q.head;
 
        do {
            cout << nodoCorrente->nome << endl;
            nodoCorrente = nodoCorrente->next;
        } while (nodoCorrente != NULL);
    }
}
 