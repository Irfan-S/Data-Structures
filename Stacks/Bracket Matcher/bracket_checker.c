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
    if(user->top>=0){
        char loc = user->arr[user->top];
        user->top--;
        return loc;
    }else{
        return '\0';
    }
}

void print_stack(stack* m){
    int t=m->top;
    printf("Top is: %d\n",t);
    while(t>=0){
        printf("%c ",m->arr[t]);
        t--;
    }
    printf("\n");
}
/*
    Checks if all input braces are matched properly
*/

int bracket_checker(char* input,int size){

    printf("--------------------------------------------------------\nChecking braces..\n\n");
    printf("Input expression: %s",input);

    stack* holder = (stack*)malloc(sizeof(stack));
    holder->arr = (char*)malloc(sizeof(char)*size);
    holder->top=-1;
    //holder->arr[0]='#';
    char ch=input[0];
    input[size]='\0';
    int pos=0;
    int ch_counter=0;
    while(ch!='\0'){
        //printf("Char being checked: %c\n",ch);
        //print_stack(holder);
        if(ch=='('||ch=='['||ch=='{'){
            push(holder,ch);
        }else if(ch==')'||ch==']'||ch=='}'){
            char temp;
            int r=2;
            //DEBUG : printf("%c",temp);
            temp = pop(holder);
            //printf("popped %c at top: %d\n",temp,holder->top);
            if(ch==')'){
                r=1;
            }
            if(temp!=(ch-r)){
                    //printf("%c != %c \n",temp,(ch-2));
                    return 0;
            }   
        }
        ch = input[++pos];
    }
    return 1;
}
