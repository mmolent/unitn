#ifndef CODA_H
#define CODA_H
 
const int MAX_DIM = 31;
 
struct nodo {
    char *nome;
    nodo *next;
};
typedef nodo *lista;
 
struct coda {
    lista tail;
    lista head;
};
 
void init();
bool enqueue(char *);
bool first(char *&);
bool dequeue();
void deinit();
void print();
 
#endif // ifndef CODA_H
 