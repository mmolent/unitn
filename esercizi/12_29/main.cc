#include <fstream>
#include <iostream>
#include <string>

using namespace std;


int main (int argc, char ** argv) {
    fstream inp, outp;
    inp.open(argv[1], ios::in);
    outp.open(argv[2], ios::out);
    int es = atoi(argv[3]);

    switch (es){
        case 3:{
                char * riga = new char[256];
                string riga_massima;
                int massimo, dim;

                int i = 0;

                while(i<5){
                    inp.getline(riga, 256);
                    dim = strlen(riga);
                    outp << riga << endl << dim << endl;
                    if(dim >= massimo){
                        massimo = dim;
                        riga_massima = riga;
                    }
                    i++;
                }
                delete [] riga;
        }
        break;
    }
    return 0;
}