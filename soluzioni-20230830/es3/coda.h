#ifndef CODA_H
#define CODA_H

struct pianeta {
	int identificativo;
	int carburante;
    int distanza;
	pianeta* next;
};

struct coda {
    pianeta* tail;
    pianeta* head;
};

void init();
bool enqueue(int, int, int);
bool first(int &, int &, int &);
bool dequeue();
void deinit();
void print();

#endif


