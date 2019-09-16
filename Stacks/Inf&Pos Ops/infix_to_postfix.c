#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stk{
    int top;
    char* arr;
}stack;

void push(stack* user,char ele){
    user->top++;
    user->arr[user->top] = ele;   
}
char pop(stack* user){
    // if(user->top<0){
    //     return NULL;
    // }else{
        char loc = user->arr[user->top];
        user->top--;
        return loc;
    //}
}
int incoming_precedence(char s){
    //left brack be min
    int l_pre=-1;
    if(s=='('){
        l_pre= 30;
    }else if(s=='+'||s=='-'){
        l_pre=10;
    }else if(s=='*'||s=='/'||s=='%'){
        l_pre=20;
    }
    return l_pre;
}

int incoming_stack_precedence(char s){
    int l_pre=-1;
    if(s=='('){
        l_pre=5;
    }else if(s=='+'||s=='-'){
        l_pre=10;
    }else if(s=='*'||s=='/'||s=='%'){
        l_pre=20;
    }
    return l_pre;
}

/*
    Accepts single digit operands. To enable multi-digit, we need to use isalphanum() and create a function to convert numbers>9 to a sequence of chars which represent the digit.
*/

char* infix_to_postfix(char* input,int size){

    printf("--------------------------------------------------------\nConversion of infix to postfix..\n\n");
    printf("Input expressions: %s",input);
    stack* precedence_stack = (stack*) malloc(sizeof(stack));
    precedence_stack->arr = (char*)malloc(sizeof(char)*size);
    precedence_stack->top=0;
    char* ans= (char*)malloc(sizeof(char)*size);
    ans[size-1]='\0';
    precedence_stack->arr[0]='#';
    char ch=input[0];
    int pos=0;
    int ch_counter=0;
    while(ch!='\0'){
        if(isdigit(ch)){
            //DEBUG : printf("%c",ch);
            ans[pos]=ch;
            pos++;
        }else if(ch=='('){
            push(precedence_stack,ch);
        }else if(ch==')'){
            char temp = pop(precedence_stack);
            while(temp!='('){
                //DEBUG : printf("%c",temp);
                ans[pos]=temp;
                temp = pop(precedence_stack);
                pos++;
            }
        }else{
            if(incoming_stack_precedence(precedence_stack->arr[precedence_stack->top])<incoming_precedence(ch)){
                push(precedence_stack,ch);
            }else{
                while(incoming_stack_precedence(precedence_stack->arr[precedence_stack->top])>=incoming_precedence(ch)){
                    char t = pop(precedence_stack);
                    //DEBUG : printf("%c",t);
                    ans[pos]=t;
                    pos++;
                }
                push(precedence_stack,ch);
            }
        }
        ch_counter++;
        ch=input[ch_counter];
    }
    if(precedence_stack->top>0){
        if(precedence_stack->arr[precedence_stack->top]!=')'){
            char z = pop(precedence_stack);
            ans[pos]=z;
        }
    }
    return ans;

}
