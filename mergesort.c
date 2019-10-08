/////////////////////////////////////////////////////
//    UFRJ - IM/IMA
//    TMA-B
//    Mileny Loyolla
//    Vitor Pavani
//    DATA: 06/09/2019
/////////////////////////////////////////////////////

#include <string.h>
#include <stdio.h>
#include "mergesort.h"
#include "data.h"

/*
    Função de merge
*/
void merger(DATA *buffer, int l, int m, int r)
{
    int i, j, k;

    int n1 = m - l + 1;
    int n2 = r - m;

    DATA L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i].i = buffer[l + i].i;
    for (j = 0; j < n2; j++)
        R[j].i = buffer[m + 1 + j].i;

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if(memcmp(&(L[i].i),&(R[j].i), sizeof(int)) <= 0)
        {
            buffer[k] = L[i];
            i++;
        }
        else
        {
            buffer[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        buffer[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        buffer[k] = R[j];
        j++;
        k++;
    }
}

/* 
    Função de merge sort recursiva
*/
void mergeSort(DATA *buffer, int l, int r)
{

    if (l < r)
    {

        int m = (l + r) / 2;

        mergeSort(buffer, l, m);
        mergeSort(buffer, m + 1, r);

        merger(buffer, l, m, r);
    }
}
