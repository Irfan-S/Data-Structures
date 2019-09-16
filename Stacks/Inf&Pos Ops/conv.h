#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stk{
    int top;
    char *arr;
}stack;
typedef struct numstk{
    int top;
    int* arr;
}numstack;

void push_num(numstack*,int);
int pop_num(numstack*);
void print_numstack(numstack*);

void push(stack* user,char ele);
char pop(stack* user);
int incoming_precedence(char s);
int incoming_stack_precedence(char s);
char* infix_to_postfix(char* input);
int ops(int a, int b, char ops);
int postfix_solver(char* a, int sz);
void print_stack(stack*);