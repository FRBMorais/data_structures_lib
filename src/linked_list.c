#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
    new_linked_list->size = 0;
    return new_linked_list;
}

/* ---------------------------------------------------------------*/
/* Corpos get data e metadados */
/* ---------------------------------------------------------------*/
/* retorna o valor do nó imediatamente a direita do cursor,
   caso não exista, retorna o menor inteiro negativo de 32 bits */
int linked_list_get_value(LinkedList *linked_list) {

    if(linked_list->curr->next) {
        return linked_list->curr->next->data;
    } else {
        return INT_MIN;  /* Não há nenhum valor da direita do cursor */
    }

}

/* retorna a quantidade de elementos na linkedlist */
int linked_list_length(LinkedList *linked_list) {

    return linked_list->size;

}

/* retorna 1 se a linked_list esta vazia, e 0 se nao esta */
int linked_list_is_empty(LinkedList *linked_list) {

    return linked_list->size == 0;

}

/* ---------------------------------------------------------------*/
/* Corpos das funções responsáveis por mover o cursor */
/* ---------------------------------------------------------------*/
/* move o ponteiro do cursor para o próximo elemento,
se nao existir, proximo elemento, nao faz nada */
void linked_list_next(LinkedList *linked_list){

    if( linked_list->curr->next && linked_list->curr != linked_list->tail ) {
        linked_list->curr = linked_list->curr->next;
    }

}

/* move o ponteiro do cursor para o elemento anterior,
se nao existir (for o no cabeca), nao faz nada */
void linked_list_prev(LinkedList *linked_list){

}

/* move o ponteiro do cursor para o ponteiro que a apontar para a no sentinela cabeça */
void linked_list_move_to_start(LinkedList *linked_list){
    
    linked_list->curr = linked_list->head;

}

/* move o ponteiro do cursor para a ponteiro que aponta para a calda */
void linked_list_move_to_end(LinkedList *linked_list){
    
    linked_list->curr = linked_list->tail;

}

/* move o cursor para um indice especifico */
void linked_list_move_to_pos(LinkedList *linked_list, unsigned int index){

    
    if(index > linked_list->size) {
        printf("***IndexError: Index out of range***\n");
    } else {
        linked_list->curr = linked_list->head;
        for(int i = 0; i < index; i++) {
            linked_list_next(linked_list);
        }
    }
    
}


/* ---------------------------------------------------------------*/
/* Corpos das funções para inserir valores */
/* ---------------------------------------------------------------*/
/* insere um valor a direita do cursor na linked_list a ajusta o
ponteiro da calda se necessario */
void linked_list_insert_value(LinkedList *linked_list, int data){

    Node *insert_node = node_create(data);

    insert_node->next = linked_list->curr->next;
    linked_list->curr->next = insert_node;

    if(linked_list->curr == linked_list->tail) { /* Caso a insercao foi no final da linked_list */
        linked_list->tail = insert_node;  /* ajusta a calda para o novo nó inserido */
    }

    linked_list->size++; /* atualiza o tamanho da linked list */

}

/* insere um valor em um posicao especificada na linked_list,
e a ajusta o ponteiro da calda se necessario*/
void linked_list_insert_value_at(LinkedList *linked_list, int data, unsigned int index){

    if (index > linked_list->size) {
        printf("***IndexError: Index out of range***\n");
        return;
    }

    Node *temp = linked_list->curr; /* salva a posicao atual do cursor */

    linked_list_move_to_pos(linked_list, index);
    linked_list_insert_value(linked_list, data);

    linked_list->curr = temp; /* retorna o cursor para a posicao original */

}

/* insere um valor no final da linked_list */
void linked_list_append(LinkedList *linked_list, int data){

    Node *new_node = node_create(data);
    linked_list->tail->next = new_node;
    linked_list->tail = new_node;    
    linked_list->size++;          

}

/* ---------------------------------------------------------------*/
/* Corpos das funções para remover valores e desalocar memória */
/* ---------------------------------------------------------------*/
/* remove um elemento a direita do cursor, se houver, e o retorna,
caso contrário, retorna o menor inteiro da macro em limits.h*/
int linked_list_remove_element(LinkedList *linked_list){

}

/* remove um elemento em uma posicao especificada, se houver, e o retorna,
caso contrário, retorna o menor inteiro da macro em limits.h*/
int linked_list_remove_element_at(LinkedList *linked_list, unsigned int index){

}

/* remove todos os elementos da linked_list */
int linked_list_clear_list(LinkedList *linked_list){

}

/* remove todos os elementos da linked_list e desaloca memória
dos nós e da linked_list */
int linked_list_destroy(LinkedList *linked_list){

}