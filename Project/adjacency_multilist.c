#include "headers.h"

/**
 * Creates a basic vertex, which consists of the vertex number. 
 **/
vertex* create_vertex(int number){
    vertex* v = malloc(sizeof(vertex));
    v->number = number;
    return v;
}

/**
 * Creates an edgelist , which has a start and vertex. Also has links which extend to the next edgelist connected to start and vertex.
 * These links are attached using the for-loops given in the function
 * Creates a directed graph, using link locations and directions.
 **/

edge_list* create_edge_list(vertex* start, vertex* end,multilist* multilist){
    printf("Creating edgelist for vertices\n");
    edge_list* temp = malloc(sizeof(edge_list));
    temp->checked = 0;
    temp->v1 = start;
    temp->v2 = end;
    temp->v1_link = NULL;
    temp->v2_link = NULL;
    for( int i=0;i<multilist->no_of_edges;i++){
            if((multilist->edge_array[i]) && (multilist->edge_array[i]->v1->number==start->number)&&(multilist->edge_array[i]->v1_link==NULL)){
                multilist->edge_array[i]->v1_link =temp;
                printf("Assigned a v1 link\n");
                break;
            }
    }
    for(int i=0;i<multilist->no_of_edges;i++){
            if((multilist->edge_array[i])&&(multilist->edge_array[i]->v2->number==start->number)&&(multilist->edge_array[i]->v2_link==NULL)){
                multilist->edge_array[i]->v2_link = temp;
                printf("Assigned a v2 link\n");
                break;
            }
    }
    return temp;

}

/**
 * Creates an empty multilist with a specific size.
 **/
multilist* init_multilist(int edges){
    multilist* temp = malloc(sizeof(multilist));
    temp->no_of_edges=edges;
    temp->edge_array = malloc(sizeof(edge_list)*edges);
    for(int i=0;i<edges;i++){
        temp->edge_array[i]=NULL;
    }
    return temp;
}

/**
 * Calls the insert_edge_list function to create and populate a new edge with that edgelist.
 **/
void insert_edge(int edge_number, vertex* start, vertex* end, multilist* multilist){
    if(edge_number<multilist->no_of_edges){
        printf("Inserting edge for %d and %d\n",start->number,end->number);
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

/*
*   TODO Delete doesn't clean up pre existing edge links. Fix issue, if required.
*
*/
void delete_edge(vertex* start, vertex* end,multilist* multilist){
        printf("Deleting edge\n");
        for( int i=0;i<multilist->no_of_edges;i++){
            if((multilist->edge_array[i])&& multilist->edge_array[i]->v1->number==start->number && multilist->edge_array[i]->v2->number == end->number){
                free(multilist->edge_array[i]);
                multilist->edge_array[i]=NULL;
                printf("Edge successfully deleted\n----------------------------------\n");
                return;
            }
        }
        printf("Edge not found\n----------------------------\n");
}

void print_multilist(multilist* multilist){
    printf("Printing vertices\n\n");
    for(int i=0;i<multilist->no_of_edges;i++){
        if(multilist->edge_array[i]){
            printf("Edge between %d and %d\n",multilist->edge_array[i]->v1->number,multilist->edge_array[i]->v2->number);
            printf("Memory location of edgelist %p ,Pointer 1 : %p and Pointer 2: %p\n",multilist->edge_array[i],multilist->edge_array[i]->v1_link,multilist->edge_array[i]->v2_link);
        }else{
            printf("Empty vertex\n");
        }
    }
    printf("----------------------------------\n");
}

/**
 * Debug method to check link connections
 * vert -> used to indicate which vertex the traversal is occuring on
 **/
void traverse_vertex_links(int vert,edge_list* start){
    //DEBUG : printf("Current vertex pointer position %p\n",start);
    if(start!=NULL){
        printf("Utilizing the %d vertex ,Edge between %d and %d\n",vert,start->v1->number,start->v2->number);
        traverse_vertex_links(1,start->v1_link);
        traverse_vertex_links(2,start->v2_link);
        
    }
}
