#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *link;
} Node;

typedef struct List {
	Node* head;
	int number_of_nodes;
} List;

/* initializes a linked list */
List* list_initialize(); 

/* Inserts a new node with data at the beginning */
void list_insert_beginning(List* list, int data);

/* Removes the last node of the linked list */
void list_delete_rear(List* list); 

/* Print the contents of a list */
void list_print(List* list); 

/* Sorts a linked list */
void list_sort(List*);

/* deallocates resources held by the list */
void list_destroy(List* list); 


List* list_initialize(){
    List* tmp = (List*)malloc(sizeof(List));
    tmp->head = NULL;
    tmp->number_of_nodes =0;
    return tmp;
}


void list_insert_beginning(List* list,int data){
       Node* tmp = (Node*)malloc(sizeof(Node));
       tmp->data = data;
       tmp->link= list->head;
       list->head = tmp;
       list->number_of_nodes++;
}

void list_insert_end(List* list, int data){
       Node* tmp = (Node*)malloc(sizeof(Node));
       tmp->data = data;
       tmp->link= NULL;
       Node* ptr = list->head;
       while(ptr->link!=NULL){
           ptr=ptr->link;
       }
       ptr->link=tmp;
       list->number_of_nodes++;
}

void list_insert_between_nodes(Node* before, Node* after, int data){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->data = data;
    tmp->link = after;
    before->link = tmp;
}

void list_delete_rear(List* list){
     Node *ptr,*ptr1;  
        if(list->head == NULL)  
        {  
            

        }  
        else if(list->head->link == NULL)  
        {  
            list->head = NULL;  
            free(list->head);    
        }  
              
        else  
        {  
            ptr = list->head;   
            while(ptr->link != NULL)  
            {  
                    ptr1 = ptr;  
                    ptr = ptr ->link;  
            }  
            ptr1->link = NULL;  
            free(ptr);  
        }     
    }  
    
void list_print(List* list){
    if(list->number_of_nodes==0||list->head==NULL){
        printf("EMPTY\n");
    }else{
    Node* t = (Node*)malloc(sizeof(Node));
    t = list->head;
    while(t!=NULL){
        printf("%d ",t->data);
        t = t->link;
    }

    printf("\n");
    }
} 

//No way to sort memory locations, but data can.
void list_sort(List* list){
    printf("Sorting linked list..\n");
    Node *h1, *h2;
    int a;
    h1 = list->head;
    while(h1!=NULL){
            h2 = h1->link;
            while(h2!=NULL){
                if(h1->data > h2->data){
                    a = h1->data;
                    h1->data = h2->data;
                    h2->data =a;
                }
                h2 = h2->link;
            }
            h1 = h1->link;
    }
}

void list_destroy(List* list){
    free(list);
} 