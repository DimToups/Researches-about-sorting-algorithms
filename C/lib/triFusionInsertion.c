#include "triFusionInsertion.h"
#include "triInsertion.c"

#include <stdio.h>
#include <stdlib.h>

void fusion(int* A, int p, int q, int r, int lim) {
  if(r - p < lim){
    int n1 = q - p;
    int n2 = r - q;
    int *Ag = malloc(n1 * sizeof(int));
    int *Ad = malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++)
      Ag[i] = A[p + i];
    for (int i = 0; i < n2; i++)
      Ad[i] = A[q + i];

    int indg = 0;
    int indd = 0;
    int i = p;

    while(i < r) {
      // Si toutes les valeurs de Ag ont été ajoutées, ajouter la prochaine de Ad
      if (indg == n1) {
        A[i] = Ad[indd];
        indd++;
      }
      // Si toutes les valeurs de Ad ont été ajoutées, ajouter la prochaine de Ag
      else if (indd == n2) {
        A[i] = Ag[indg];
        indg++;
      }
      // Si la prochaine valeur de Ag est inférieure à la prochaine valeur de Ad, l'ajouter
      else if (Ag[indg] < Ad[indd]) {
        A[i] = Ag[indg];
        indg++;
      }
      // Si la prochaine valeur de Ad est inférieure à la prochaine valeur de Ag, l'ajouter
      else {
        A[i] = Ad[indd];
        indd++;
      }
      i++;
    }

    free(Ag);
    free(Ad);
  }
  else
    triInsertion(A, r - p);
}

void sousTriFusion (int* A, int p,int r, int lim) {
  // Si le tableau à traiter a une taille supérieure à 1, faire le tri
  if (p < r - 1) {
    int q = (p + r) / 2;
    sousTriFusion(A, p, q, lim);
    sousTriFusion(A, q, r, lim);
    fusion(A, p, q, r, lim);
  }
}

void triFusion(int* A, int n, int lim) {
  sousTriFusion(A, 0, n, lim);
}

