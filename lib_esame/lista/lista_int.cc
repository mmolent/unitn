#include "lista_int.hpp"
using namespace std;
void deinit_lista(lista& l){
    if(l != nullptr){
        deinit_lista(l -> next);
        delete l;
        l = nullptr;
    }
}

void init_lista(lista& l){
    l = nullptr;
}

//funzione che fa un print della lista
void print_lista(const lista l){
    if(l == nullptr){
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    lista tmp = l;
    while(tmp -> next != nullptr){
        cout << tmp -> value << ", ";
        tmp = tmp -> next;
    }
    cout << tmp -> value << "]" << endl;
}
nodo* findlast_lista(lista l) {
  while(l -> next != nullptr) {
    l = l -> next;
  }
  return l;
}

void addtailelem_lista(lista &l, int value){
  nodo* last = findlast_lista(l);


  nodo* obj = new nodo();
  obj -> value = value;
  if(last == nullptr) {
    l = obj;
  }
  else{
    last -> next = obj;
  }
}

void addheadelem_lista(lista &l, int value){
  nodo* obj = new nodo();
  obj -> value = value;
  obj -> next = l;
  l = obj;
}

void addorderedelem_lista(lista &l, int value){
  if(l == nullptr || l -> value > value) {
    addheadelem_lista(l, value);
  } else {
    nodo* tmp = l;
    while(tmp -> next != nullptr && tmp -> next -> value < value) {
      tmp = tmp -> next;
    }
    nodo* obj = new nodo();
    obj -> value = value;
    obj -> next = tmp -> next;
    tmp -> next = obj;
  }
}

void concat_lista(lista &l1, lista &l2) {
    nodo* last = findlast_lista(l1);
    if(last == nullptr) {
        l1 = l2;
    } else {
        last -> next = l2;
        l2 = nullptr;
    }
}

void removeheadelem_lista(lista &l){
  if(l != nullptr){
    lista aux = l;
    l = l -> next;
    delete aux;
  }
}

void removetailelem_lista(lista &l) {
  if(l != nullptr) {
    lista aux = findlast_lista(l);
    delete aux;
    aux = findlast_lista(l);
    aux -> next = nullptr;
  }
}

void removeelem_lista(lista &l, int value) {
  if(l == nullptr) {
    return;
  }
  if(l -> value == value) {
    removeheadelem_lista(l);
    return;
  }
  nodo* tmp = l;
  while(tmp -> next != nullptr && tmp -> next -> value != value) {
    tmp = tmp -> next;
  }
  if(tmp -> next == nullptr) {
    return;
  }
  nodo* to_delete = tmp -> next;
  tmp -> next = tmp -> next -> next;
  delete to_delete;
}

int getheadelem_lista(const nodo* const &l) {
  return l -> value;
}
int gettailelem_lista(const lista l){
  return findlast_lista(l) -> value;
}

bool is_empty_lista(const lista l) {
  if (l == nullptr) return true;
  return false;
}

int size_lista(lista l) {
  int cont = 0;
  while(l != nullptr) {
    l = l -> next;
    cont++;
  } 
  return cont;
}

lista copy_lista(const lista l) {
  lista r = nullptr;
  lista tmp = l;
  while(tmp != nullptr) {
    addtailelem_lista(r, tmp -> value);
    tmp = tmp -> next;
  }
  return r;
}

//miglir algoritmo di sorting per la lista 
void sort_lista(lista &l) {
  if(l == nullptr) {
    return;
  }
  lista tmp = l;
  while(tmp -> next != nullptr) {
    lista min = tmp;
    lista tmp2 = tmp -> next;
    while(tmp2 != nullptr) {
      if(tmp2 -> value < min -> value) {
        min = tmp2;
      }
      tmp2 = tmp2 -> next;
    }
    int aux = tmp -> value;
    tmp -> value = min -> value;
    min -> value = aux;
    tmp = tmp -> next;
  }
}

bool is_sorted_lista(const lista l) {
  if(l == nullptr) {
    return true;
  }
  lista tmp = l;
  while(tmp -> next != nullptr) {
    if(tmp -> value > tmp -> next -> value) {
      return false;
    }
    tmp = tmp -> next;
  }
  return true;
}

lista findvalue_lista(const lista l, int value) {
  lista tmp = l;
  while(tmp != nullptr) {
    if(tmp -> value == value) {
      return tmp;
    }
    tmp = tmp -> next;
  }
  return nullptr;
}

//funzione che stampa l'intero oggetto lista
void print_lista(const lista l){
    if(l == nullptr){
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    lista tmp = l;
    while(tmp -> next != nullptr){
        cout << tmp -> value << ", ";
        tmp = tmp -> next;
    }
    cout << tmp -> value << "]" << endl;
}

//overriding dell'operatore << per stampare la lista
ostream& operator<<(ostream& os, const lista& l){
    os << "[";
    lista tmp = l;
    while(tmp -> next != nullptr){
        os << tmp -> value << ", ";
        tmp = tmp -> next;
    }
    os << tmp -> value << "]" << endl;
    return os;
}
//overriding dell'operatore >> per leggere la lista (prende un intero e aggiunge ogni cifra alla lista)
istream& operator>>(istream& is, lista& l){
    int n;
    is >> n;
    while(n != 0){
        addtailelem_lista(l, n % 10);
        n /= 10;
    }
    return is;
}


