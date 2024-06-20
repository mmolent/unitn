#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;



int main(int argc, char * argv []) {

  // Controllo che gli argomenti ci siano tutti
  if (argc != 2) {
    cout << "Usage: exercise1.out <input>" << endl;
    exit(1);
  }

  // Apro gli stream di lettura e scrittura
  fstream input;
  input.open(argv[1], ios::in);

  // Controllo che gli stream siano stati aperti correttamente
  if ( input.fail() ) {
    cout << "Errore nell'apertura degli stream!" << endl;
  }

  // Chiedo la stringa da ricercare
  char find[256];
  cout << "Inserire la stringa di ricerca: ";
  cin >> find;

  // Cerco
  char buffer[256];

  while(input >> buffer) {
    
    if ( strlen(buffer) == strlen(find) ) {

      bool missmatch = false;

      for ( int i=0; i<strlen(find) && !missmatch; ++i ) {

        if ( find[i] != '*' && buffer[i] != find[i] ) {
          // not matching
          missmatch = true;
        }

      }

      if ( ! missmatch ) {
        // found
        cout << buffer << endl;
      }

    }
    
  }

  input.close();

  return 0;

}
