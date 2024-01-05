//main che usa la classe pilat
#include <iostream>
#include "pila.hpp"
int main() {
    pila_init<int>(); // Assuming pila_init is a template function that takes an argument of type int
    pila_push(1);
    pila_push(2);
    pila_push(3);
    pila_print<int>(); // Assuming pila_print is a template function that takes an argument of type int
    int n;
    pila_top(n);
    std::cout << "Top: " << n << std::endl;
    pila_pop<int>(); // Assuming pila_pop is a template function that takes an argument of type int
    pila_print<int>(); // Assuming pila_print is a template function that takes an argument of type int
    pila_deinit<int>(); // Assuming pila_deinit is a template function that takes an argument of type int
    return 0;
}