#include "headers.h"

int main(){
    printf("\n\nGraph using Adjacency multi-list representation\n\n-----------------------------------\n");
    printf("Enter the max number of vertices:");
    int vertex_count;
    scanf("%d",&vertex_count);
    printf("\nEnter the max number of edges in graph:");
    int max;
    scanf("%d",&max);
    printf("\n----------------------------------------\n");
    printf("\nOptions:\n1 <edge-number> <vertex> <vertex>- insert edge\n2 <vertex> <vertex>- delete edge\n3- print graph\n4 <starting edge>- traverse edges\n5 <starting edge> <start vertex> - Shortest path\n0- exit\n--------------------------------\n\n");
    int ch = 1;
    multilist* multilist = init_multilist(max);
    while(ch){
        scanf("%d",&ch);
        int edge_number;
        int v1;
        int** matrix;
        int v2;
        int start_vertex;
        int start_edge;
        vertex* ver1;
        vertex* ver2;
        switch (ch)
        {
        case 0:
            printf("Exiting program\n");
            return 0;
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
            printf("Traversing vertex links\n--------------------------------------\n\n");
            traverse_vertex_links(1,multilist->edge_array[start_edge]);
            printf("\n------------------------------------------------\n");
            break;
        case 5:
            scanf("%d",&start_edge);
            scanf("%d",&start_vertex);
            matrix = create_matrix(vertex_count);
            printf("Preparing matrix representation for shortest path\n------------------------------------------\n");
            generate_indices(1,multilist->edge_array[start_edge],matrix);
            //print_matrix(matrix,vertex_count);
            dijkstra(matrix,vertex_count,start_vertex);
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