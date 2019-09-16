#include <stdio.h>
#include <stdlib.h>

void solve_hanoi(int n, char from_rod, char to_rod, char aux_rod){
    if(n==1){
        printf("Move disk 1 from %c rod to %c rod\n",from_rod,to_rod);
        return;
    }
    solve_hanoi(n-1,from_rod,aux_rod,to_rod);
    printf("Move disk %d from %c rod to %c rod\n",n,from_rod,to_rod);
    solve_hanoi(n-1,aux_rod,to_rod,from_rod);
    }