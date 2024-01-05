#ifndef PILA_HPP
#define PILA_HPP

template<class T> 
struct nodoPila {
    T value;
    nodoPila* next;
    void pila_init();
    bool pila_push(T);
    bool pila_top(T &);
    bool pila_pop();
    void pila_deinit();
    void pila_print();
};
typedef nodoPila* listaPila;
 

 
#endif
