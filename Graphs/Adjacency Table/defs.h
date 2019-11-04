#include <stdbool.h>
typedef struct graph{
    int no_of_vertices;
    int A[5][5];
} Graph;

Graph* init_graph(int sz);
void print_adjmatrix(Graph* graph);
void addEdge(int from, int to, Graph* graph);
void delEdge(int from, int to, Graph* graph);
void traverse_DFS(Graph* graph, int start, bool* visited);