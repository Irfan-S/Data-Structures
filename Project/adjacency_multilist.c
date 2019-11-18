#include "headers.h"
#define INFINITY 9999
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
    printf("\n----------------------------------\n");
}

/**
 * Debug method to check link connections
 * vert -> used to indicate which vertex the traversal is occuring on
 **/
void traverse_vertex_links(int vert,edge_list* start){
    //DEBUG : printf("Current vertex pointer position %p\n",start);
    if(start!=NULL){
        printf("Utilizing the %d vertex ,Edge between %d and %d\n",vert,start->v1->number,start->v2->number);
        traverse_vertex_links(start->v1->number,start->v1_link);
        traverse_vertex_links(start->v2->number,start->v2_link);
    }
}

/**
 * Generates the indices which represent the directed adjacency matrix.
 * Used to implement dijkastra's shortest path
 **/
void generate_indices(int vert,edge_list* start,int ** G){
    if(start!=NULL){
        G[start->v1->number][start->v2->number] = 1;
        generate_indices(start->v1->number,start->v1_link,G);
        generate_indices(start->v2->number,start->v2_link,G); 
    }
}


int** create_matrix(int size){
    int ** G = malloc(size*sizeof(int*));
    for(int i=0;i<size;i++){
        G[i] = (int*)malloc(size*sizeof(int));
    }
    return G;
}

void print_matrix(int** m,int r){
    printf("Matrix is:\n");
    for(int i=0;i<r;i++){
        for(int j =0;j<r;j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void dijkstra(int** G,int n,int startnode)
{
 
	int cost[n][n],distance[n],pred[n];
	int visited[n],count,mindistance,nextnode,i,j;
	
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	
	while(count<n-1)
	{
		mindistance=INFINITY;
		
		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
			
			//check if a better path exists through nextnode			
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
 
	//print the path and distance of each node
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of node%d=%d",i,distance[i]);
			printf("\nPath=%d",i);
			
			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);
            printf("\n");
	}
}



