#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

int main(){
    printf("--------------------------------\nProgram to perform graph operations on an Adjacency table representation\n");
    printf("Enter max no. of vertices");
    int sz =0;
    scanf("%d",&sz);
    Graph* graph = init_graph(sz);
    printf("------------------------------\n-0 to exit\n-1 x y to add edge from x to y\n-2 x y to delete edge from x to y\n-3 for dfs traversal\n-4 to print adj matrix\n-----------------------------------\n");
    int ch=1;
    int from;
    bool* visited = malloc(sizeof(bool)*sz);
    for (int i=0;i<sz;i++){
        visited[i] = false;
    }
    int to;
    while(ch){
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        
            scanf("%d",&from);
            scanf("%d",&to);
            addEdge(from-1,to-1,graph);
            break;

        case 2:

            scanf("%d",&from);
            scanf("%d",&to);
            delEdge(from-1,to-1,graph);
            break;
        
        case 3:
             printf("--------------------------------\n");
            printf("DFS traversal of graph..\n");
            traverse_DFS(graph,0,visited);
            printf("\n--------------------------------\n");
            break;
        
        case 4:
            print_adjmatrix(graph);
            break;
        default:
            break;
        }
    }
    return 0;
}