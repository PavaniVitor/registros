#include <stdio.h>

#include "linked.h"
#include "data.h"


int main(){

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

    list_remove(list, 0);
    list_remove(list, 1);
    list_remove(list, 2);
    list_remove(list, 3);
    list_remove(list, 4);


    printf("tamanho da lista: %i \n" , list->lenght);

    printf("%li \n", sizeof(list));
    return 0;
}