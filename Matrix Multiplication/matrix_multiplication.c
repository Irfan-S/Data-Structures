//Code to implement matrix multiplication on a dynamically allocated 2D array.
//input file -> input_matrix.txt;

#include <stdio.h>
#include <stdlib.h>

void print_matrix(int**,int, int);
void mul_matrices(int** , int**, int ,int ,int ,int);
int** input_matrix(int,int);

int main(){
    //printf("Enter the number of rows and columns for matrix 1: ");
    int r1,c1;
    scanf("%d %d",&r1,&c1);
    int** m1 =input_matrix(r1,c1);

    //printf("Enter the number of rows and columns for matrix 2: ");
    int r2,c2;
    scanf("%d %d",&r2,&c2);
    int** m2 =input_matrix(r2,c2);


    mul_matrices(m1,m2,r1,c1,r2,c2);

}

int** input_matrix(int r, int c){
    int** m1 = (int**)malloc(r*sizeof(int*));
    for(int i=0;i<r;i++){
        m1[i] = (int*)malloc(c*sizeof(int));
    }
    //printf("Enter the elements:\n");
    for(int i=0;i<r;i++){
        for(int j =0;j<c;j++){
            scanf("%d",&m1[i][j]);
        }
    }
    return m1;
}

void mul_matrices(int** m1, int** m2, int r1,int c1,int r2,int c2){
    int r,c;
    int sum=0;
    if(r1==c2){
        r=r1;
        c = c2;
    }else if(r2==c1){
        r= r2;
        c = c2;
    }else{
        r=0,c=0;
    }
    int** m = (int**)malloc(r*sizeof(int*));
    for(int i=0;i<r;i++){
        m[i] = (int*)malloc(c*sizeof(int));
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            for(int k=0;k<c1;k++){
                sum = sum + m1[i][k]*m2[k][j];
            }
            m[i][j] = sum;
            sum=0;
        }
    }
    print_matrix(m,r,c);
}

void print_matrix(int** m,int r ,int c){
    printf("Matrix multiplication:\n");
    for(int i=0;i<r;i++){
        for(int j =0;j<c;j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}