#include <iostream>
#include <cstdlib>

#define MAX_DIM 75

void fill_random_array(char * A, int N) {
  if (NULL != A) {
    for(int i = 0; i < N; i++) {
      A[i] = 'A' + rand()%(('A' - 'Z')+1);
    }
  }
}

void print_array(const char msg[], char * A, int N) {
  std::cout << msg;
  if (NULL != A) {
    for (int i = 0; i < N; i++) {
      std::cout << A[i];
    }
  }
  std::cout << std::endl;
}

/* Inserire qui sotto la dichiarazione della funzione conta */
void conta(const char *A, const int N, const int i, const int j, int * &res);
/* Inserire qui sopra la dichiarazione della funzione conta */

int main(int argc, char **argv) {
  unsigned int seed = (unsigned int)time(NULL);
  // seed = 60000
  seed = 1697033220;
  if (argc > 1) {
    seed = atoi(argv[1]);
  }
  std::cout << "Seed = " << seed << std::endl;
  srand(seed);

  char A[MAX_DIM];

  fill_random_array(A, MAX_DIM);
  print_array("A[] = ", A, MAX_DIM);
  int i, j;
  i = 0; j = -1;
  while(i > j) {
    i = rand()%MAX_DIM;
    j = rand()%MAX_DIM;
  }
  int * res;
  conta(A, MAX_DIM, i, j, res);
  std::cout << "i = " << i << ", j = " << j << std::endl;
  std::cout << "A[" << i << "] = " << A[i];
  std::cout << "  A[" << j << "] = " << A[j] << std::endl;
  std::cout << "There are " << res[0] << " occurrences of the searched pattern";
  std::cout << " between indexes " << i << " and " << j
            << " (with A[" << i << "] included and A[" << j << "] excluded)" << std::endl;
  if (res[0] > 0) {
    std::cout << "They are at indexes: ";
    for(int l = 1; l < res[0]+1; l++) {
      std::cout << res[l] << " ";
    }
    std::cout << std::endl;
  }
  delete [] res;
}

/* Inserire qui sotto la definizione della funzione conta */

void conta_aux(const char *A, const int N, const int i, const int j, int * & res, int r, int k) {
  if (i+k >= j) {
    // We need to create the space also for storing the size of the array!
    res = new int[r+1];
    // I save in position 0 the number of elements found
    res[0] = r;
    return;
  }
  if (A[i+k] != A[j]) {
    r+=1;
    // I recurse afer incrementing r to allocate res
    conta_aux(A, N, i, j, res, r, k+1);
    // I store in the position r the index of the found element
    res[r] = i+k;
    return;
  }
  // Condition not met, recurse to check the remaining positions
  conta_aux(A, N, i, j, res, r, k+1);
}

void conta(const char * A, const int N, const int i, const int j, int * & res) {
  if ((i > j) || (NULL == A)) {
    res = new int[1];
    res[0] = 0;
    return;
  }
  conta_aux(A, N, i, j, res, 0, 0);
}

/* Inserire qui sotto la definizione della funzione conta */
