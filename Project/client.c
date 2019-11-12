#include "headers.h"

int main(){
    printf("Graph using Adjacency multi-list representation\n-----------------------------------\n");
    printf("Enter the max number of edges in graph:");
    int max;
    scanf("%d",&max);
    printf("\n----------------------------------------\n");
    printf("Options:\n1 edge-number vertex vertex- insert edge\n2 vertex vertex- delete edge\n3- print graph\n4 starting edge- traverse edges\n0- exit\n--------------------------------\n");
    int ch = 1;
    multilist* multilist = init_multilist(max);
    while(ch){
        scanf("%d",&ch);
        int edge_number;
        int v1;
        int v2;
        int start_edge;
        vertex* ver1;
        vertex* ver2;
        switch (ch)
        {
        case 0:
            printf("Exiting program\n");
            break;
        case 1:
            scanf("%d",&edge_number);
            scanf("%d",&v1);
            scanf("%d",&v2);
            ver1 = create_vertex(v1);
            ver2 = create_vertex(v2);
            insert_edge(edge_number,ver1,ver2,multilist);
            break;
        case 2:
            scanf("%d",&v1);
            scanf("%d",&v2);
            ver1 = create_vertex(v1);
            ver2 = create_vertex(v2);
            delete_edge(ver1,ver2,multilist);
            break;
        
        case 3:
            print_multilist(multilist);
            break;
            
        case 4:
            scanf("%d",&start_edge);
            printf("Traversing vertex links\n--------------------------------------\n");
            traverse_vertex_links(multilist->edge_array[start_edge]);
            printf("\n------------------------------------------------\n");
            break;
        default:
            printf("Invalid choice, please retry...\n");
            break;
        }
    }

    printf("-------------------------------------\n");


    return 0;
}