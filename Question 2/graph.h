// #include <newlib/dyn_lib.h>
// #include <newlib/llist.h>
// #include <newlib/stack.h>
// #include <newlib/queue.h>
// #include <newlib/union_find.h>
// #include <newlib/heap.h>

typedef struct graph
{
    int num_nodes;
    int ** adj_matrix;
    int num_edges;
} graph;

typedef graph* GRAPH;

GRAPH readGraph(char *);

void BFS(GRAPH );

void DFS(GRAPH );

void MST(GRAPH );
