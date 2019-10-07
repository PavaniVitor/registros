#include <string.h>
#include <stdio.h>
#include "file.h"

void createFile(){

    FILE *sortedFile = NULL;
    struct fileHeader header;
    header.creationStamp = time(0);
    header.modStamp = 0;
    header.count = 0;
    strcpy(header.fileName, FILE_PATH);
    sortedFile = fopen(FILE_PATH, "wb");
    fwrite(&header , sizeof(FILE_HEADER), 1, sortedFile);
    fclose(sortedFile);
    return;
}
void auxCreateFile(){

    FILE *auxFile = NULL;
    auxFile = fopen(AUX_FILE_PATH, "wb");
    
    struct auxFileHeader auxheader;
    auxheader.creationStamp = time(0);
    auxheader.count = 0;

    fwrite(&auxheader , sizeof(AUX_FILE_HEADER), 1, auxFile);
    fclose(auxFile);
    return;
}
void updateStamp(unsigned int count){
    FILE* fp = NULL;
    fp = fopen(FILE_PATH, "wb+");
    struct fileHeader header;
    fseek(fp, 0, SEEK_SET);
    fread(&header , sizeof(FILE_HEADER), 1, fp);
    header.modStamp = time(0);
    header.count += count;
    fseek(fp, 0, SEEK_SET); 
    fwrite(&header , sizeof(FILE_HEADER), 1, fp);
    return;
}
void updateAuxStamp(unsigned int count){
    FILE* fp = NULL;
    fp = fopen(AUX_FILE_PATH, "wb+");
    struct auxFileHeader auxheader;
    fread(&auxheader , sizeof(AUX_FILE_HEADER), 1, fp);
    fseek(fp, 0, SEEK_SET);
    auxheader.count += count;
    fclose(fp);
}