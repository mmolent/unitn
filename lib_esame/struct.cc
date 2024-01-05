

#include <iostream>

typedef nodo* lista; //lista è un puntatore a nodo
typedef nodo* pila; //pila è un puntatore a nodo
typedef nodo* coda; //coda è un puntatore a nodo

using namespace std;
struct nodo {
    int info;
    nodo* next;
};

//dunzione che inizializza un oggetto nodo a zero
void init(nodo* p) {
    p->info = 0;
    p->next = NULL;
}
//funzione che inizializza con un valore
void init(nodo* p, int val) {
    p->info = val;
    p->next = NULL;
}
//funzione che dealloca un nodo
void deinit(nodo* p) {
    delete p;
}
//funzione che dealloca una lista in maniera ricorsiva
void deinit_lista(lista& p) {
    if (p != NULL) {
       deinit_lista(p->next);
        delete p;
        p = NULL;
    }
}
//funzione che dealloca una lista in maniera iterativa
void deinit_lista_iter(lista& p) {
    nodo* q;
    while (p != NULL) {
        q = p;
        p = p->next;
        delete q;
    }
}
//funzione che conta il numero di elementi di una lista in maniera ricorsiva
int conta_ric(lista p) {
    if (p == NULL) {
        return 0;
    } else {
        return 1 + conta_ric(p->next);
    }
}
//funzioen che conta il numero di elementi di una lista in maniera iterativa
int conta(lista p) {
    int cont = 0;
    while (p != NULL) {
        cont++;
        p = p->next;
    }
    return cont;
}
//stampa di una lista ricorsivo
void stampa_ric(lista p) {
    if (p != NULL) {
        cout << p->info << endl;
        stampa_ric(p->next);
    }
}
//stampa di una lista iterativo
void stampa(lista p) {
    while (p != NULL) {
        cout << p->info << endl;
        p = p->next;
    }
}
//inverti lista
void inverti(lista& p) {
    nodo* q = NULL;
    nodo* r = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    p = q;
}

//stampa ricorsiva inversa
void stampa_ric_inv(lista p) {
    if (p != NULL) {
        stampa_ric_inv(p->next);
        cout << p->info << endl;
    }
}

//inserimento in testa
void inserisci_testa(lista& p, int val) {
    nodo* q = new nodo;
    q->info = val;
    q->next = p;
    p = q;
}
//inserimento in coda
void inserisci_coda(lista& p, int val) {
    nodo* q = new nodo;
    q->info = val;
    q->next = NULL;
    if (p == NULL) {
        p = q;
    } else {
        nodo* r = p;
        while (r->next != NULL) {
            r = r->next;
        }
        r->next = q;
    }
}

//inserimento ordinato
void inserisci_ordinato(lista& p, int val) {
    nodo* q = new nodo;
    q->info = val;
    if (p == NULL || p->info > val) {
        q->next = p;
        p = q;
    } else {
        nodo* r = p;
        while (r->next != NULL && r->next->info < val) {
            r = r->next;
        }
        q->next = r->next;
        r->next = q;
    }
}
//inserimento in posizione
void inserisci_pos(lista& p, int val, int pos) {
    nodo* q = new nodo;
    q->info = val;
    if (pos == 0) {
        q->next = p;
        p = q;
    } else {
        nodo* r = p;
        for (int i = 0; i < pos - 1 && r != NULL; i++) {
            r = r->next;
        }
        if (r != NULL) {
            q->next = r->next;
            r->next = q;
        } else {
            delete q;
        }
    }
}

//ricerca di un elemento in una lista che restituisce il puntatore al nodo che contiene l'elemento. se non presente restituisce null
nodo* ricerca(lista p, int val) {
    while (p != NULL && p->info != val) {
        p = p->next;
    }
    return p;
}
//ricerca ricorsiva
nodo* ricerca_ric(lista p, int val) {
    if (p == NULL || p->info == val) {
        return p;
    } else {
        return ricerca_ric(p->next, val);
    }
}
//

int main() {
    //utilizzo di struct
    nodo* p;
    p = &(*p);
    p = new nodo;
    p->info = 5;
    p->next = NULL;
    return 0;
}
