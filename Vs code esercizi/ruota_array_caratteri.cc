#include <iostream>
#include <time.h>
using namespace std;

 void ruotaArrayEfficiente(char v[], int dim, int rotazione) {
    int *temp = new int[rotazione];

    for (int i = 0; i < rotazione; i++) {
        temp[i] = v[i];
    }

    for (int i = 0; i < dim - rotazione; i++) {
        v[i] = v[rotazione + i];
    }

    for (int i = 0; i < rotazione; i++) {
        v[dim - rotazione + i] = temp[i];
    }
    delete[] temp;
}

void ruotaArrayInefficiente(char v[], int dim, int rotazione) {
    int temp;

    for (int i = 0; i < rotazione; i++) {
        temp = v[0];

        for (int k = 0; k < dim - 1; k++) {
            v[k] = v[k + 1];
        }
        v[dim - 1] = temp;
    }
}

void stampaArray(char v[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}




int main(){
    srand(time(NULL));
    char v[5];
    int numero;
    for(int i=0;i<5;i++) v[i]= (char)(rand()%26)+ (int)'A';

    cout << "Inserisci un numero: " << endl;
    cin >> numero;
    numero %= 5;
    stampaArray(v, 5);
    ruotaArrayEfficiente(v, 5, numero);
    stampaArray(v, 5);

 


}