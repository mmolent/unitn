#include <iostream>
#include <iomanip>
#include <cstdlib>

void copy_array(char *src, char *dst, int n) {
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

// Inserire qui la dichiarazione della funzione codici

// Inserire qui sopra la dichiarazione della funzione codici_aux

// NON MODIFICARE IL MAIN
int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " #num" << std::endl;
        exit(1);
    }
    int nb = atoi(argv[1]);

    int max;
    char **res = codici(nb, max);

    std::cout << "Grey codes for " << nb << " bits:" << std::endl;
    for (int i = 0; i < max; i++) {
        std::cout << std::setw(3) << i << ": ";
        for (int j = 0; j < nb; j++) {
            std::cout << res[i][j];
        }
        delete [] res[i];
        std::cout << std::endl;
    }
    delete [] res;
    return 0;
}
// NON MODIFICARE IL MAIN

// Inserire qui sotto eventuali definizioni di funzioni ausiliarie

// Inserire qui sopra eventuali definizioni di funzioni ausiliarie

// Inserire qui sotto la definizione della funzione codici

// Inserire qui sopra la definizione della funzione codici