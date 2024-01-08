#include <iostream>
#include "coda_lista_concatenata.h"
#include <cstring>

using namespace std;

bool uguali(char* nome, int i){
    char* t = new char[31];
    bool check= false;
    while(i>=0)
    {
        first(t);
        if(strcmp(t, nome))
            {
                enqueue(t);
                dequeue();
                i--;
            }
        else {
            check= true;
            i--;
            }
    }
    delete[] t;
    return check;
}

int main(){
    

    init();
    int val = 0;
    int conta=0;
    char* nome = new char[31];
    while(val>=0 && val<=3)
    {
        cout << endl << "Menu: 1: aggiungi" << endl << "2: smaltisci" << endl << "3: stampa situazione" << endl << "4 per uscire" << endl;
        cin >> val;

        switch(val){
        case 0: break;

        case 1: {
            cout << "Come si chiama il nuovo arrivato?: " << endl;
            cin >> nome;
            if(!uguali(nome, conta)) {enqueue(nome); conta++;}
            else cout << "Nome gia presente, non e' posibile inserirlo" << endl;
            break;
        }
        
        case 2: {
            if(!dequeue()) cout << "La lista e' vuota, impossibile smaltire." << endl;
            else conta--;
            break;
        }

        case 3: {
            print();
            break;
        }
    }
    
    }
    delete[] nome;
    return 0;
}