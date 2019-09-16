#include <stdlib.h>
#include <stdio.h>
#include "josephus.h"

//TODO Solve Josephus TBD


// cll* init_cll(int num_persons){
//     int pos=1;
//     cll* m_cll = (cll*)malloc(sizeof(cll));
//     m_cll->num_of_nodes = num_persons;
//     node* linker = (node*)malloc(sizeof(node));
//     linker->next=NULL;
//     linker->data=pos;
//     pos++;
//     m_cll->head=linker;
//     node* rover = linker;
//     while(num_persons>=pos){
//         node* n_node = (node*)malloc(sizeof(node));
//         n_node->data=pos;
//         n_node->next=NULL;
//         rover->next=n_node;
//         rover=rover->next;
//         pos++;
//         //printf("hi\n");
//     }
//     rover->next = m_cll->head;
// }

// void print_cll(cll* m_cll){
//     node* rover = m_cll->head;
//     if(rover!=NULL){
//         int c=0;
//         while(c<m_cll->num_of_nodes){
//             printf("Person %d ",rover->data);
//             rover=rover->next;
//             c++;
//         }
//         printf("\n");
//     }else{
//         printf("EMPTY\n");
//     }
// }

// void eliminate(cll* m_cll, int pos_to_be_eliminated){
//     node* rover = m_cll->head;
//     while (m_cll->num_of_nodes>1)
//     {
//         int counter=1;
//         while(counter<pos_to_be_eliminated-1){
//             rover = rover->next;
//             counter++;
//             printf("Rover moved\n");
//         }
//         if(counter==pos_to_be_eliminated-1){
//             printf("Killing person %d \n",rover->next->data);
//             rover->next = rover->next->next;
//             m_cll->num_of_nodes--;
//         }
//         printf("Removed 1 person, new list is: \n");m_cll->num_of_nodes--;
//         print_cll(m_cll);
//     }
    
// }

// int main(){
//     cll* m_cll = init_cll(3);
//     print_cll(m_cll);
//     eliminate(m_cll,3);
//     print_cll(m_cll);
//     return 0;
// }
