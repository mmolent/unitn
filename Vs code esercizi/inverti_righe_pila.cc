#include <iostream>
#include <fstream>
#include "pila_statica.h"
using namespace std;

int main(int argc, char* argv[]){
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if(input.fail()){
        cout << "errore ad aprire il file input.txt" << endl;
        exit(1);
    }

    if(output.fail()){
        cout << "errore ad aprire il file output.txt" << endl;
        exit(1);
    }

    int t;
    int car;
    pila_init();
    while(input >> car)
        pila_push(car);
    
    while(pila_top(t)){
        output << t << endl;
        pila_pop();
        }
    
    input.close();
    output.close();

    return 0;
}