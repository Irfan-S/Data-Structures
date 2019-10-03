#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

int main(){
    Graph* graph = init_graph();
    /*
        0 to exit
        1 x y to add edge from x to y
        2 x y to delete edge from x to y
        3 for dfs traversal
        4 to print adj matrix
    */
    int ch=1;
    int from;
    int to;
    while(ch){
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        
            scanf("%d",&from);
            scanf("%d",&to);
            addEdge(from,to,graph);
            break;

        case 2:

            scanf("%d",&from);
            scanf("%d",&to);
            delEdge(from,to,graph);
            break;
        
        case 3:
            traverse_DFS(graph,0,0);
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