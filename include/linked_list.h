#ifndef _LINKED_LIST /* evita duplo import */
#define _LINKED_LIST


typedef struct Node {
    int data;
    struct Node *next;
} Node;


typedef struct LinkedList {
    int size;
    Node *curr, *tail, *head;  /* implementação usando nó sentinela */
} LinkedList;


/* protótipos das funções */

/* protótipos das funções construtoras */
Node *node_create(int data);
LinkedList *linked_list_create();

#endif