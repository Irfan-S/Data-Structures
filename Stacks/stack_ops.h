typedef struct stack{
    
    int* arr;
    int top;

} stack;

stack* init_stack();

void increase_size(stack* m_stack);

void decrease_size(stack* m_stack);

void push(int ele, stack* m_stack);

void pop(stack* m_stack);

void print_stack(stack* m_stack);