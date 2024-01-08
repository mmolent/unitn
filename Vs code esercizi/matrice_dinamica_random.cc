#include <iostream>
#include <cstdlib>

using namespace std;

int minimo(int a, int b){
  if(a<b) return a;
  else return b;
}

int main(){

    srand(time(NULL));
    int righe, colonne, sottorighe, sottocolonne, riga, colonna;
    cout << "Quante righe si vuole inserire?: " << endl;
    cin >> righe;
    cout << "Quante colonne si vuole inserire?: " << endl;
    cin >> colonne;
    cout << endl;

    int** matrice = new int* [righe];
   
    for(int i=0;i<righe;i++)
    {
      matrice[i]=new int[colonne];
      for(int j=0;j<colonne;j++)
        {
            matrice[i][j]= rand() % 10;
            cout << matrice[i][j] << " ";
         }
    cout << endl; 
    }

    cout << "Quante righe si vogliono per la sottomatrice?: " << endl;
    cin >> sottorighe;
    cout << "Quante colonne si vogliono per la sottomatrice?: " << endl;
    cin >> sottocolonne;

    cout << "Da che punto della matrice si vuole creare la sottomatrice?: " << endl;
    cin >> riga >> colonna;

    for(int i=riga; i<minimo(righe, riga+sottorighe); i++){
        for(int j=colonna; j<minimo(colonne, colonna+sottocolonne); j++){
          cout << matrice[i][j] << " ";
        }
        cout << endl;
    }

   for(int i=0;i<righe;i++)
   {
    delete[] matrice[i];
   }
   delete[] matrice;


    return 0;

}