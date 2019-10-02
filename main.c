#include <stdio.h>

#include "linked.h"


int main(){

    LIST *list = init_list();

    printf("%li \n", sizeof(list));
    return 0;
}