#define MAX 100
typedef struct q{
    int front;
    int rear;
    int array[MAX];
} Queue;

Queue* init_queue();
void push(Queue*,int);
void pop(Queue*);
void view(Queue*);