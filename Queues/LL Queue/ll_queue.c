#include <stdio.h>
#include <stdlib.h>
#include "ll_queue.h"

Queue* init_queue(){

    printf("Initializing Queue..\n");
    Queue* m = (Queue*)malloc(sizeof(Queue));
    m->rear=NULL;
    m->front=m->rear;
    m->size=0;
    return m;
}

Node* createNode(int ele){
    Node* n = (Node*)malloc(sizeof(Node));
    n->data=ele;
    n->next=NULL;
    return n;
}

void pop(Queue* q){
    Node* tmp = q->front;
    if(tmp!=NULL){
        q->front=tmp->next;
    }

}

void push(Queue* q, int ele){
    Node* tmp = createNode(ele);
    if(q->front==NULL){
        q->front=tmp;
        //tmp->next=q->rear;
        q->rear=tmp;
    }else{
        q->rear->next = tmp;
        q->rear = tmp;
    }
}

void view(Queue* q){
    Node* tmp = q->front;
    if(tmp==NULL){
        //q->rear=NULL;
        //q->front=q->rear;
        printf("Empty\n");
    }else{
    while(tmp!=NULL){
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    }
}
