#include "headers.h"

vertex* create_vertex(int number){
    vertex* v = malloc(sizeof(vertex));
    v->number = number;
    return v;
}


edge_list* create_edge_list( vertex* start, vertex* end,multilist* multilist){
    printf("Creating edgelist for vertices\n");
    edge_list* temp = malloc(sizeof(edge_list));
    temp->checked = 0;
    temp->v1 = start;
    temp->v2 = end;
    temp->v1_link = NULL;
    temp->v2_link = NULL;
    for( int i=0;i<multilist->no_of_edges;i++){
            if((multilist->edge_array[i]) && (multilist->edge_array[i]->v1->number==start->number)){
                multilist->edge_array[i]->v1_link =temp;
                printf("Assigned a v1 link\n");
                break;
            }
    }
    for(int i=0;i<multilist->no_of_edges;i++){
            if((multilist->edge_array[i])&&(multilist->edge_array[i]->v2->number==start->number)){
                multilist->edge_array[i]->v2_link = temp;
                printf("Assigned a v2 link\n");
                break;
            }
    }
    return temp;

}

multilist* init_multilist(int edges){
    multilist* temp = malloc(sizeof(multilist));
    temp->no_of_edges=edges;
    temp->edge_array = malloc(sizeof(edge_list)*edges);
    for(int i=0;i<edges;i++){
        temp->edge_array[i]=NULL;
    }
    return temp;
}

void insert_edge(int edge_number, vertex* start, vertex* end, multilist* multilist){
    if(edge_number<multilist->no_of_edges){
        printf("Inserting edge\n");
        for(int i=0;i<multilist->no_of_edges;i++){
            if((multilist->edge_array[i])&& multilist->edge_array[i]->v1->number==start->number && multilist->edge_array[i]->v2->number == end->number){
                printf("Edge already exists..\n");
                return;
            }
        }
        edge_list* new_edge = create_edge_list(start,end,multilist);
        multilist->edge_array[edge_number] = new_edge;
        printf("Edge successfully added\n---------------------------------\n");
    }
}

void delete_edge(vertex* start, vertex* end,multilist* multilist){
        printf("Deleting edge\n");
        for( int i=0;i<multilist->no_of_edges;i++){
            if((multilist->edge_array[i])&& multilist->edge_array[i]->v1->number==start->number && multilist->edge_array[i]->v2->number == end->number){
                multilist->edge_array[i]= NULL;
                printf("Edge successfully deleted\n----------------------------------\n");
                return;
            }
        }
        printf("Edge not found\n----------------------------\n");
}

void print_multilist(multilist* multilist){
    printf("Printing vertices\n");
    for(int i=0;i<multilist->no_of_edges;i++){
        if(multilist->edge_array[i]){
            printf("Edge between %d and %d\n",multilist->edge_array[i]->v1->number,multilist->edge_array[i]->v2->number);
            printf("Pointer 1 : %p and Pointer 2: %p\n",multilist->edge_array[i]->v1_link,multilist->edge_array[i]->v2_link);
        }else{
            printf("Empty vertex\n");
        }
    }
    printf("----------------------------------\n");
}

//TODO to check if the links are connected properly, still a little glitchy...
void traverse_vertex_links(edge_list* start){
    //printf("Current pointer position %p\n",start->v1_link);
    if(start->v1_link!=NULL){
        printf("Utilizing the first vertex ,Edge between %d and %d\n",start->v1->number,start->v2->number);
        traverse_vertex_links(start->v1_link);
        
    }
    if(start->v2_link!=NULL){
        printf("Utilizing the second vertex ,Edge between %d and %d\n",start->v1->number,start->v2->number);
        traverse_vertex_links(start->v2_link);
    }
    if(start->v1_link==NULL){
        printf("Reached end of vertex 1 connections\n");
    }
    if(start->v2_link==NULL){
        printf("Reached end of vertex 2 connections\n");
    }
}
