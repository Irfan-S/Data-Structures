typedef struct n{
    int data;
    struct n* next;
}  Node;

typedef struct q{
    int size;
    Node* front;
    Node* rear;

} Queue;

Queue* init_queue();
void push(Queue*,int);
void pop(Queue*);
void view(Queue*);
