typedef struct heap
{
    int *arr, size;
}heap;

typedef heap * HEAP;

void swap(int *, int *);

HEAP createHeap();

int findMin(HEAP );

int isFullHeap(HEAP );

int isEmptyHeap(HEAP );

HEAP extractMin(HEAP );

HEAP insertHeap(HEAP , int );

void printHeap(HEAP );