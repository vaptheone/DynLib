#include <stdio.h>
#include <stdlib.h>
#include "../Question 1/dyn_lib.h"
#include "../Question 1/llist.h"
#include "../Question 1/queue.h"

QUEUE createQueue()
{
    QUEUE q = (QUEUE) malloc (sizeof (queue));
    q->list = createList();
    q->size = 0;
    return q;
}

int isEmptyQueue(QUEUE Q)
{
    return (!Q->size)? 1:0;
}

QUEUE enqueue(QUEUE Q, int k)
{
    Q->list = insertAtEnd(Q->list, k);
    ++ Q->size;
    return Q;
}

QUEUE dequeue(QUEUE Q, int *k)
{
    Q->list = deleteFromFront(Q->list, k);
    -- Q->size;
    return Q;
}

void printQueue(QUEUE Q)
{
    print(Q->list);
}

/*
int main()
{
    QUEUE q = createQueue();
    enqueue (q, 2);
    enqueue (q, 6);

    printQueue(q);
    int k;
    dequeue (q, &k);
    printf ("%d dequeued\n", k);
    enqueue (q, 5);
    printQueue(q);
    dequeue (q, &k);
    dequeue (q, &k);
    printQueue (q);
    printf ("%d", isEmptyQueue(q));

    return 0;
}
*/
