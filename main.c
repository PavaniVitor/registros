#include <stdio.h>

#include "linked.h"
#include "data.h"
#include "sorted.h"
#include "file.h"

int main(){
    DATA d0;
    FILE *fp = NULL;
    int i;
    
    createFile();
    auxCreateFile();

    fp = fopen(FILE_PATH, "wb+");
    
    for (i = 0; i < 4096 ; i++){
        d0.i = (char) i;
        sortedInsert(&d0);
    }
    
    return 0;
}