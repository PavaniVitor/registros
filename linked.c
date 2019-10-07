#include <stdlib.h>
#include "linked.h"


#include <stdio.h>



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

DATA *get_element(LIST *list, const unsigned int pos){
    int i = 0;
    DATA *data = NULL;
    NODE *cursor = NULL;
    cursor = list->head;
    if(pos >= list->lenght)
    {
        // erro trying to get a element out of list
        printf("elemento %i fora da lista\n" , pos);
        return NULL;
    }

    while(i < pos){
        // go to pos
        cursor = cursor->next;
        i++;
    }
    data = (cursor->data);

    return data;
}

void list_remove(LIST *list, const unsigned int pos){
    int i = 0;
    NODE *cursor = NULL;
    NODE *next = NULL;
    cursor = list->head;
    
    if(pos == 0){
        
        list->head = cursor->next;
        free(cursor->data);
        free(cursor);
        list->lenght -= 1;
    }
    else if(pos == list->lenght -1){
        
        while(i < pos){
        // go to pos
        cursor = cursor->next;
        i++;
        }
        
        free(cursor->data);
        free(cursor);
        list->lenght -= 1;
    }
    else{
        while(i < pos - 1){
            // go to pos
            next = cursor->next;
            i++;
        }

        cursor = next->next;
        
        free(cursor->data);
        next->next = cursor->next;
        free(cursor);

        list->lenght -= 1;
    }

    // remove element
    
    return;
}