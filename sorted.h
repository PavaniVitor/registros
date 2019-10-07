#ifndef SORTED
#define SORTED
#include <time.h>

#define SORTED_R_PATH "sorted.bin" 
#define BUFFER_R_PATH "sortedbuffer.bin" 
#define SORTED_FILE_NAME "Registros Ordenados"

struct sortedHeader{
    char fileName[256];
    time_t creationStamp;
    time_t modStamp;
}SORTED_HEADER;

struct bufferHeader{
    time_t modStamp;
    unsigned int count;
};

void createSortedFile();


#endif