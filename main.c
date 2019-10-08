#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "linked.h"
#include "data.h"
#include "sorted.h"
#include "file.h"


int main(){
    DATA d0;
    FILE *fp = NULL;
    int i;


    if (!fopen(FILE_PATH, "rb")){
        createFile();
    }
    if (!fopen(AUX_FILE_PATH, "rb")){
        auxCreateFile();
    }

    srand(time(0));
    
    fp = fopen(FILE_PATH, "wb+");
    
    for (i = 0; i < 4096 ; i++){
        d0.i = rand();
        sortedInsert(&d0);
    }
    
    return 0;
}