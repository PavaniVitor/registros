#include <stdio.h>

#include "linked.h"
#include "data.h"


int main(){
    int i = 0;
    LIST *list = init_list();
    DATA d0;
    DATA d1;
    DATA d2;
    DATA d3;
    DATA d4;
    DATA *aux;
    d0.i = 1;
    d1.i = 2;
    d2.i = 3;
    d3.i = 4;
    d4.i = 5;
    
    list_insert(list, d0);
    list_insert(list, d1);
    list_insert(list, d2);
    list_insert(list, d3);
    list_insert(list, d4);


    for(i = 0; i < 5; i++){
        printf("%d \n", get_element(list, i)->i);
    }

    list_remove(list, 3);

    list_remove(list, list->lenght - 1);
    list_remove(list, list->lenght - 1);
    
    
    for(i = 0; i < list->lenght; i++){
        printf("%d \n", get_element(list, i)->i);
    }

    printf("tamanho da lista: %i \n" , list->lenght);

    return 0;
}