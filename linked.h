#ifndef LINKED_LIST
#define LINKED_LIST
#include "data.h"

typedef struct node{
    struct data *data;
    struct node *next;
}NODE;

typedef struct list{
    struct node *head;
    unsigned int lenght;
}LIST;

LIST *init_list();

void list_insert(LIST *list, DATA data);

void list_remove(LIST *list, const unsigned int pos);

DATA *get_element(LIST *list, const unsigned int pos);

#endif
