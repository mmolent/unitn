#include <iostream>
#include <cstdlib>
#include "coda.h"

using namespace std;

int trovaIlPianetaDiPartenza(int numeroDiPianeti);

void stampaPercorso(int identificativoPianetaDiPartenza) {
    int identificativoPianetaCorrente;
    int carburantePianetaCorrente;
    int distanzaPianetaCorrente;
    do {
        first(identificativoPianetaCorrente, carburantePianetaCorrente, distanzaPianetaCorrente);
    } while (identificativoPianetaDiPartenza != identificativoPianetaCorrente);

    int carburanteCorrente = 0;
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



// Implementare la funzione sottostante come da consegna:
int trovaIlPianetaDiPartenza(int numeroDiPianeti) {
    // E' possibile invocare una ulteriore funzione
    // ricorsiva che prende come parametri formali:
    //   * una variabile intera (passata per riferimento) per ritornare
    //     l'identificativo del pianeta di partenza (oppure -1);
    //   * una variabile intera per il carburante rimasto all'astronave;
    //   * una variabile intera per il numero totale di pianeti;
    //   * una variabile intera che conti il numero di tentativi
    //     fatti per trovare un pianeta di partenza adatto.
    // Per esempio:
    int identificativoPianetaDiPartenza = ;   // E' possibile inizializzare con un valore apposito
    int carburanteIniziale = ;                // Inizializzare con il carburante presente all'inizio del viaggio
    trovaIlPianetaDiPartenza_rec(identificativoPianetaDiPartenza, carburanteIniziale, numeroDiPianeti, 0);
    return identificativoPianetaDiPartenza;
}


// La funzione "trovaIlPianetaDiPartenza_rec" potrebbe avere un valore
// di ritorno booleano: "true" se il carburante e` sufficiente per il
// viaggio al pianeta successivo, "false" altrimenti
bool trovaIlPianetaDiPartenza_rec(int& identificativoPianetaDiPartenza, int carburanteCorrente, int numeroDiPianeti, int tentativi) {

    // Prendere i dati del pianeta corrente
    int identificativoPianetaCorrente;
    int carburantePianetaCorrente;
    int distanzaPianetaCorrente;
    first(identificativoPianetaCorrente, carburantePianetaCorrente, distanzaPianetaCorrente);


    // CASO BASE 1: L'astronave ha fatto un giro completo dei pianeti
    //              (per esempio, l'identificativo del pianeta corrente e` uguale a quello di partenza)
    if ( /* condizione */ ) {
        // 1. ritornare il valore booleano corretto
    }



    // CASO BASE 2: Sono stati esauriti i tentativi senza trovare un pianeta di partenza adatto
    //              (per esempio, "tentativi" e` uguale a "numeroDiPianeti")
    else if ( /* condizione */ ) {
        // 1. settare "identificativoPianetaDiPartenza = -1;"
        // 2. ritornare il valore booleano corretto
    }



    // INDUZIONE 1: L'astronave sta iniziando un nuovo viaggio
    //              (per esempio, la variabile "identificativoPianetaDiPartenza" ha un valore apposito)
    else if ( /* condizione */ ) {
        // 1. settare "identificativoPianetaDiPartenza = identificativoPianetaCorrente;"
        // 2. aggiornare il carburante corrente, controllando se e` sufficiente
        //    per il viaggio al pianeta successivo
        // 3. modificare opportunamente la coda (per esempio, spostando il pianeta
        //    corrente in fondo alla coda con le funzioni dequeue/enqueue)
        // 4. invocare ricorsivamente la funzione "trovaIlPianetaDiPartenza_rec",
        //    ricordandone il valore di ritorno
        // 5. se il carburante corrente e` sufficiente per il viaggio al pianeta successivo
        //    e la funzione "trovaIlPianetaDiPartenza_rec" ha ritornato "true", allora il
        //    pianeta corrente e` un valido pianeta di partenza. Altrimenti:
        //    5.1 resettare il valore di "identificativoPianetaDiPartenza"
        //    5.2 incrementare il numero di tentativi di 1
        //    5.3 spostarsi al pianeta successivo (dequeue/enqueue)
        //    5.4 settare il carburante presente all'inizio del viaggio
        //    5.5 invocare ricorsivamente "trovaIlPianetaDiPartenza_rec"
    }



    // INDUZIONE 2: l'astronave sta viaggiando da un pianeta all'altro
    else {
        // 1. aggiornare il carburante corrente, controllando se e` sufficiente
        //    per il viaggio al pianeta successivo
        // 2. modificare opportunamente la coda (per esempio, spostando il pianeta
        //    corrente in fondo alla coda con le funzioni dequeue/enqueue)
        // 3. invocare ricorsivamente la funzione "trovaIlPianetaDiPartenza_rec",
        //    ricordandone il valore di ritorno
        // 4. ritornare un valore booleano che dica se il viaggio e` fattibile oppure
        //    no (per esempio, la congiunzione logica AND fra il valore tornato dalla
        //    funzione "trovaIlPianetaDiPartenza_rec" chiamata ricorsivamente e il
        //    controllo fatto sul carburante)
    }
}
