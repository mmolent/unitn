#include "albero_int.hpp"
// si invoca "stampaAlbero(radice);"
void stampaAlbero(albero radice, int spazio=0);
 
void stampaAlbero(albero radice, int spazio){
   if (radice != NULL) {
    spazio ++;
    
    stampaAlbero(radice->right, spazio);
 
    for (int i = 1; i < spazio; i++) {
        cout<<"\t";
    }
    cout<<radice->value<<"\n";
    
    stampaAlbero(radice->left, spazio);
   }
}


Albero init_albero() {
  return nullptr;
}

Albero init_albero(int value) {
  Albero a = new nodo();
  a -> value = value;
  a -> left = nullptr;
  a -> right = nullptr;
  return a;
}

void deinit_albero(Albero &a) {
  if(a != nullptr) {
    deinit_albero(a -> left);
    deinit_albero(a -> right);
    delete a;
    a = nullptr;
  }
}

void insert(Albero &a, int value) {
    if(a == nullptr) { //caso base se l'albero è vuoto lo inizializzo con un nodo avente quel valore
        a = init_albero(value);
    } else if(value < a -> value) { //se il valore è minore del valore del nodo corrente vado a sinistra
        insert(a -> left, value); //provo a inserire il valore a sinistra
    } else { //se il valore è maggiore del valore del nodo corrente vado a destra
        insert(a -> right, value); //provo a inserire il valore a destra
    }
}
//funzione che bilancia l'albero
void balance (Albero &a) {
    if(a == nullptr) {
        return;
    }
    int left = depth(a -> left);
    int right = depth(a -> right);
    if(abs(left - right) > 1) {
        if(left > right) {
        Albero tmp = a;
        a = a -> left;
        tmp -> left = a -> right;
        a -> right = tmp;
        } else {
        Albero tmp = a;
        a = a -> right;
        tmp -> right = a -> left;
        a -> left = tmp;
        }
    }
    balance(a -> left);
    balance(a -> right);
    
}


bool search(const Albero a, int value) {
  if(a == nullptr) { //caso base se l'albero è vuoto non ho trovato il valore
    return false;
  } else if(a -> value == value) { //caso base se il valore del nodo corrente è uguale al valore che sto cercando ho trovato il valore
    return true;
  } else if(value < a -> value) { //se il valore è minore del valore del nodo corrente vado a sinistra
    return search(a -> left, value);
  } else {
    return search(a -> right, value);
  }
}



nodo* search_nodo(const Albero a, int value) {
  if(a == nullptr) {
    return nullptr;
  } else if(a -> value == value) {
    return a;
  } else if(value < a -> value) {
    return search_nodo(a -> left, value);
  } else {
    return search_nodo(a -> right, value);
  }
}



void print_identata(const Albero a) {
  if(a != nullptr) {
    print_identata(a -> left);
    std::cout << a -> value << std::endl;
    print_identata(a -> right);
  }
}

void inorder(const Albero a) {
  if(a != nullptr) {
    inorder(a -> left);
    std::cout << a -> value << " ";
    inorder(a -> right);
  }
}

void preorder(const Albero a) {
  if(a != nullptr) {
    std::cout << a -> value << " ";
    preorder(a -> left);
    preorder(a -> right);
  }
}

void postorder(const Albero a) {
  if(a != nullptr) {
    postorder(a -> left);
    postorder(a -> right);
    std::cout << a -> value << " ";
  }
}

int max(const Albero a) {
  if(a == nullptr) {
    return 0;
  } else if(a -> right == nullptr) {
    return a -> value;
  } else {
    return max(a -> right);
  }
}

int min(const Albero a) {
  if(a == nullptr) {
    return 0;
  } else if(a -> left == nullptr) {
    return a -> value;
  } else {
    return min(a -> left);
  }
}

//dim_albero
int dim_albero(const Albero a) {
  if(a == nullptr) {
    return 0;
  } else {
    return 1 + dim_albero(a -> left) + dim_albero(a -> right);
  }
}

int depth(const Albero a) {
  if(a == nullptr) {
    return 0;
  } else {
    int left = depth(a -> left);
    int right = depth(a -> right);
    if(left > right) {
      return 1 + left;
    } else {
      return 1 + right;
    }
  }
}

bool is_balanced(const Albero a) {
  if(a == nullptr) {
    return true;
  } else {
    int left = depth(a -> left);
    int right = depth(a -> right);
    if(abs(left - right) > 1) {
      return false;
    } else {
      return is_balanced(a -> left) && is_balanced(a -> right);
    }
  }
}

bool is_complete(const Albero a) {
  if(a == nullptr) {
    return true;
  } else if(a -> left == nullptr && a -> right == nullptr) {
    return true;
  } else if(a -> left != nullptr && a -> right == nullptr) {
    return false;
  } else if(a -> left == nullptr && a -> right != nullptr) {
    return false;
  } else {
    return is_complete(a -> left) && is_complete(a -> right);
  }
}