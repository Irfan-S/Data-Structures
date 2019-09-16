#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stk{
    int top;
    char *arr;
}stack;

void push(stack* user,char ele);
char pop(stack* user);
int bracket_checker(char*, int);
void print_stack(stack*);