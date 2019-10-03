#include <stdlib.h>
#include "linked.h"

#include <stdio.h>

#include <string.h>

LIST *init_list(){
    LIST *list = NULL;
    list = malloc(sizeof(LIST));
    
    list->head = NULL;
    list->lenght = 0;

    if (list == NULL){
        // erro 
        printf("erro ao inicializar a lista");
    }
    return list; 
}

void list_insert(LIST *list, DATA data){
    NODE *new_node = NULL;
    DATA *node_data = NULL;
    
    new_node = malloc(sizeof(NODE));
    node_data = malloc(sizeof(DATA));

    if (!new_node || !node_data){
        // erro
        printf("erro ao inserir elemento na lista");
    }
    
    *node_data = data;
    new_node->data = node_data;
    new_node->next = list->head;
    list->head = new_node;
    list->lenght += 1;

    return;
}

void list_remove(LIST *list, const unsigned int pos){
    int i = 0;
    NODE *cursor = NULL;
    DATA aux; 
    cursor = list->head;
  
    while(i < pos){
        // go to pos
        cursor = cursor->next;
        i++;
    }
    aux = *(cursor->data);
    printf("data lida: %i\n" , aux.i );
    // remove element
    
    return;
}

DATA *get_element(const unsigned int pos){
    DATA *data;

    return data;
}