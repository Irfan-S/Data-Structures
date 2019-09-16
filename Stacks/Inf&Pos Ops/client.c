#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "conv.h"

int main()
{
    /* testing with fixed input as a test
        given input     =>((2+3-4)*(9+5*2+3*6))
        expected output => 23+4-952*+36*+*
        */
    int sz;
    scanf("%d",&sz);
    char* input = (char*)malloc(sizeof(char)*sz);
    scanf("%s",input);
    // char op[22] = {'(','(','2','+','3','-','4',')','*','(','9','+','5','*','2','+','3','*','6',')'
    // ,')','\0'};
    char* ans = infix_to_postfix(input);

    printf("\nPostfix expression: %s\n \n--------------------------------------------------------",ans);
    int num = postfix_solver(ans,sz);
    printf("Solution: %d \n",num);

}