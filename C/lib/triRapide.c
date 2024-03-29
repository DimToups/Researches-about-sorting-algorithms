#include "triRapide.h"

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
    for(int j = p; j < r - 1; j++){
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

