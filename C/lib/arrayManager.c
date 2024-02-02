#include "arrayManager.h"

#include <time.h>
#include <stddef.h>
#include <stdlib.h>

void remplissageTableau(int *array, int nbVal, int valMax){
    srand(time(NULL));
    for(int i = 0; i < nbVal; i++)
        array[i] = rand() % valMax;
}

bool estTrie(int *A){
    bool estTrie = true;
    int i = 1;
    while(estTrie && i < sizeof(A)){
	if(A[i - 1] > A[i])
	    estTrie = false;
	i++;
    }
    return estTrie;
}
