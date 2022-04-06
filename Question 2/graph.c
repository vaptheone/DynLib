#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <newlib.h>
#include "graph.h"

#define MAX 100000

//function for reading the graph
GRAPH readGraph(char * FName)
{
    FILE * f;
    GRAPH G = (GRAPH)malloc(sizeof(graph));
    int i, j, k, n, m;
    f = fopen(FName, "r");
    fscanf(f, "%d", &n);

    // G = (GRAPH)malloc(sizeof(graph));
    G->adj_matrix = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    G->adj_matrix[i] = (int *)malloc(n * sizeof(int));

    for (i =0; i< n; ++i)
    {
        for (j=0; j< n; ++j)
        {
            G->adj_matrix[i][j] = MAX;
            G->adj_matrix[j][i] = MAX;
        }
    }
    G->num_nodes = n;
    fscanf(f, "%d", &m);
    G->num_edges = m;

    for (k =0; k<m; ++k)
    {
        int wieght;
        fscanf(f, "%d %d %d", &i, &j, &wieght);
        G->adj_matrix[i][j] = wieght;
        G->adj_matrix[j][i] = wieght;
    }

    return G;
}

//Depth First Search using Stack
void DFS (GRAPH G)
{
    printf("DFS traversal of graph: ");
    int i,j;
    bool visited [G->num_nodes];
    
    for (i=0; i<G->num_nodes; ++i) visited[i] = false;
    STACK S = createStack();

    for (i=0; i<G->num_nodes; ++i)
    if (!visited[i])
    {
        visited[i] = true;
        push(S, i);
        while (!isEmptyStack(S))
        {
            int u; 
            pop(S, &u);
            printf("%d ", u);
            for (j=0; j<G->num_nodes; ++j)
            if (G->adj_matrix[u][j] < MAX && !visited[j])
            {
                visited[j] = true;
                push(S, j);
            }
        }
        printf("\n");
    }
    
}

//Breadth First Search using Queue
void BFS (GRAPH G)
{
    printf("BFS traversal of graph: ");
    int i,j;
    bool visited [G->num_nodes];
    
    for (i=0; i<G->num_nodes; ++i) visited[i] = false;

    for (i=0; i<G->num_nodes; ++i)
    if (!visited[i])
    {
        visited[i] = true;
        QUEUE Q = createQueue();
        enqueue(Q, i);
        while (!isEmptyQueue(Q))
        {
            int u;
            dequeue(Q, &u);
            printf("%d ", u);
            for (j=0; j<G->num_nodes; ++j)
            if (G->adj_matrix[u][j] < MAX && !visited[j])
            {
                visited[j] = true;
                enqueue(Q, j);
            }
        }
        printf("\n");
    }
}

//Finds the minimum spanning tree using Kruskal's algorithm
void MST (GRAPH G)
{
    UNION_FIND u = createUF(G->num_nodes);
    int i,j;

    for (i=0; i<G->num_nodes; ++i)
    makeSetUF (u, i, &j);

    printf("MST:-\n");
    int edge_cnt = 0, cost = 0;

    while (edge_cnt < G->num_nodes - 1)
    {
        int min = MAX, a = -1, b=-1; 
        for (i=0; i< G->num_nodes; ++i)
        for (j=0; j< G->num_nodes; ++j)
        if (G->adj_matrix[i][j] < min && findUF(u, i) != findUF(u,j))
        {
            min = G->adj_matrix[i][j];
            a = i;
            b = j;
        }
        if (a != -1 && b != -1)
        {
            printf("Edge : %d %d, weight = %d\n", a, b, min);
            unionUF(u, a, b);
            edge_cnt++;
            cost += min;
        }
    }

    printf("-> Minimum cost = %d \n", cost);
}

/*
int main()
{
    char a[8] = "new.txt";
    GRAPH G = readGraph(&a[0]);

    // for Printing graph :-
    // for (int i = 0 ; i < G->num_nodes; ++i)
    // {
    //     for (int j = 0; j < G->num_nodes; ++j)
    //     printf("%d ", G->adj_matrix[i][j]);
    //     printf("\n");
    // }

    DFS (G);
    BFS (G);
    MST (G);

    return 0;
}
*/
