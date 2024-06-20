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

  // Chiedo i caratteri da ricercare e tenere nel testo finale
  char query[256];
  cout << "Inserire la sequenza di caratteri: ";
  cin.getline( query, 256 );
  cout << query << endl;

  // Scorro char testo in input
  while ( ! input.eof() ) {

    char c;
    input.read(&c, 1);
    // cout << "reading " << c << endl;

    // Scorro char sequenza
    for ( int i=0; i<strlen(query); i++ ) {

      char q = query[i];
      char Q = ( q >= 'a' && q <= 'z' ? q - 'a' + 'A' : q );
      q = ( q >= 'A' && q <= 'Z' ? q - 'A' + 'a' : q );

      // cout << "query " << q << endl;
      if ( q == c || Q == c ) {
        cout << c;
        break;
      }

    }

  }

  input.close();

  return 0;

}
