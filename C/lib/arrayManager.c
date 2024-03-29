#include "arrayManager.h"

#include <time.h>
#include <stddef.h>
#include <stdlib.h>

void remplissageIncremental(int *array, int nbVal){
    for(int i = 0; i < nbVal; i++)
	array[i] = i;
}

void remplissageIncrementalDecale(int *array, int nbVal, int decalage){
    for(int i = 0; i < nbVal; i++)
        array[i] = (i + decalage) % nbVal;
}

void remplissageAleatoire(int *array, int nbVal, int valMax){
    srand(time(NULL));
    for(int i = 0; i < nbVal; i++)
        array[i] = rand() % valMax;
}

void remplissageInverse(int* array, int nbVal){
    for(int i = 0; i < nbVal; i++)
        array[i] = nbVal - i;
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
