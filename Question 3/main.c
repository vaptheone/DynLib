#include <stdio.h>
#include <stdlib.h>
#include <graphlib/dyn_lib.h>
#include <graphlib/llist.h>
#include <graphlib/stack.h>
#include <graphlib/queue.h>
#include <graphlib/union_find.h>
#include <graphlib/graph.h>

int main()
{
    char a[10] = "new.txt";
    GRAPH G = readGraph(a);
    DFS(G);
    printf("\n");
    BFS(G);
    printf("\n");
    MST(G);
    
    return 0;
}