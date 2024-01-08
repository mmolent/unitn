#include <iostream>
#include <fstream>
using namespace std;

    int converti(int partenza, int arrivo, int numero);
    int converti_intero(string parola);
    int pow(int base, int esponente);

int main(int argc, char* argv[]){

    fstream input, output;
    input.open(argv[1], ios::in);
 //   output.open(argv[2], ios::out);

    char* parola = new char[9];
    int base, arrivo;
    cout << "Inserisci la base di partenza: "<< endl;
    cin >> base;

    cout << "Inserisci la base di arrivo: "<< endl;
    cin >> arrivo;
    input >> parola;
    cout << parola;
    int numero = converti_intero(parola);


  //  cout << converti(base, arrivo, numero) << endl;

    delete[] parola;
return 0;
}

   int converti(int partenza, int arrivo, int numero){
    int risultato = 0;
    int potenza = 1;
    while (numero > 0) {
        risultato += (numero % partenza) * potenza;
        numero /= arrivo;
        potenza *= partenza;
    }
    return risultato;

   }


int converti_intero(string parola)
{
    int i=0;
    while(parola[i]!='\0') i++;
    int t=0, j= 0;
    i--;
    
    while(i>=0)
    {
        t+=(parola[j]- '0')*pow(10, i);
        i--;
        j++;
    }
    return t;
}

int pow(int base, int esponente){
    int ciao= base;
    for(int i=0;i<esponente;i++) base*=ciao;
    return base;

}
