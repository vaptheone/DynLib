#include <stdio.h>
#include <stdlib.h>
#include "dyn_lib.h"
#include "llist.h"

LLIST createList()
{
    LLIST l = (LLIST)malloc(sizeof (list));
    l->head = (NODE*) malloc (sizeof(NODE));
    l->head->value = 0;
    l->head->next = NULL;
    l->size = 0;
    // printf("list created\n");
    return l;
}

int searchList(LLIST H, int k)
{
    NODE * p = H->head->next;
    while (p)
    {
        if (p->value == k) return 1;
        else p = p->next;
    }
    return 0;
}

LLIST insertAtFront(LLIST H, int k)
{
    NODE* p = (NODE *)malloc(sizeof(NODE));
    p->value = k;
    p->next = H->head->next;
    H->head->next = p;
    ++H->size;
    // printf("insertion done\n");
    return H;
}

LLIST insertAtEnd(LLIST H, int k)
{
    if (H->size > 0)
    {
        NODE * p = H->head->next;
        while (p->next)
        {
            p = p->next;
        }
        NODE * q = (NODE *)malloc(sizeof (NODE));
        q->value = k;
        q->next = NULL;
        p->next = q;
        ++H->size;
        return H;
    }
    else return insertAtFront (H, k);
}

LLIST deleteFromFront(LLIST H, int *k)
{
    NODE *p = H->head->next;
    H->head->next = H->head->next->next;
    *k = p->value;
    --H->size;
    return H; //new list returned
}

LLIST deleteFromEnd(LLIST H, int *k)
{
    NODE *p = H->head->next;
    while (p->next->next) p= p->next;

    *k = p->next->value;
    free(p->next);
    p->next = NULL;
    --H->size;
    return H;
}

LLIST deleteList(LLIST H, int k)
{
    if (searchList(H,k))
    {
        NODE *p = H->head;
        while (p->next)
        {
            if (p->next->value == k) break;
            else p = p->next;
        }
        p->next = p->next->next;
        -- H->size;
        return H;
    }
    else return NULL;
}

void print(LLIST H)
{
    if (H->size>0)
    {
        NODE * p = H->head->next;
        while (p)
        {
            printf("%d ",p->value);
            p= p->next;
        }
        printf("\n");
    }
}

/*
int main()
{
    LLIST l = createList();
    l = insertAtFront(l,2);
    l = insertAtEnd(l,5);
    // printf("lol\n");
    print(l);
    l = insertAtEnd(l,4);
    l = insertAtEnd(l,3);
    print(l);
    int k;
    l = deleteFromEnd(l,&k);
    printf("%d deleted from end!\n",k);
    print(l);
    l = deleteFromEnd(l,&k);
    print(l);
    l = deleteFromFront(l, &k);
    print(l);

    return 0;
}
*/