
struct nodo{
    nodo *prev;
    nodo *next;
    int value;

    
};
struct lista{
    nodo *first;
    nodo *last;

    lista();
    ~lista();
    friend std::ostream& operator<<(std::ostream& os, const lista& l);
};
