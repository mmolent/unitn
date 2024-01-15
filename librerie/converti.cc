

#include <iostream>

using namespace std;

// funzione che converte un numero da string a int
int converti_string_int(char *numero) {
  int risultato = 0; // risultato della conversione
  int potenza = 1;   // potenza della base 10 da moltiplicare per ogni cifra
  int i = 0;         // indice per scorrere il numero
  while (
      numero[i] !=
      '\0') { // scorro il numero fino a che non trovo il carattere terminatore
    i++;
  }
  i--; // decremento l'indice perche' l'ultimo carattere e' il carattere
       // terminatore
  while (i >= 0) { // scorro il numero al contrario
    risultato += (numero[i] - '0') * potenza;
    potenza *= 10;
    i--;
  }
  return risultato;
}

// funzione che converte un numero da una base ad un'altra base
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

int converti_base(char *numero, int base_partenza, int base_arrivo) {
  return converti_base(converti_string_int(numero), base_partenza, base_arrivo);
}

int converti_base_ricorsivo(int numero, int base_partenza, int base_arrivo) {
  if (numero == 0) {
    return 0;
  }
  return (numero % base_arrivo) + converti_base_ricorsivo(numero / base_arrivo,
                                                          base_partenza,
                                                          base_arrivo) *
                                      base_partenza;
}

char *converti_base_str(int numero, int base_partenza, int base_arrivo) {
  int length = 1; // Initialize the length to 1 for the null terminator
  int temp = numero;
  while (temp > 0) {
    length++;
    temp /= base_arrivo;
  }
  char *risultato = new char[length]; // Allocate memory for the risultato array
                                      // with the exact length
  int i = 0;
  while (numero > 0) {
    risultato[i] = (numero % base_arrivo) + '0';
    numero /= base_arrivo;
    i++;
  }
  risultato[i] = '\0';
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
  char *risultato = converti_base_str(
      numero, base_partenza, base_arrivo); // Store the returned risultato array
  cout << "Il numero " << numero << " in base " << base_partenza
       << " e' uguale a " << risultato << " in base " << base_arrivo << endl;
  delete[] risultato; // Deallocate the memory for the risultato array
  return 0;
}
