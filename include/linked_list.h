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

/* Protótipos get data e metadados */
int linked_list_get_value(LinkedList *linked_list);
int linked_list_length(LinkedList *linked_list);
int linked_list_is_empty(LinkedList *linked_list);

/* Protótipos das funções responsáveis por mover o cursor */
void linked_list_next(LinkedList *linked_list);
void linked_list_prev(LinkedList *linked_list);
void linked_list_move_to_start(LinkedList *linked_list);
void linked_list_move_to_end(LinkedList *linked_list);
void linked_list_move_to_pos(LinkedList *linked_list, unsigned int idx);

/* Protótipos das funções para inserir valores */
void linked_list_insert_value(LinkedList *linked_list, int data);
void linked_list_insert_value_at(LinkedList *linked_list, int data, unsigned int idx);
void linked_list_append(LinkedList *linked_list, int data);

/* Protótipos das funções para remover valores e desalocar memória */
int linked_list_remove_element(LinkedList *linked_list);
int linked_list_remove_element_at(LinkedList *linked_list, unsigned int idx);
int linked_list_clear_list(LinkedList *linked_list);
int linked_list_destroy(LinkedList *linked_list);

#endif