#include "sorted.h"
#include <stdio.h>
#include <string.h>

void createSortedFile(){

    FILE *sortedFile = NULL;
    struct sortedHeader header;
    header.creationStamp = time(0);
    header.modStamp = 0;
    strcpy(header.fileName, SORTED_FILE_NAME);
    sortedFile = fopen(SORTED_R_PATH, "wb");
    fwrite(&header , sizeof(SORTED_HEADER), 1, sortedFile);
    fclose(sortedFile);
    return;
}

void insert(){

}

void select(){

}