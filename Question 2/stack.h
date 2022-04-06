typedef struct stack
{
    LLIST list;
    int size;
}stack;

typedef stack * STACK;

STACK createStack();

int isEmptyStack(STACK );

STACK push(STACK , int );

STACK pop(STACK , int *);

void printStack(STACK );