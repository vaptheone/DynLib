#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dyn_lib.h"
#include "llist.h"
#include "heap.h"

void swap(int *a, int *b)
{
    int t = *a; *a= *b; *b=t;
}

HEAP createHeap()
{
    HEAP h = (HEAP) malloc (sizeof(heap));
    h->size = 0;
    h->arr = (int *)malloc (100 * sizeof(int));
    return h;
}

int findMin(HEAP H)
{
    return H->arr[1];
}

int isFullHeap(HEAP H)
{
    return (H->size == 100)? 1:0;
}

int isEmptyHeap(HEAP H)
{
    return (!H->size)? 1:0;
}

HEAP extractMin(HEAP H)
{
    if (!H->size)
    {
        printf ("Extraction failed, heap is empty.\n");
        return H;
    }

    H->arr [1] = H->arr[H->size--];

    int nodeIndex = 1;
    while (true)
    {
        int l = 2 * nodeIndex;
        int r = 2 * nodeIndex + 1;
        if (l > H->size) return H;
        int min = r;
        if (r > H->size) min = l;
        else if (H->arr[l] < H->arr[r]) min = l;

        if (H->arr[nodeIndex] < H->arr[min]) return H;
        swap (&H->arr[nodeIndex], &H->arr[min]);
        nodeIndex = min;
    }

    return H;
}

HEAP insertHeap(HEAP H, int k)
{
    if (isFullHeap(H)) 
    {
        printf ("Insertion failed, heap is full\n");
        return H;
    }
    H->arr[H->size + 1] = k;
    int nodeIndex = H->size + 1;
    ++ H->size;

    while (true)
    {
        if (nodeIndex  == 1) return H;
        int p = nodeIndex/2;

        if (H->arr[p] < H->arr[nodeIndex]) return H;
        swap (&H->arr[p], &H->arr[nodeIndex]);
        nodeIndex = p;
    }

    return H;
}

void printHeap(HEAP H)
{
    for (int i = 1; i<= H->size; ++i)
    printf("%d ", H->arr[i]);
    printf("\n");
}

/*
int main()
{
    HEAP h = createHeap();
    insertHeap (h, 5);
    insertHeap (h, 4);
    insertHeap (h, 10);
    insertHeap (h, 2);
    printHeap (h);
    extractMin (h);
    printf("Current minima: %d\n", findMin(h));
    insertHeap (h, 3);
    insertHeap (h, 7);
    printHeap (h);
    extractMin (h);
    printHeap (h);
    extractMin (h);
    extractMin (h);
    printHeap (h);
    extractMin (h);
    extractMin (h);
    printf ("%d", isEmptyHeap (h));
    return 0;
}
*/