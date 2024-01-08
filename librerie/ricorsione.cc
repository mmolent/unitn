//esempio allocazione dinamica
//funzione ricorsiva che visita un albero e alloca dinamicamente un array avente come valori il numero di numeri dispari nell'albero

#include <iostream>
#include "albero.hpp"
using namespace std;



int conta_dispari(Albero a) {
    if (a == nullptr) {
        return 0;
    }
    int count = 0;
    if (a->value % 2 != 0) {
        count++;
    }
    return count + conta_dispari(a->left) + conta_dispari(a->right);
}

//funzione che mette tutti i numeri dispari in una lista
void metti_dispari_in_lista(Albero a, char * & array, int & i) {
    if (a == nullptr) {
        return;
    }
    if (a->value % 2 != 0) {
        array[i] = a->value;
        i++;
    }
    metti_dispari_in_lista(a->left, array, i);
    metti_dispari_in_lista(a->right, array, i);
}



void stampa_array(int * array, int dim) {
    for (int i = 0; i < dim; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int * alloca_dispari(Albero a, int & dim){
    if (a == nullptr) {
        dim = 0;
        return nullptr;
    }
    int dim_sx = 0;
    int dim_dx = 0;
    int * array_sx = alloca_dispari(a->left, dim_sx);
    int * array_dx = alloca_dispari(a->right, dim_dx);
    dim = dim_sx + dim_dx;
    if ((a->value) % 2 != 0) { 
        dim++;
    }
    int * array = new int[dim];
    int i = 0;
    for (; i < dim_sx; i++) {
        array[i] = array_sx[i];
    }
    if ((a->value) % 2 != 0) { 
        array[i] = a->value;
        i++;
    }
    for (int j = 0; j < dim_dx; j++) {
        array[i] = array_dx[j];
        i++;
    }
    delete [] array_sx;
    delete [] array_dx;
    return array;
}

int main(){
    Albero a = init_albero();
    popola_albero(a, 10);
    print_identata(a);
    int dim = 0;
    int * array = alloca_dispari(a, dim);
    cout << "dim: " << dim << endl;
    cout << "array: ";
    stampa_array(array, dim);
    delete [] array;
    deinit_albero(a);
    return 0;
}

