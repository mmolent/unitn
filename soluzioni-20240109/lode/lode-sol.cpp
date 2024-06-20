#include <iostream>
#include <iomanip>
#include <cstdlib>

void copy_array(char *src, char *dst, int n) {
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

// Inserire qui la dichiarazione della funzione codici
char ** codici(int nb, int & max);
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

void codici_aux(char **res, int nb, int start, int end, bool first, int & index) {
    if (nb == 0) {
        if (index < end) {
            copy_array(res[index], res[index+1], start);
            index++;
        }
    }
    else {
        if (first) {
            res[index][start] = '1';
            codici_aux(res, nb - 1, start+1, end, false, index);
            res[index][start] = '0';
            codici_aux(res, nb - 1, start+1, end, true, index);
        } 
        else {
            res[index][start] = '0';
            codici_aux(res, nb - 1, start + 1, end, false, index);
            res[index][start] = '1';
            codici_aux(res, nb - 1, start + 1, end, true, index);
        }
    }
}

// Inserire qui sopra eventuali definizioni di funzioni ausiliarie

// Inserire qui sotto la definizione della funzione codici
char ** codici(int nb, int & max) {
    // compute the number of codes
    max = 1 << nb;
    // Allocate memory for the result
    char **res = new char*[max];
    for (int i = 0; i < max; i++) {
        res[i] = new char[nb];
    }
    // Compute the codes
    int index = 0;
    codici_aux(res, nb, 0, max - 1, false, index);

    return res;
}
// Inserire qui sopra la definizione della funzione codici