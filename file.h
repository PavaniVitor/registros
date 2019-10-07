#ifndef FILE_UTIL
#define FILE_UTIL

#define FILE_PATH "sorted.bin" 
#define AUX_FILE_PATH "sortedbuffer.bin" 
#define FILE_NAME "Registros Ordenados"


#include <time.h>
typedef struct fileHeader{
    char fileName[256];
    time_t creationStamp;
    time_t modStamp;
}FILE_HEADER;

typedef struct auxFileHeader{
    time_t modStamp;
    unsigned int count;
}AUX_FILE_HEADER;

void createFile();

#endif