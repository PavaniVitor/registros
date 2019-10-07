#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.h"
#include "sorted.h"
#include "data.h"


void sortedInsert(DATA *data){
    static DATA* buff = NULL;
    static const int size = BUFFER_SIZE/(sizeof(DATA));
    static int pos = 0; 
    int i = 0;
    
    if(!buff){
        buff = (DATA*)malloc(BUFFER_SIZE);
    }
    buff[pos] = *data;
    pos += 1;
    
    if (pos == size){
        // hora de gravar no arquivo
        printf("lotou o buffer \n");

        FILE *fp = NULL;
        fp = fopen(AUX_FILE_PATH, "rb+");
        AUX_FILE_HEADER header;
        fread(&header, sizeof(AUX_FILE_HEADER), 1, fp);
        printf("numero lido do header: %d", header.count);
        if(header.count >= AUX_MAX_COUNT - pos){
            // grava os registros do arquivo auxiliar no arquivo principal (ordena)
            // grava os registros do buffer no arquivo auxiliar
            // atualiza os headers
            
            pos = 0;
            printf("debugado\n");
        }
        
        else{
            int j = 0;
            printf("to gravando o auxiliar \n");
            fseek(fp, 0, SEEK_END);
            j = fwrite(buff, sizeof(DATA), pos, fp);
            printf("%d \n" , j);
            fseek(fp, 0, SEEK_SET);
            header.count += pos;
            printf("numero gravado no header: %d ", header.count);
            fwrite(&header, sizeof(AUX_FILE_HEADER), 1, fp);            
            pos = 0;
        }
        fclose(fp);
    }
    
    if (pos == 10){
        for(i = 0; i < pos; i++){
            printf("%d \n", buff[i].i);
        }
    }
}

void selectSorted(){

}

void sortedDelete(){

}