#include<stdio.h>
#include<stdlib.h>
struct dllnode{
    int data;
    //left link
    struct dllnode* llink;
    //right link
    struct dllnode* rlink;
};
typedef struct dllnode Node;

Node* create_node(int data){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->llink = NULL;
    new_node->rlink = NULL;
    return new_node;
}

void insert_at_front(Node* head, int data){
    Node* new_head = create_node(data);
    if(head==NULL){
        head = new_head;
        return;
    }
    new_head->rlink= head;
    head->llink = new_head;
    new_head->llink=NULL;
    head = new_head;
}

void insert_at_end(Node* head,int data){
    Node* new_node = create_node(data);
    if(head==NULL){
        head=new_node;
        return;
    }
    Node* rover = head;
    while(rover->rlink!=NULL){
        rover = rover->rlink;
    }
    rover->rlink = new_node;
    new_node->llink = rover;
    new_node->rlink = NULL;

}

void insert_at_pos(Node* head, int ele, int pos){
    Node* new_node = create_node(ele);
    if(head==NULL){
        head = new_node;
        return;
    }
    int loc_pos=0;
    Node* rover  = head;
    while(rover->rlink!=NULL){
        if(loc_pos==pos){
            new_node->llink = rover;
            new_node->rlink = rover->rlink;
            rover->rlink = new_node;
            if(rover->rlink!=NULL){
                rover->rlink->llink= new_node;
            }
            return;
        }
        rover = rover->rlink;
        loc_pos++;
    }
    if(loc_pos==pos){
        insert_at_end(head,ele);
    }
    printf("Invalid position entered\n");
}

void delete_node_at_front(Node* head){
    
}