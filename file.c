#include <string.h>
#include <stdio.h>
#include "file.h"

void createFile(){

    FILE *sortedFile = NULL;
    struct fileHeader header;
    header.creationStamp = time(0);
    header.modStamp = 0;
    strcpy(header.fileName, FILE_PATH);
    sortedFile = fopen(FILE_PATH, "wb");
    fwrite(&header , sizeof(FILE_HEADER), 1, sortedFile);
    fclose(sortedFile);
    return;
}
void updateStamp(FILE* fp){
    
    struct fileHeader header;
    fseek(fp, 0, SEEK_SET);
    fread(&header , sizeof(FILE_HEADER), 1, fp);
    header.modStamp = time(0);
    fseek(fp, 0, SEEK_SET); 
    fwrite(&header , sizeof(FILE_HEADER), 1, fp);
    return;
}