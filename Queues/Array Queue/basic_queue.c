#include<stdio.h>
#include <stdlib.h>
#include "basic_queue.h"
// Queues are FIFO

Queue* init_queue(){
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->front=0;
    q->rear=-1;
    return q;
}

void push(Queue* loc, int ele){
    if(loc->rear<MAX){
        printf("Pushing %d ..\n",ele);
        loc->rear++;
        loc->array[loc->rear] = ele;
    }
}
void pop(Queue* loc){
    int ele;
    if(loc->front!=loc->rear+1){
        ele = loc->array[loc->front];
        printf("Popping %d..\n",ele);
        loc->front++;
    }else{
        printf("Empty\n");
    }
}

void view(Queue* loc){
    int local_pos = loc->front;
    while(local_pos!=loc->rear+1){
        printf("%d ",loc->array[local_pos]);
        local_pos++;
    }
    if(loc->front==loc->rear+1){
        printf("Empty");
    }
    printf("\n");
}