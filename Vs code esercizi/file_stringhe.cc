#include <iostream>
#include <fstream>
using namespace std;



int conta_caratteri(string parola){
    int a= 0, i=0;
    while(parola[i]=='*'){
        a++;
        i++;
    }
    return a;

}

int main(int argc, char* argv[]){
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out | ios::app);

    char car[11];
    int conta= 0;
    int parole= 0;

    if(input.fail())
    {
        cout << "Errore ad aprire il file input." << endl;
        return 0;
    }

    while(input >> car)
        {
            
            int aa = conta_caratteri(car);
            cout << aa << endl;
            conta += aa;
            parole ++;
        }

            input.close();
            cout << parole << endl;

            int media=conta/parole;
            output << endl << media;
            output.close();
    return 0;
}