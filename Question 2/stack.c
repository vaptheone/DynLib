#include <stdio.h>
#include <stdlib.h>
#include "../Question 1/dyn_lib.h"
#include "../Question 1/llist.h"
#include "../Question 1/stack.h"

STACK createStack()
{
    STACK p = (STACK) malloc (sizeof (stack));
    p->list = createList();
    p->size = 0;
    return p;
}

int isEmptyStack(STACK S)
{
    return (!S->size)? 1:0;
}

STACK push(STACK S, int k)
{
    S->list = insertAtFront(S->list, k);
    ++ S->size;
    return S;
}

STACK pop(STACK S, int * k)
{
    if (S->size > 0) 
    {
        S->list = deleteFromFront(S->list, k);
        -- S->size;
        return S;
    }
    else return NULL;
}

void printStack(STACK S)
{
    print(S->list);
}

/*
int main()
{
    STACK s = createStack();
    s = push (s, 2);
    s = push (s, 4);
    printStack(s);
    s = push (s, 3);
    // printf("whm\n");
    printStack (s);
    int k;
    s = pop (s, &k);
    printf ("%d popped\n", k);
    s = pop (s, &k);
    printf ("%d popped\n", k);
    printStack(s);
    s = pop (s, &k);
    printf ("%d",isEmptyStack(s));

    return 0;
}
*/