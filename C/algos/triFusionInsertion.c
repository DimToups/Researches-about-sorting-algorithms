#include "../lib/triFusionInsertion.c"
#include "../lib/arrayManager.c"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char** argv) {
    if(argc < 3){
        printf("Usage : %s <nbVal> <valMax>\n\tOptions : -r : a; i; d\n", argv[0]);
        return EXIT_FAILURE;
    }
    int nbVal = atoi(argv[1]);
    int *a= malloc(nbVal * sizeof(int));
    int remplissage = 0;
    int decalage = 0;
    if(argc > 5 && strcmp(argv[3], "-r") == 0){
        if(strcmp(argv[4], "a") == 0)
            remplissage = 0;
        else if(strcmp(argv[4], "i") == 0)
            remplissage = 1;
        else if(strcmp(argv[4], "d") == 0){
            remplissage = 2;
            if(atoi(argv[5]) != 0)
                decalage = atoi(argv[5]);
            else{
                printf("Le décalage n'est pas valide");
                free(a);
                return EXIT_FAILURE;
            }
        }
        else
            remplissage = 0;
    }
    else
        remplissage = 0;

    switch (remplissage) {
        case 0 : remplissageAleatoire(a, nbVal, atoi(argv[2])); break;
        case 1 : remplissageIncremental(a, nbVal);  break;
        case 2 : remplissageIncrementalDecale(a, nbVal, decalage); break;
        default : remplissageAleatoire(a, nbVal, atoi(argv[2])); break;
    }

    triFusion(a, nbVal);

    free(a);
}
