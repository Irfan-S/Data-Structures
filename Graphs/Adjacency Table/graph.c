#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

#define MAX_VERT 6

Graph* init_graph(){
    Graph* m = (Graph*)malloc(sizeof(Graph));
    m->no_of_vertices=MAX_VERT;
    int i,j;
    for(i=0;i<MAX_VERT;i++){
        for(j=0;j<MAX_VERT;j++){
            m->A[i][j]=0;
        }
    }
    return m;
}

void print_adjmatrix(Graph* graph){
    printf("\nPrinting Adjacency matrix..\n");
    for(int i=0;i<MAX_VERT;i++){
        for(int j=0;j<MAX_VERT;j++){
            printf("%d ",graph->A[i][j]);
        }
        printf("\n");
    }
}

void addEdge(int from, int to,Graph* graph){
    int max_vertex = graph->no_of_vertices;
    if(from<=max_vertex && to<=max_vertex){
        graph->A[from][to] = 1;
    }else{
        printf("Edge out of range.\n");
    }
}

void delEdge(int from, int to, Graph* graph){
    int max_vertex = graph->no_of_vertices;
    if(from<=max_vertex && to<=max_vertex){
        graph->A[from][to] = 0;
    }else{
        printf("Non-existent edge input.\n");
    }
}

//Getting some errors. Check and fix.
void traverse_DFS(Graph* graph,int row, int col){
    //If the Adjacency Matrix item is not 1 i.e is 0
    if(!(graph->A[row][col])){
        if(col<graph->no_of_vertices){
            col++;
            traverse_DFS(graph,row,col);
        }else if(row< graph->no_of_vertices){
            col=0;
            row++;
            traverse_DFS(graph,row,col);
        }
    }else{
        if(col< graph->no_of_vertices){
            printf("Edge from %d to %d\n",row,col);
            col++;
            traverse_DFS(graph,row,col);
        }else if(row < graph->no_of_vertices){
            printf("Edge from %d to %d\n",row,col);
            col=0;
            row++;
            traverse_DFS(graph,row,col);
        }
    }
}
