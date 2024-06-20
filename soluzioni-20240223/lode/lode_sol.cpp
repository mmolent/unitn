#include <iostream>
#include <ctime>
#include <cstdlib>

#define SOLUZIONE_EFFICIENTE 1

void print_array(int arr[], int size, int N, bool modulo = false) {
    for (int i = 0; i < size; i++) {
        std::cout << (modulo ? arr[i] % N : arr[i]) << " ";
    }
    std::cout << std::endl;
}

void swap(int & a, int & b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// scrivere la dichiarazione della funzione calcola qui sotto

void calcola(int arr[], int size, int N);

// scrivere la dichiarazione della funzione calcola qui sopra

int main() {
    int N;
    const int size = 10;
    int * arr = new int [size];
    unsigned int seed = time(0);
    // commentare riga sotto per comportamento randomico
    seed = 1708114916;
    std::cout << "Seed: " << seed << std::endl;
    srand(seed);
    N = rand() % 100;
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
    std::cout << "N = " << N << std::endl;
    std::cout << "Array unordered: " << std::endl;
    print_array(arr, size, N);
    std::cout << "Array unordered (modulo): " << std::endl;
    print_array(arr, size, N, true);
    calcola(arr, size, N);
    std::cout << "Array ordered: " << std::endl;
    print_array(arr, size, N);
    std::cout << "Array ordered (modulo): " << std::endl;
    print_array(arr, size, N, true);
    delete [] arr;
    return 0;
}

// scrivere la definizione della funzione calcola qui sotto
void calcola(int arr[], int size, int N) {
#if SOLUZIONE_EFFICIENTE
    // variante del selection sort che sfrutta il fatto che 
    // il modulo di N è da 0 a N-1, e che gli elementi che hanno modulo
    // uguale a N-1 sono già ordinati e quindi ultima iterazione non e' necessaria  
    int M = N-1; // N-1 perchè il modulo di N è da 0 a N-1
    int d = 0;
    for (int m = 0; m < M; m++) { // Non e' necessario calcolare 
                                  // l'ultimo gruppo in quanto è già calcolato
      for (int i = d; i < size; i++) {
        if (arr[i] % N == m) {
          swap(arr[d], arr[i]);
          d++;
        }
      }
    }
 #else 
    // Bubble sort  inefficiente
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (arr[i] % N > arr[j] % N) {
                swap(arr[i], arr[j]);
            }
        }
    }
#endif
}
// scrivere la definizione della funzione calcola qui sopra
