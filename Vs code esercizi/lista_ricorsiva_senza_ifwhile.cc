#include <iostream>
#include <string>

using namespace std;

typedef struct _list {
  int code;
  struct _list * next;
} list;

#define MAXCODE 100
#define MAXDIP 10

// Add hereafter the declaration of estrai
list* estrai(list* l1, list* l2);
list* crea_l3(list* l1, list* l2, list* primo, list* secondo);
int conta(int val, list* l2, int contatore);

// Add here above the declaration of estrai

list * crea_lista(int num) {
  int * a = new int[num];
  for (int i = 0; i < num; i++) {
    a[i] = rand()%MAXCODE + 1;
    for (int j = 0; j < i; j++) {
      if (a[i] == a[j]) { i--; break;}
    }
  }
  list * res = NULL;
  for (int i = 0; i < num; i++) {
    res = new list{a[i], res};
  }
  delete [] a;
  return res;
}

list * crea_l2(list * const l1, const int t = 5) {
  list * res = NULL;
  for (int k = t; k >= 0; k--) {
    for (list * d = l1; d != NULL; d = d->next) {
      if (rand()%2 == 0) {
        res = new list{d->code, res};
      }
    }
  }
  return res;
}

void print_list(list * l, const char * prefix) {
  std::cout << prefix;
  for( ; l != NULL; l = l->next)
    std::cout << " " << l->code;
  std::cout << std::endl;
}

void delete_list(list * & l) {
  while(l != NULL) {
    list * p = l;
    l = l->next;
    delete p;
  }
}

int main(int argc, char ** argv) {
  srand(unsigned(time(0)));
		//
		// Scommentare la linea seguente per avere comportamento
		// deterministico
		//
		srand(0);

  list * l1 = crea_lista(MAXDIP);
  print_list(l1, "Lista L1:");
  list * l2 = crea_l2(l1);
  print_list(l2, "Lista L2:");
  list * l3 = estrai(l1, l2);
  print_list(l3, "Lista L3:");
  delete_list(l1);
  delete_list(l2);
  delete_list(l3);
  return 0;
}


// Add hereafter the definition of estrai

/*list* estrai(list* l1, list* l2)
{
  if(l1==nullptr) return nullptr;
  
  list* primo = new list;
  
  primo -> next = NULL;
  if(l1->code%2 == 0)
  primo -> code = conta(l1->code, l2, 0);
  else
  primo -> code = -1;
  
  if(l1->next==nullptr) return primo;
  list* secondo = new list;

  primo->next = secondo;
  secondo->next = NULL;

  if(l1->next->code%2 == 0)
    secondo -> code = conta(l1->code, l2, 0);
  else
    secondo -> code = -1;

  return crea_l3(l1->next->next, l2, primo, secondo);
}

list* crea_l3(list* l1, list* l2, list* primo, list* secondo){
  if(l1 == NULL)
  return primo;

  list* nodo = new list;
  nodo->next = NULL;
  secondo->next = nodo;

  if(l1->code%2 == 0)
    nodo -> code = conta(l1->code, l2, 0);
  else
    nodo -> code = -1;

  return crea_l3(l1->next, l2, primo, nodo);
  

}*/

int conta(int val, list* l2, int contatore){
  if(l2==NULL)
  return contatore;

  return conta(val, l2->next, contatore + (l2->code==val));
}
// Add here above the definition of estrai



list* estrai(list* l1, list* l2){
  if(l1==nullptr) return nullptr;

  list* nodo = new list;
  if(l1->code%2 == 0)
    nodo -> code = conta(l1->code, l2, 0);
  else
    nodo -> code = -1;

  nodo ->next = estrai(l1->next, l2);
  return nodo;
}