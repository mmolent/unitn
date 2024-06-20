
struct Queue;

Queue * init();
int get(Queue *);
void put(Queue *, int);
bool isEmpty(Queue *);
void quit(Queue * & s);
