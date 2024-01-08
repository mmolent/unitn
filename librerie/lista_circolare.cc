#include "lista_circolare.hpp"
#include <iostream>

void init_lista(lista & l) {
    l = nullptr; // la lista è vuota all'inizio
}

void delete_lista(lista &l) {
    if (!is_empty(l)) {
        nodo * curr = l;
        do {
            nodo * temp = curr;
            curr = curr->next;
            delete temp;
        } while (curr != l);
    }
    l = nullptr;
}

bool is_empty(lista l) {
    return l == nullptr; // la lista è vuota se l è nullptr
}

void insert(lista & l, int value) {
    nodo * temp = new nodo;
    temp->value = value;
    if (is_empty(l)) {
        temp->next = temp; // l'elemento punta a se stesso
        l = temp;
    } else {
        temp->next = l->next;
        l->next = temp;
    }
}

void insert_tail(lista & l, int value) {
    insert(l, value); // inserisce all'inizio
    l = l->next; // sposta l alla fine
}

void insert_ordinato(lista & l, int value) {
    if (is_empty(l) || l->value >= value) {
        insert(l, value);
    } else {
        lista curr = l;
        while (curr->next != l && curr->next->value < value) {
            curr = curr->next;
        }
        nodo * temp = new nodo;
        temp->value = value;
        temp->next = curr->next;
        curr->next = temp;
    }
}

void remove(lista & l, int value) {
    if (!is_empty(l)) {
        if (l->value == value) {
            nodo * temp = l->next;
            if (l->next == l) {
                l = nullptr;
            } else {
                l->next = temp->next;
                l = temp->next;
            }
            delete temp;
        } else {
            lista curr = l;
            while (curr->next != l && curr->next->value != value) {
                curr = curr->next;
            }
            if (curr->next->value == value) {
                nodo * temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
        }
    }
}

void print_lista(lista l) {
    if (!is_empty(l)) {
        lista curr = l->next;
        do {
            std::cout << curr->value << " ";
            curr = curr->next;
        } while (curr != l->next);
        std::cout << std::endl;
    }
}

nodo * search(lista l, int value) {
    if (!is_empty(l)) {
        lista curr = l->next;
        do {
            if (curr->value == value) {
                return curr;
            }
            curr = curr->next;
        } while (curr != l->next);
    }
    return nullptr;
}