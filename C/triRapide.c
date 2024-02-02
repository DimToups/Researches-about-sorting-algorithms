#include "lib/triRapide.h"

#include <stdlib.h>
#include <stdio.h>

void triRapide(int* A, int n);

void sousTriRapide(int* A, int p, int r);

int partition(int* A, int p, int r);

int main(int argc, char** argv){
    // Vérification de la conformité des arguments
    if(argc != 2){
	printf("Usage : %s <arraySize>\n", argv[0]);
	return EXIT_FAILURE;
    }

    int n = atoi(argv[0]);

    int* A = malloc(n * sizeof(int));

    triRapide(A, n);

    free(A);
    
    return EXIT_SUCCESS;
}

void triRapide(int* A, int n){
    sousTriRapide(A, 0, n);
}

void sousTriRapide(int* A, int p, int r){
    if(p < r - 1){
	int q = partition(A, p, r);
	sousTriRapide(A, p, q);
	sousTriRapide(A, q + 1, r);
    }
}

int partition(int* A, int p, int r){
    int pivot = A[r - 1];
    int i = p;
    for(int j = p; j < r - 2; j++){
	if(A[j] <= pivot){
	    int v = A[i];
	    A[i] = A[j];
	    A[j] = v;
	    i++;
	}
    }
    int v = A[i];
    A[i] = A[r - 1];
    A[r - 1] = v;

    return i;
}

