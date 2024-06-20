#include <iostream>
#include <fstream>
#include <cstdlib>

float mean(float * numbers, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum / size;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Numero parametri errato\nUso " << argv[0] << " <input> <output>" << std::endl;
        exit(1);
    }

    // Apertura file di input e output
    std::ifstream inf(argv[1]);
    std::ofstream ouf(argv[2]);

    if (!inf || !ouf) {
        std::cout << "Errore apertura file input o output" << std::endl;
        exit(1);
    }

    // Lettura dimensione vettore e allocazione memoria
    int size;
    inf >> size;
    float *numbers = new float[size];

    // lettura dei valori nel file di input
    for (int i = 0; i < size; i++) {
        inf >> numbers[i];
    }

    // Calcolo media e stampa risultato
    float meanValue = mean(numbers, size);
    std::cout << "Media: " << meanValue << std::endl;

    // Chiusura file di input e output
    inf.close();
    ouf.close();

    return 0;
}