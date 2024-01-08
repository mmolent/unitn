#include <iostream>

using namespace std;

typedef struct cifra{
    int valore;
    cifra * next; 
}n;

static n * cifre = new cifra[10];

void init_n(){
    for(int i = 0; i < 10; i++){
        cifre[i].valore = i;
        cifre[i].next = nullptr;
    }
}