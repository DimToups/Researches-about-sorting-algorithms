#include "../lib/triFusion.c"
#include "../lib/arrayManager.c"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    if(argc != 3){
	printf("Usage : %s <nbVal> <valMax>\n", argv[0]);
	return EXIT_FAILURE;
    }
    int nbVal = atoi(argv[1]);
    int *a= malloc(nbVal * sizeof(int));

    remplissageAleatoire(a, nbVal, atoi(argv[2]));

    triFusion(a, nbVal);

    free(a);
}
