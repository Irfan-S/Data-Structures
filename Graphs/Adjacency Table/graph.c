#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

#define MAX_VERT 5

//Implement dynamic version, currently has a fixed size of 5.

Graph* init_graph(int size){
    printf("\nInitializing graph\n--------------------------------\n");
    Graph* m = (Graph*)malloc(sizeof(Graph));
    m->no_of_vertices=size;
    return m;
}

void print_adjmatrix(Graph* graph){
    printf("\nPrinting graph\n--------------------------------\n");
    for(int i=0;i<MAX_VERT;i++){
        for(int j=0;j<MAX_VERT;j++){
            printf("%d ",graph->A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addEdge(int from, int to,Graph* graph){
    printf("--------------------------------\n");
    int max_vertex = graph->no_of_vertices;
    if(from<=max_vertex && to<=max_vertex){
        printf("Adding Edge\n");
        graph->A[from][to] = 1;
    }else{
        printf("Edge out of range.\n");
    }
}

void delEdge(int from, int to, Graph* graph){
    printf("--------------------------------\n");
    int max_vertex = graph->no_of_vertices;
    if(from<=max_vertex && to<=max_vertex){
        printf("Deleting Edge.\n");
        graph->A[from][to] = 0;
    }else{
        printf("Non-existent edge input.\n");
    }
}

void traverse_DFS(Graph* graph,int start,bool* visited){
    printf("%d ",start+1);
    visited[start] = true;
    for(int i=0;i<5;i++){
        if((!visited[i]) && (graph->A[start][i])){
            traverse_DFS(graph,i,visited);
        }
    }

}
