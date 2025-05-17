#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"


Node *node_create(int data){

    /* alocação de memória para um novo nó*/
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(!new_node) {
        /* falha - na alocação de memória para o nó */
    }

    /* atribuições*/
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}


LinkedList *linked_list_create(){

    LinkedList *new_linked_list = (LinkedList *)malloc(sizeof(LinkedList));
    if(!new_linked_list) {
        /* falha - na alocação de memória para a linked list */
    }

    /* criação do nó sentinela */
    Node *sentinel = node_create(0);  /* na funcao node_create ja verificamos se a alocacao foi bem sucedida */
    
    /* atribuições */
    new_linked_list->curr = new_linked_list->head = new_linked_list->tail = sentinel;

    return new_linked_list;
}