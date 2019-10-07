#ifndef FILE_UTIL
#define FILE_UTIL

#define FILE_PATH "sorted.bin" 
#define AUX_FILE_PATH "sortedbuffer.bin"
#define AUX_MAX_COUNT 4096 // numero de registros suportados no arquivo auxiliar
#define FILE_NAME "Registros Ordenados"

/* 
deve ser igual ao tamanho do bloco do sistema de arquivos
4096 para Ext4 (Linux)
4096 para NTFS com volumes de até 16TB
*/

#define BUFFER_SIZE 4096  

#include <time.h>


typedef struct fileHeader{
    char fileName[256];
    time_t creationStamp;
    time_t modStamp;
    unsigned int count;
}FILE_HEADER;

typedef struct auxFileHeader{
    time_t creationStamp;
    unsigned int count;
}AUX_FILE_HEADER;

void createFile();
void createAuxFile();

void updateStamp(unsigned int count);
void updateAuxStamp(unsigned int count);

#endif