#include <iostream>
#include <fstream>
#include "pila_con_lista_concatenata.h"
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

    pila_init;
    char car;
    int t;
    bool fatto = false;
    while(input>>car){
        if(car=='(') pila_push(1);
        else {
            if(!pila_top(t))
                {
                    output << "NO"<< endl;
                    fatto = true;
                    break;
                }
            else
                {
                    pila_pop();
                }
        }
    }

    pila_print();

    if(pila_top(t) && !fatto)
        {
            output << "NO"<< endl;
            pila_deinit();
        }
    else if(!fatto)
        output << "YES" << endl;

    input.close();
    output.close();


return 0;
}