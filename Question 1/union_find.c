#include <stdio.h>
#include <stdlib.h>
#include "union_find.h"

UNION_FIND createUF(int n)
{
    UNION_FIND u = (UNION_FIND)malloc(sizeof(Union));
    u->set_array = (NODE_PTR *)malloc(n * sizeof(NODE_PTR));
    u->size = n;
    for (int i=0; i< n; ++i) u->set_array[i] = NULL;

    return u;
}

UNION_FIND makeSetUF (UNION_FIND F, int x, int *i)
{
    NODE_PTR n = (NODE_PTR) malloc (sizeof(Node_s));
    n->data = x;
    n->next = NULL;

    for (int j=0; j<F->size; ++j)
    {
        if (F->set_array[j] == NULL)
        {
            F->set_array[j] = n;
            *i = j;
            return F;
        }
    }

    printf("Set array full\n");
    return F;
}

NODE_PTR find (UNION_FIND F, NODE_PTR current)
{
    if (current->next == NULL) 
    return current;
    return current->next= find(F, current->next);
}

NODE_PTR findUF (UNION_FIND F, int i)
{
    return find(F, F->set_array[i]);
}

void unionUF (UNION_FIND F, int i, int j)
{
    NODE_PTR n1 = findUF(F, i);
    NODE_PTR n2 = findUF(F, j);

    if (n1->data != n2->data) 
    {
        // printf ("%d %d children merged\n", n1->data, n2->data);
        n2->next = n1;
    }
    else printf("Already in same set\n");
}

/*
int main()
{
    UNION_FIND F;
    F = createUF (10);
    int i;
    makeSetUF (F, 34, &i);
    printf("34 inserted at index: %d\n", i);
    makeSetUF (F, 19, &i);
    printf("19 inserted at index: %d\n", i);
    makeSetUF (F, 5, &i);
    printf("5 inserted at index: %d\n", i);
    makeSetUF (F, 23, &i);
    printf("23 inserted at index: %d\n", i);
    makeSetUF (F, 11, &i);
    printf("11 inserted at index: %d\n", i);
    makeSetUF (F, 47, &i);
    printf("47 inserted at index: %d\n", i);
    makeSetUF (F, 9, &i);
    printf("9 inserted at index: %d\n", i);
    makeSetUF (F, 28, &i);
    printf("28 inserted at index: %d\n", i);
    unionUF(F, 1, 2);
    unionUF(F, 1, 4);
    unionUF(F, 0, 5);
    unionUF(F, 5, 6);
    unionUF(F, 4, 7);
    unionUF(F, 0, 6);

    return 0;
}
*/