typedef struct Node_s
{
    int data;// value stored in the node
    struct Node_s* next;// to point at next node
    int size;// to store the size of the tree
}Node_s;

typedef Node_s* NODE_PTR;

typedef struct
{
    NODE_PTR* set_array;
    int size;
}Union;

typedef Union* UNION_FIND;

UNION_FIND createUF(int );

UNION_FIND makeSetUF (UNION_FIND , int , int *);

NODE_PTR findUF (UNION_FIND , int );

void unionUF (UNION_FIND , int , int );