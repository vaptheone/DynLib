typedef struct list
{
    NODE * head;
    int size;
}list;

typedef list* LLIST;

LLIST createList();

int searchList(LLIST , int );

LLIST insertAtFront(LLIST , int );

LLIST insertAtEnd(LLIST ,int );

LLIST deleteFromFront(LLIST , int *);

LLIST deleteFromEnd(LLIST , int *);

LLIST deleteList(LLIST , int k);

void print(LLIST );