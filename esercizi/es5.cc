/*
Scrivere un programma che, data una parola in input (massimo 100
caratteri), dica se è palindroma oppure no usando una pila e/o una coda.
Nota: non potete sfruttare la conoscenza della lunghezza della parola
(non potete nemmeno calcolarla)
*/

#include <iostream>
#include "../pila.hpp"
#include "../coda.hpp"

using namespace std;

int main (int argc, char** argv){
    coda_init();
    pila_init();

    char parola [] = "abba";

    cout << parola<<endl;

    int i = 0;

    int numero, n1, n2;

    bool palindroma = false;

    while(parola[i] != '\0'){
        numero = (int)(parola[i]);
        pila_push(numero);
        coda_enqueue(numero);
        i++;
    }

    while(coda_first(numero)){
        coda_first(n1);
        pila_top(n2);
        cout << "TOP = " << n1 <<endl;
        cout << "FIRST = " << n2 <<endl;
        if(n1 == n2){
            palindroma = true;
        }
        else{
            palindroma = false;
        }
        coda_dequeue();
        pila_pop();
    }
    if(palindroma){
        cout << "La parola " << parola << " e' palindroma;" << endl;
    }
    else {
        cout << "La parola " << parola << " NON e' palindroma;" << endl;
    }

    coda_deinit();
    pila_deinit();
    return 0;
}
