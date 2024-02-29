#include "triFusion.h"
#include "triInsertion.c"

#include <stdio.h>
#include <stdlib.h>

void fusion(int* A, int p, int q, int r) {
  int n1 = q - p;
  int n2 = r - q;
  int *An = malloc((r - p) * sizeof(int));
  for (int i = 0; i < n1; i++)
    An[i] = A[p + i];
  for (int i = 0; i < n2; i++)
    An[i] = A[q + i];

  triInsertion(An, r - q);
  //printf("p = %d\tq = %d\tr = %d\n", p, q, r);
  for(int i = 0; i < (r - p); i++)
    A[i + p] = An[i];
    // Erreur à partir d'une certaine valeur

  free(An);
}

void sousTriFusion (int* A, int p,int r) {
  // Si le tableau à traiter a une taille supérieure à 1, faire le tri
  if (p < r - 1) {
    int q = (p + r) / 2;
    sousTriFusion(A, p, q);
    sousTriFusion(A, q, r);
    fusion(A, p, q, r);
  }
}

void triFusion(int* A, int n) {
  sousTriFusion(A, 0, n);
}

