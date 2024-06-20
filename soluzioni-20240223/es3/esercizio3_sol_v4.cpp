#include <iostream>
#include <cstdlib>

// Non modificare questa parte sotto del codice
typedef struct Stack {
    int data;
    struct Stack * next;
} Stack;

struct Stack * initStack() {
    return nullptr;
}

bool isEmpty(struct Stack * s) {
    return (s == nullptr);
}

void push(struct Stack * &s, int value) {
    struct Stack * newElement = new Stack;
    newElement->data = value;
    newElement->next = s;
    s = newElement;
}

int top(struct Stack * s) {
    if (isEmpty(s)) {
        std::cerr << "Error: stack is empty" << std::endl;
        exit(1);
    }
    return s->data;
}

int pop(struct Stack * &s) {
    if (isEmpty(s)) {
        std::cerr << "Error: stack is empty" << std::endl;
        exit(1);
    }
    int value = s->data;
    struct Stack * temp = s;
    s = s->next;
    delete temp;
    return value;
}

void deleteStack(struct Stack * &s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

void printStack(struct Stack * s, const char * message = "Stack: ") {
    if (isEmpty(s)) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << message;
        struct Stack * temp = s;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}
// Non modificare questa parte sopra del codice

// Inserire qui sotto la dichiarazione della funzione stackOperator
struct Stack *stackOperator(struct Stack * &s);
// Inserire qui sopra la dichiarazione della funzione stackOperator

int main() {
    struct Stack *s, *result;
    unsigned int seed = (unsigned int)time(NULL);
    // seed = 60000
    seed = 1697033220;
    srand(seed);

    s = initStack();
    for (int i = 0; i < 5; i++) {
        if (i != 2) push(s, 5-i);
    }
    printStack(s, "Original before: ");
    result = stackOperator(s);
    printStack(result, "Result StackOperator: ");
    printStack(s, "Original after: ");
    deleteStack(s);
    deleteStack(result);

    s = initStack();
    for (int i = 0; i < 10; i++) {
        push(s, rand() % 100);
    }
    printStack(s, "Original before: ");
    result = stackOperator(s);
    printStack(result, "Result StackOperator: ");
    printStack(s, "Original after: ");
    deleteStack(s);
    deleteStack(result);

    return 0;
}

// Inserire qui sotto la definizione della funzione stackOperator
void stackOperatorAux(struct Stack * & s, struct Stack * & result, int base) {
    if (!isEmpty(s)) {
        int value = pop(s);
        base -= value;
        push(result, value);
        push(result, base);
        stackOperatorAux(s, result, base);
        push(s, value);
    }
}

struct Stack * stackOperator(struct Stack * &s) {
    struct Stack *result = initStack();
    stackOperatorAux(s, result, 0);
    return result;
}
// Inserire qui sopra la definizione della funzione stackOperator
