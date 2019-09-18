#include <stdio.h>
#include <stdlib.h>
#include "cll_queue.h"

Queue* init_queue(){

    printf("Initializing Queue..\n\n");
    Queue* m = (Queue*)malloc(sizeof(Queue));
    m->rear=NULL;
    m->front=NULL;
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
        //Fix issues
        if(tmp->next==q->front){
            printf("Removing last element %d from queue..\n",tmp->data);
            q->front=NULL;
            q->rear=NULL;
        }
        else if(tmp!=NULL){
            printf("Removing %d from queue..\n",tmp->data);
            q->front=tmp->next;
            q->rear->next = q->front;
        }
    }

}

void push(Queue* q, int ele){
    Node* tmp = createNode(ele);
    
    if(q->front==NULL){
        printf("Pushing to %d to queue head..\n",ele);
        q->front=tmp;
        tmp->next = q->front;
        q->rear=tmp;
    }else{
        printf("Pushing to %d to queue..\n",ele);
        q->rear->next = tmp;
        tmp->next = q->front;
        q->rear = tmp;
    }
}

void view(Queue* q){
    printf("\nPrinting queue..\n");
    Node* tmp = q->front;
    if(tmp==NULL){
        printf("Empty\n");
    }else{
        do{
            printf("%d ",tmp->data);
            tmp = tmp->next;
        }
        while(tmp!=q->front);
    printf("\n\n");
    }
}
