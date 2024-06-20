#include <iostream>
using namespace std;

struct ListNode {
    int code;
    ListNode* next;
};

// Funzione per stampare una lista
void printList(ListNode* list, const char* message = "List: ") {
    cout << message;
    while (list != nullptr) {
        cout << list->code << " ";
        list = list->next;
    }
    cout << endl;
}

// Funzione per creare una nuova lista con i risultati
void estraiHelper(ListNode* original, ListNode*& result, int& accumulatedSum) {
    if (original == nullptr) {
        return;
    }

    // Crea il nuovo nodo con il valore corrente
    ListNode* newNode = new ListNode;
    newNode->code = original->code;

    // Collega il nuovo nodo alla lista risultato
    newNode->next = result;
    result = newNode;

    // Aggiorna la somma accumulata
    accumulatedSum += original->code;

    // Crea il nuovo nodo con la somma accumulata
    ListNode* sumNode = new ListNode;
    sumNode->code = accumulatedSum;

    // Collega il nodo somma alla lista risultato
    sumNode->next = result;
    result = sumNode;

    // Chiamata ricorsiva per il resto della lista
    estraiHelper(original->next, result, accumulatedSum);
}

ListNode* estrai(ListNode* l1) {
    ListNode* result = nullptr;
    int accumulatedSum = 0;
    estraiHelper(l1, result, accumulatedSum);

    // Inverti la lista risultato per ottenere l'ordine corretto
    ListNode* prev = nullptr;
    ListNode* current = result;
    ListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    result = prev;

    return result;
}

// Funzione di utilità per creare una nuova lista da un array
ListNode* createListFromArray(int arr[], int size) {
    if (size == 0) {
        return nullptr;
    }
    ListNode* head = new ListNode;
    head->code = arr[0];
    head->next = nullptr;

    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        ListNode* newNode = new ListNode;
        newNode->code = arr[i];
        newNode->next = nullptr;
        current->next = newNode;
        current = newNode;
    }

    return head;
}

// Funzione principale
int main() {
    // Creazione delle liste di esempio
    int arr1[] = {1, 2, 4, 5};

    ListNode* l1 = createListFromArray(arr1, 4);

    // Stampa della lista originale
    cout << "Lista originale l1: ";
    printList(l1);

    // Creazione della nuova lista con i risultati
    ListNode* result = estrai(l1);

    // Stampa della nuova lista
    cout << "Lista risultante: ";
    printList(result);

    // Liberazione della memoria
    while (l1 != nullptr) {
        ListNode* temp = l1;
        l1 = l1->next;
        delete temp;
    }
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
