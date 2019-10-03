typedef int AdjacencyTable[6][6];
typedef struct graph{
    int no_of_vertices;
    AdjacencyTable A;
} Graph;

Graph* init_graph();
void print_adjmatrix(Graph* graph);
void addEdge(int from, int to, Graph* graph);
void delEdge(int from, int to, Graph* graph);
void traverse_DFS(Graph* graph, int row, int col);