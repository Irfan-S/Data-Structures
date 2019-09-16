#include <stdlib.h>
#include <stdio.h>
#include "func.h"

int main(){
    int n;
    scanf("%d",&n);
    printf("Solving Towers of Hanoi for %d numbers..\n",n);
    printf("---------------------------------------------------------------------------------------\n");
    solve_hanoi(n,'A','C','B');
    printf("---------------------------------------------------------------------------------------\n");
    return 0;
}