#include <iostream>
#include <ctime>
#include <cstdlib>

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

// scrivere la definizione della funzione calcola qui sopra
