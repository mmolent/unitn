#include "12_18.hpp"
#include <iostream>
lista::lista(){
    first = nullptr;
    last = nullptr;
}

lista::~lista(){
    nodo *n = first;
    while(n != nullptr){
        nodo *t = n;
        n = n -> next;
        delete t;
    }
}

std::ostream& operator<<(std::ostream& os, const lista& l){
    nodo *n = l.first;
    while(n != nullptr){
        os << n -> value << " ";
        n = n -> next;
    }
    return os;
}
