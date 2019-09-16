#include<stdio.h>
#include<stdlib.h>
/*  Custom code
    Polynomial Addition using Circular Linked List.
 */
typedef struct node{
    int exp;
    int coeff;
    struct node* next;
}Node;

typedef struct List {
    struct node* head;
    int number_of_nodes;
} Circular_List;

Circular_List* init_cll(){
    Circular_List* m_cll = (Circular_List*) malloc(sizeof(Circular_List));
    m_cll->number_of_nodes = 0;
    m_cll->head = NULL;
    return m_cll;
}

Node* create_node(int exp,int coeff){
    Node* m_node = (Node*)malloc(sizeof(Node));
    m_node->coeff = coeff;
    m_node->exp = exp;
    m_node->next = NULL;
    return m_node;
}

void add_term_to_list(int exp, int coeff,Circular_List* cll){
    Node* n_node = create_node(exp,coeff);
    Node* rover = cll->head;
    if(cll->head==NULL){
        n_node->next = n_node;
        cll->head = n_node;
    }else{
        n_node->next = cll->head;
        rover=rover->next;
        while(rover->next!=cll->head){
            rover = rover->next;
        }
        rover->next = n_node;
    }
    cll->number_of_nodes++;
}