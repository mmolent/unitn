#include <iostream>
#include <fstream>
#include "palindroma_coda.h"
#include "palindroma_pila.h"
using namespace std;

int main(int argc, char* argv[]){
    fstream input, output;
    input.open(argv[1], ios::in);
   // output.open(argv[2], ios::out);

    if(input.fail()){
        cout << "errore ad aprire il file input.txt" << endl;
        exit(1);
    }

    if(output.fail()){
        cout << "errore ad aprire il file output.txt" << endl;
        exit(1);
    }
    pila_init();
    coda_init();
    char pippo;
    bool check= true;
    int t, s;
    while(input >> pippo)
        {
            t = (int) pippo;
            s= (int) pippo;
            pila_push(t);
            coda_enqueue(t);
        }
        pila_print();
        cout << endl;
        coda_print();
        cout << endl;
    while(pila_top(t) && coda_first(s)){
    if(t==s)
        {
            pila_pop();
            coda_dequeue();
        
        }
    else
        {
            cout << "Non palindoma" << endl;
            check = false;
            break;
        }
    }
    if(check) cout << "Palindroma";
    pila_deinit();
    coda_deinit();
    return 0;
}