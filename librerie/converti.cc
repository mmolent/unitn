//funzione che converte un numero da una base ad un'altra base

#include <iostream>

using namespace std;

int converti_base(int numero, int base_partenza, int base_arrivo) {
    int risultato = 0;
    int potenza = 1;
    while (numero > 0) {
        risultato += (numero % base_arrivo) * potenza;
        numero /= base_arrivo;
        potenza *= base_partenza;
    }
    return risultato;
}
int main() {
    int numero, base_partenza, base_arrivo;
    cout << "Inserisci il numero da convertire: ";
    cin >> numero;
    cout << "Inserisci la base di partenza: ";
    cin >> base_partenza;
    cout << "Inserisci la base di arrivo: ";
    cin >> base_arrivo;
    cout << "Il numero " << numero << " in base " << base_partenza << " e' uguale a " << converti_base(numero, base_partenza, base_arrivo) << " in base " << base_arrivo << endl;
    return 0;
}