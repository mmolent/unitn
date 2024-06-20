#include <iostream>
#include <cstdlib>
#include "coda.h"

using namespace std;

// Implementare la funzione sottostante come da consegna:
// - 'numeroDiPianeti' e` il numero di pianeti, o anche chiamato 'n'
// - usare le funzioni definite in "coda.h" per interagire con la coda dei pianeti.
int trovaIlPianetaDiPartenza(int numeroDiPianeti);

void stampaPercorso(int identificativoPianetaDiPartenza) {
    int identificativoPianetaCorrente;
    int carburantePianetaCorrente;
    int distanzaPianetaCorrente;
    do {
        first(identificativoPianetaCorrente, carburantePianetaCorrente, distanzaPianetaCorrente);
    } while (identificativoPianetaDiPartenza != identificativoPianetaCorrente);

    int carburanteCorrente = 1;
    do {
        carburanteCorrente += carburantePianetaCorrente;
        cout << "Rifornimento al pianeta \"" << identificativoPianetaCorrente << "\", carburante attuale " << carburanteCorrente << endl;
        carburanteCorrente -= distanzaPianetaCorrente;
        dequeue();
        enqueue(identificativoPianetaCorrente, carburantePianetaCorrente, distanzaPianetaCorrente);
        first(identificativoPianetaCorrente, carburantePianetaCorrente, distanzaPianetaCorrente);
        cout << "Viaggio al pianeta \"" << identificativoPianetaCorrente << "\", carburante rimasto " << carburanteCorrente << endl;
    } while (identificativoPianetaDiPartenza != identificativoPianetaCorrente);
}

int main() {

    // E' possibile modificare TEMPORANEAMENTE la funzione main (e.g., per
    // aggiungere la randomicità della generazione dei pianeti e fare testing
    // della soluzione implementata). Prima della consegna, ricordarsi di
    // ripristinare il codice originale della funzione main
    srand(1);
    init();
    int numeroDiPianeti = rand() % 4+2;
    for (int i = 1 ; i <= numeroDiPianeti ; i++) {
        int identificativo = rand() % (9999 - 1000 + 1) + 1000;
        int carburante = rand() % 5+1;
        int distanza = rand() % 5+1;
        enqueue(identificativo, carburante, distanza);
    }

    cout << "Stampa dei pianeti in senso orario" << endl;
    print();

    int pianetaDiPartenza = trovaIlPianetaDiPartenza(numeroDiPianeti);
    if (pianetaDiPartenza == -1) {
        cout << "Non e` possibile completare il percorso tra i pianeti" << endl;
    } else {
        cout << "Il pianeta di partenza e` il pianeta con identificativo " << pianetaDiPartenza << endl;
        stampaPercorso(pianetaDiPartenza);
    }
    deinit();

    return 0;
}


bool trovaIlPianetaDiPartenza_rec(int& identificativoPianetaDiPartenza, int carburanteCorrente, int numeroDiPianeti, int tentativi) {

    // Prendiamo i dati del pianeta corrente
    int identificativoPianetaCorrente;
    int carburantePianetaCorrente;
    int distanzaPianetaCorrente;
    first(identificativoPianetaCorrente, carburantePianetaCorrente, distanzaPianetaCorrente);


    // CASO BASE 1: siamo arrivati in fondo al cerchio
    if (identificativoPianetaDiPartenza == identificativoPianetaCorrente) {
        return true;
    }
    // CASO BASE 2: abbiamo esaurito i tentativi
    else if (identificativoPianetaDiPartenza == 0 && numeroDiPianeti == tentativi) {
        identificativoPianetaDiPartenza = -1;
        return false;
    }
    // INDUZIONE 1: stiamo iniziando un nuovo viaggio
    else if (identificativoPianetaDiPartenza == 0) {
        identificativoPianetaDiPartenza = identificativoPianetaCorrente;

        // Viaggia verso il prossimo pianeta
        carburanteCorrente += (carburantePianetaCorrente - distanzaPianetaCorrente);
        dequeue();
        enqueue(identificativoPianetaCorrente, carburantePianetaCorrente, distanzaPianetaCorrente);

        // Se questo viaggio va a buon fine e tutti gli altri viaggi vanno a buon fine
        bool viaggioValido = trovaIlPianetaDiPartenza_rec(identificativoPianetaDiPartenza, carburanteCorrente, numeroDiPianeti, tentativi);
        if ((carburanteCorrente >= 0) && viaggioValido) {
            return true;
        }
        // Altrimenti, resetta l'identificativoPianetaDiPartenza e carburante,
        // incrementa i tentativi e riprova con il pianeta successivo
        else {
            identificativoPianetaDiPartenza = 0;
            tentativi++;
            dequeue();
            enqueue(identificativoPianetaCorrente, carburantePianetaCorrente, distanzaPianetaCorrente);
            return trovaIlPianetaDiPartenza_rec(identificativoPianetaDiPartenza, 1, numeroDiPianeti, tentativi);
        }
    }
    // INDUZIONE 2: stiamo viaggiando da un pianeta all'altro
    else {
        carburanteCorrente += (carburantePianetaCorrente - distanzaPianetaCorrente);
        dequeue();
        enqueue(identificativoPianetaCorrente, carburantePianetaCorrente, distanzaPianetaCorrente);
        bool viaggioValido = trovaIlPianetaDiPartenza_rec(identificativoPianetaDiPartenza, carburanteCorrente, numeroDiPianeti, tentativi);
        return (carburanteCorrente >= 0) && viaggioValido;
    }
}

int trovaIlPianetaDiPartenza(int numeroDiPianeti) {
    int identificativoPianetaDiPartenza = 0;
    trovaIlPianetaDiPartenza_rec(identificativoPianetaDiPartenza, 1, numeroDiPianeti, 0);
    return identificativoPianetaDiPartenza;
}
