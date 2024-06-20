#include <iostream>
#include "lista.h"

using namespace std;

const int POS_AL_SECONDO = 3;
const int DIM_COLORI = 3;
const int MAX_BAMBINI = 13;

const char* nomi[20] = {"Davide", "Valentina", "Niccolò", "Hannah", "Gabriele", "Amelia", "Riccardo", "Grace", "Simone", "Zoe", "Elia", "Julia", "Paolo", "Victoria", "Sara", "Michael", "Alessia", "Alberto", "Charlotte", "Enrico"};
const color colori[DIM_COLORI] = {rosso, verde, giallo};

// Inserire QUI sotto la dichirazione delle funzioni coloraPartecipante e cerca.
// Inserire QUI sopra la dichirazione delle funzioni coloraPartecipante e cerca.

int main() {
    lista cerchio = NULL;

    unsigned int seed = time(NULL);
    // Commentare la riga sotto per non avere sempre lo stesso seed
    seed = 1703945587;
    std::cout << "Seed: " << seed << std::endl;
    srand(seed);
    
    int numero_bambini = rand() % MAX_BAMBINI + 2;
    for (int i = 0; i < numero_bambini; i++) {
        char* nome = (char*)nomi[rand() % 18];
        if (cerca(cerchio, nome) == NULL) {
            insert_in(cerchio, nome, 0);
        } else {
            i--;
        }
    }

    cout << "Ci sono " << size(cerchio) << " bambini nella lista." << endl;
    print(cerchio);

    int i = 0;
    int durata;
    bool finished = false;

    while (!empty(cerchio) && !finished) {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Giro numero " << ++i << endl;
        
        cout << "La canzone durerà per " << (durata = rand() % 60 + 10) << " secondi." << endl;

        int sedia_rimossa = rand() % size(cerchio);
        cout << "Fermo il bambino alla sedia numero " << sedia_rimossa << "." << endl;

        lista eliminato = coloraPartecipante(cerchio, durata, sedia_rimossa);

        if (eliminato != NULL) {
            cout << eliminato->nome << " ha ricevuto il colore " << eliminato->colore << endl;
        } else {
            cout << "Tutti i bambini hanno un colore. Ho finito." << endl;
            finished = true;
        }
        print(cerchio);
    }

    // Controllo che non ci siano colori adiacenti
    for (lista m = cerchio; m != cerchio; m = m->next) {
        if (m->colore == m->next->colore) {
            cout << "ERROR: colori adiacenti!" << endl;
            exit(1);
        }
        if (m->colore == nero) {
            cout << "ERROR: C'è un colore nero!" << endl;
            exit(1);
        }
    }

    cout << "-------------------------------------------------------------" << endl;
    cout << "Tutti i bambini hanno un colore. Ho finito." << endl;

    return 0;
}

// Inserire QUI sotto la definizione delle funzioni coloraPartecipante e cerca.