#include <iostream>
#include "coda.h"

using namespace std;

static coda Q;

static bool vuota() {
  return (Q.head == NULL);
}

void init() {
  Q.head = NULL;
}

bool enqueue(int identificativo, int carburante, int distanza) {
  
    bool risultatoOperazione;
    pianeta* nuovoNodo = new (nothrow) pianeta;
    if (nuovoNodo==NULL) {
        risultatoOperazione = false;
    }
    else {
        nuovoNodo->identificativo=identificativo;
        nuovoNodo->carburante=carburante;
        nuovoNodo->distanza=distanza;
        nuovoNodo->next=NULL;
        if (vuota()) {
            Q.head=nuovoNodo;
        }
        else { 
            Q.tail->next=nuovoNodo;
        }
        Q.tail=nuovoNodo;
        risultatoOperazione = true;
    }
    return risultatoOperazione;
}


bool first(int &identificativo, int &carburante, int &distanza) { 
    bool risultatoOperazione;
    if (vuota()) {
        risultatoOperazione = false;
    }
    else {
        identificativo = Q.head->identificativo;
        carburante = Q.head->carburante;
        distanza = Q.head->distanza;
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
        pianeta* primoNodo;
        primoNodo = Q.head;
        Q.head = Q.head->next;
        delete primoNodo; 
        risultatoOperazione = true;
    }
    return risultatoOperazione;
}

void deinit() {
    int tmp1, tmp2, tmp3;
	while(first(tmp1, tmp2, tmp3)) {
		dequeue();
	}
}

void print() {

  if (!vuota()) {
    pianeta* nodoCorrente=Q.head;
    do {
      cout << "Pianeta \"" << nodoCorrente->identificativo << "\", carburante disponibile " << nodoCorrente->carburante << ", distanza dal prossimo pianeta " << nodoCorrente->distanza << endl;
      nodoCorrente = nodoCorrente->next;
    } while (nodoCorrente != NULL);
  }
}