#include <stdlib.h>
#include <string.h>
#include "linked.h"

LIST *init_list(){
    LIST *list = NULL;
    list = malloc(sizeof(LIST)); 
    if (list == NULL){
        // erro 
    }
    return list; 
}

void list_insert(LIST *list, DATA data){
    NODE *new_node = NULL;
    DATA *node_data = NULL;
    
    new_node = malloc(sizeof(NODE));
    node_data = malloc(sizeof(DATA));

    if (new_node == NULL || node_data == NULL){
        // erro
    }

    memcpy(node_data , &data , sizeof(DATA));
    new_node->next = list->head;
    list->head = new_node;

    return;
}

void list_remove(const unsigned int pos){
    int i;

    while(i < pos){
        // go to pos
    }
    // remove element
    
    return;
}

DATA *get_element(const unsigned int pos){
    DATA *data;

    return data;
}