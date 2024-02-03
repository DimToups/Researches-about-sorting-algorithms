#include "lib/triInsertion.h"
#include "lib/triFusion.h"
#include "lib/triRapide.h"
#include "lib/arrayManager.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdint.h>

int main(int argc, char** argv){
    // Vérification de la conformité des arguments
    if(argc != 5){
	printf("Usage : %s <algo> <tailleTableau> <valeurMaximale> <nbOccurences>\n    <algo>\n\t-i : tri par insertion\n\t-f : tri par fusion\n\t-r : tri rapide\n", argv[0]);
	return EXIT_FAILURE;
    }

    // Décision du fichier csv lié aux paramètres d'exécution à ouvrir ou créer
    FILE *csvFile;
    char *fileName = malloc(64 * sizeof(char));
    strcat(fileName, "out/");
    if(!strcmp(argv[1], "-i"))
	strcat(fileName, "insertion");
    else if(!strcmp(argv[1], "-f"))
	strcat(fileName, "fusion");
    else if(!strcmp(argv[1], "-r"))
	strcat(fileName, "rapide");
    else{
	printf("L'algorithme renseigné n'est pas valide");
	return EXIT_FAILURE;
    }
    strcat(fileName, argv[2]);
    strcat(fileName, ".csv");

    // Ouverture ou création du fichier
    if((csvFile = fopen(fileName, "a")) == NULL){
	printf("Une erreur est survenue lors de l'ouverture du fichier\n");
	return EXIT_FAILURE;
    }

    // Allocation d'un tableau d'entiers
    int *A = malloc(atoi(argv[2]) * sizeof(int));

    // Instanciation de variables de statistiques
    uint32_t nbRatures = 0;
    clock_t ts, tf;

    // Lancement du chronomètre de début d'exécution de la boucle
    ts = clock();
    
    // Execution du tri
    for(int i = 0; i < atoi(argv[4]); i++){
	// Affichage de la progression du programme
	if(ceil(log((double) i)) > ceil(log((double) i - 1)))
	    printf("\r%d / %d", i, atoi(argv[4]));
	else
	    printf("\r%d", i);
	
	// Réinitialisation du tableau
	if(i != 0)
	    memset(A, 0, sizeof(int));

	// Remplissage du tableau
	remplissageAleatoire(A, atoi(argv[2]), atoi(argv[3]));

	// Préparation et lancement du chronomètre
	clock_t t1, t2;
	t1 = clock();

	// Choix du tri a effectuer
	if(!strcmp(argv[1], "-i"))
	    triInsertion(A, atoi(argv[2]));
	else if(!strcmp(argv[1], "-f"))
            triFusion(A, atoi(argv[2]));
	else
	    triRapide(A, atoi(argv[2]));

	// Arrêt du chronomètre
	t2 = clock();

	// Vérification de la qualité du tri
	bool estValide = estTrie(A);

	// Inscription du temps d'exécution dans le fichier
	if(estValide)
	    fprintf(csvFile, "%7lf,", (double) (t2 - t1) / (double) CLOCKS_PER_SEC);
	else{
	    nbRatures++;
	    fprintf(csvFile, "-1,");
	}
    }
    // Arrêt du chronomètre d'exécution de la boucle
    tf = clock();

    // Affichage des informations d'exécution
    printf("\r%d / %d\nTemps d'exécution du programme : %lf secondes\nNombre de tri ratés : %d\n", atoi(argv[4]), atoi(argv[4]), (double)(tf - ts) / (double) CLOCKS_PER_SEC, nbRatures);

    // Fermeture du fichier csv
    fclose(csvFile);

    // Libération de la mémoire
    free(A);
    free(fileName);

    return EXIT_SUCCESS;
}

