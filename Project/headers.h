#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vert{
    int number;
} vertex;

typedef struct ed{
    vertex* start;
    vertex* end;
    int edge_number;
} edge;

typedef struct eg{
    int checked;
    vertex* v1;
    vertex* v2;
    struct eg* v1_link;
    struct eg* v2_link;
} edge_list;

typedef struct e_list{
    edge_list** edge_array;
    int no_of_edges;
} multilist;

vertex* create_vertex(int data);
edge_list* create_edge_list( vertex* start, vertex* end,multilist* multilist);
multilist* init_multilist(int edge_count);

void insert_edge(int edge_number, vertex* start, vertex* end,multilist* multilist);
void delete_edge( vertex* start, vertex* end,multilist* multilist);
void print_multilist(multilist* multilist);
void traverse_vertex_links(edge_list* edge_list);
