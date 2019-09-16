#include <stdio.h>
#include <stdlib.h>
#include "stack_ops.h"

typedef struct btack{
    int* arr;
    int top;
} stack ;

stack* init_stack();
void increase_size(stack*);
void decrease_size(stack*);
void push(int,stack*);
void pop(stack*);
void print_stack(stack*);


stack* init_stack(){
    stack* m_stack = (stack*)malloc(sizeof(stack));
    m_stack->arr = (int*)malloc(sizeof(int));
    m_stack->top=0;
    return m_stack;
}

void increase_size(stack* m_stack){
    m_stack = (stack*)malloc(sizeof(sizeof(m_stack->arr)*2));
}

void decrease_size(stack* m_stack){
    m_stack = (stack*)malloc(sizeof(sizeof(m_stack->arr)/2));
}

void push(int ele, stack* m_stack){
    increase_size(m_stack);
    m_stack->arr[m_stack->top]=ele;
    m_stack->top++;
}

void pop(stack* m_stack){
    decrease_size(m_stack);
    m_stack->top--;
}

void print_stack(stack* m_stack){
    for(int i=0;i<=m_stack->top;i++){
        printf("%d ",m_stack->arr[i]);
    }
    printf("\n");
}