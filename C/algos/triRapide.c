#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void triRapide(int *A, int n);

void sousTriRapide(int *A, int p, int r);

int partition(int *A, int p, int r);

bool estTrie(int *A);

int main(int argc, char** argv){
    // Vérification de la conformité des arguments
    if(argc != 2){
	printf("Usage : %s <arraySize>\n", argv[0]);
	return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    int* A = malloc(n * sizeof(int));

    // Remplissage du tableau
    srand(time(NULL));
    for (int i = 0; i < n; i++)
	A[i] = rand() % 101;

    // Lancement du chronomètre
    clock_t t1;
    t1 = clock();

    // Lancement du tri
    triRapide(A, n);

    // Arrêt du chronomètre
    t1 = clock();

    // Affichage du tableau
    printf("n = %d\n", n);
    for(int i = 0; i < n; i++){
	if(i % 10 == 0)
	    printf("\n[%d] |", i);
	printf(" %d |", A[i]);
    }
    printf("\n");
    printf("Le programme a duré %lf secondes\n", (double)t1 / (double)CLOCKS_PER_SEC);

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

