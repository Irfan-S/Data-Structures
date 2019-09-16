#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conv.h"

void push_num(numstack* user,int ele){
    user->top++;
    user->arr[user->top] = ele;   
}
int pop_num(numstack* user){
    // if(user->top<0){
    //     return NULL;
    // }else{
        int loc = user->arr[user->top];
        user->top--;
        return loc;
    //}
}

int ops(int a, int b, char op){
    int ans=0;
    //printf("op char is %c \n",op);
    if(op=='+'){
        ans = a+b;//(a-'0')+(b-'0');
    }else if(op == '-'){
        ans = a-b;//(a-'0') - (b-'0');
    }else if(op== '/'){
        ans = a/b;//(a-'0') /(b-'0');
    }else if(op =='*'){
        ans = a*b;//(a-'0') *( b-'0');
    }else if(op =='%'){
        ans = a%b;//(a-'0') %( b-'0');
    }
    //printf("Ans is: %d\n",ans);
    return ans;
}

//Printer to debug and trace stack output.
void print_numstack(numstack* m){
    int t=m->top;
    while(t>=0){
        printf("%d ",m->arr[t]);
        t--;
    }
    printf("\n");
}
// Does not work for digits going into 10+, only works if the result of operations performed is always <10.
// Uncommented code works for all digits.
int postfix_solver(char* input,int sz){

    printf("\nStarting postfix resolver for single digits..\n\n");
    numstack* op_stack = (numstack*) malloc(sizeof(numstack));
    op_stack->top=-1;
    op_stack->arr = (int*)malloc(sizeof(int)*sz);
    char ch = input[0];
    int pos=0;
    int ans=0;
    while(ch!='\0'||ch!=NULL){
        //printf("Top is %d, ",op_stack->top);
        //printf("Character is %c\n ",ch);
        //print_numstack(op_stack);
        if(isdigit(ch)){
            push_num(op_stack,(ch-'0'));
            pos++;
        }else{
            //if(op_stack->top>=2){
                int b = pop_num(op_stack);
                int a =pop_num(op_stack);
                ans = ops(a,b,ch);
                push_num(op_stack,ans);
                pos++;
            //}else{
            //    push_num(op_stack,ans);
            //    pos++;
           // }
        }
        // if(op_stack->top>=3){
        //     if(isdigit(op_stack->arr[op_stack->top])){
        //         push(op_stack,ch);
        //         print_stack(op_stack);
        //         pos++;
        //     }else{
        //     char op = pop(op_stack);
        //     char b = pop(op_stack);
        //     char a =pop(op_stack);
        //     ans = ops(a,b,op);
        //     char c_ans;
        //     c_ans = ans+'0';
        //     push(op_stack,c_ans);
        //     printf("Stack after pop and push:\n");
        //     print_stack(op_stack);
        //     //DEBUG : printf("pushed %c \n",c_ans);
        //     }
            
        // }else{
        //     //DEBUG : printf("pushing %c \n",ch);
        //     push(op_stack,ch);
        //     print_stack(op_stack);
        //     pos++;
        // }
        ch=input[pos];
    }
    //char op = pop(op_stack);
    // int b = pop_num(op_stack);
    // int a =pop_num(op_stack);
    // ans = ops(a,b,ch);

    //print_stack(op_stack);
    return ans;
}