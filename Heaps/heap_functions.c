#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int parent(int i){
    return (i-1)/2;
}
int left(int i){
    return (2*i)+1;
}
int right(int i){
    return (2*i)+2;
}

void heapify(heap* hp,int pos){
    int lrg = pos;
    if(left(pos)<hp->max && hp->arr[left(pos)]>hp->arr[lrg]){
        lrg = left(pos);
    }
    if(right(pos)<hp->max && hp->arr[right(pos)]>hp->arr[lrg]){
        lrg = right(pos);
    }
    if(pos!=lrg){
        int t = hp->arr[lrg];
        hp->arr[lrg]= hp->arr[pos];
        hp->arr[pos] = t;
        heapify(hp,lrg);
    }
}

heap* create_heap(int len){
    heap* loc = malloc(sizeof(heap));
    loc->max = len;
    loc->len =0;
    loc->arr = malloc(sizeof(int)*len);
    return loc;
}

void insert_heap(int ele,heap* hp){
    int i = hp->len;
    if(hp->max>=hp->len){
        hp->arr[hp->len]=ele;
        hp->len++;
        while( hp->arr[parent(i)]<hp->arr[i] && parent(i)>=0){
            int t = hp->arr[parent(i)];
            hp->arr[parent(i)]= hp->arr[i];
            hp->arr[i] = t;
            i = parent(i);
        }
        printf("Successfully inserted\n");
        printf("-------------------------------\n");}
    else{
        printf("Length exceeded\n");
        printf("-------------------------------\n");
    }
}

void print_heap(heap* hp){
    printf("Printing elements of heap...\n");
    for(int i=0;i<hp->len;i++){
        printf("%d ",hp->arr[i]);
    }
    printf("-------------------------------\n");
}

void max_ele(heap* hp){
    if(hp->len>0){
        printf("Max element in heap is: %d\n",hp->arr[0]);
    }else{
        printf("Heap is empty\n");
    }
    printf("-------------------------------\n");
}

void delete_ele(int ele, heap* hp){
    if(!(hp->len>0)){
        printf("Heap is empty\n");
        return;
    }
    //search for ele
    int pos=hp->len;
    while(pos>=0){
        if(hp->arr[pos]==ele){
            break;
        }else{
            pos--;
        }
    }
    if(pos>=0){
        hp->arr[pos] =hp->arr[(hp->len)-1];
        hp->len--;
        //Reheapify structure;
        heapify(hp,pos);
        printf("Element successfully deleted.\n");
        printf("-------------------------------\n");

    }else{
        printf("Element not found.\n");
        printf("-------------------------------\n");
        return;
    }
}