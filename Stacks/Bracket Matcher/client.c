#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "conv.h"

int main()
{
    /* testing with fixed input as a test
        given input     => ()[{{{{{[()]}}}}}]
        expected output => Yes
        */
    int sz;
    scanf("%d",&sz);
    char* input = (char*)malloc(sizeof(char)*sz);
    //Accepting input thru pipe operator while invoking a.out.
    scanf("%s",input);
    int ans = bracket_checker(input,sz);
    char reply[4] ="Yes";
    if(!ans){
        reply[0]='N';
        reply[1]='o';
        reply[2]='\0';
    }
    printf("\nBrackets matched : %s\n \n--------------------------------------------------------\n",reply);

}