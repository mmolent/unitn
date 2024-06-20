#include <fstream>
#include <iostream>

using namespace std;

const int n1 = 128;
const int n2 = 8;
const int n3 = 13;

int converti(int [], int );
int prodotto(int [], int);
void elaborariga(char [], int, int);

int prodotto(int a[], int n) {
    int p = 1;
    for (int i = 0; i < n; i++)
       p *= a[i];
    return p;
}

void elaborariga(char str[], int num[], int& ris) {
    int k = 0; int n = 0; int b[n2] = {0};
    for (int i = 0; i < n3; i++)
        num[i] = 1;
    while (str[k] != '\0') {
        int h = 0;
        while (str[k] != '*' && str[k] != '=' && str[k] != ';') {
		    b[h] = str[k] - '0';
		    k++; h++;
	    }
	    if (str[k] == '*' || str[k] == '=') {
		    num[n] = converti(b, h);
            n++;
	    }
	    else
            ris = converti(b, h);
	    k++;
    }
    return;
}

int converti(int b[], int n) {
    int num = 0;
    for (int i = 0; i < n; i++)
       num = num * 2 + b[i];
    return num;
}

int main() {
    char linea[n1];
    fstream fin, fout;

    fin.open("inputdati.txt", ios::in);
    fout.open("outputcheck.txt", ios::out);

    if (fin.fail() || fout.fail()) {
        cout << "Errore nell'apertura dei file";
        return 1;
    }

    fin >> linea;
    while (!fin.eof()) {
	    int fattori[n3] = {0};
	    int risultato = 0;
	    elaborariga(linea, fattori, risultato);
	    int p = prodotto(fattori, n3);
	    if (p != risultato) {
	        fout << p << endl;
	    }
	    else
            fout << "Corretto" << endl;
	    fin >> linea;
    }
    fin.close();
    fout.close();

    return 0;
}
