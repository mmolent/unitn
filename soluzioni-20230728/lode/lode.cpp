#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define MAXVAL 20
#define MAXSIZE 10

void printSquareMatrix(float ** A, int N) {
  for(int i = 0; i < N; i++) {
    std::cout << std::setw(10);
    for (int j = 0; j < N; j++)
      std::cout << std::setprecision(3) <<  A[i][j] << std::setw(10);
    std::cout << std::endl;
  }
}

float ** randomSquareMatrix(const int N) {
  float ** result = new float * [N];
  for(int i = 0; i < N; i++) {
    result[i] = new float[N];
    for(int j = 0; j < N; j++) {
      result[i][j] = rand()%MAXVAL;
    }
  }
  return result;
}

void deallocateSquaredMatrix(float ** & M, const int N) {
  for(int i = 0; i < N; i++)
    delete [] M[i];
  delete [] M;
  M = NULL;
}


// Inserire qui sotto la dichiarazione della procedura triangolarizza

// Inserire qui sopra la dichiarazione della procedura triangolarizza


int main(int argc, char * argv[]) {
  unsigned s = unsigned(time(0));
  srand(s);
		//
		// Commentare la linea seguente per avere comportamento
		// non-deterministico
		//
		srand(1688544644);
  int N = rand()%MAXSIZE;
  float **A = randomSquareMatrix(N);
  std::cout << "Matrice A["<< N << "][" << N << "]" << std::endl;
  printSquareMatrix(A, N);
  triangolarizza(A,N);
  std::cout << "Matrice AT["<< N << "][" << N << "]" << std::endl;
  printSquareMatrix(A, N);
  deallocateSquaredMatrix(A,N);
}

// Inserire qui sotto la definizione della procedura triangolarizza

// Inserire qui sopra la definizione della procedura triangolarizza
