#include <stdio.h>
#include <stdlib.h>
#include "stack_ops.h"

int main(){
    stack* myStack = init_stack();
    push(1,myStack);
    print_stack(myStack);
    push(2,myStack);
    print_stack(myStack);
    push(3,myStack);
    print_stack(myStack);
    pop(myStack);
    print_stack(myStack);
}