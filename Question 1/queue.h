typedef struct queue
{
    LLIST list;
    int size;
}queue;

typedef queue * QUEUE;

QUEUE createQueue();

int isEmptyQueue( QUEUE );

QUEUE enqueue( QUEUE , int );

QUEUE dequeue( QUEUE , int *);

void printQueue( QUEUE );