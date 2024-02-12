#include "triFusion.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fusion(int* A, int p, int q, int r) {
    int n1 = q - p;
    int n2 = r - q;
    int *Ag = malloc(n1 * sizeof(int));
       int *Ad = malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++)
        Ag[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        Ad[j] = A[q + j];

    int indg = 0;
    int indd = 0;
    int i = p;

    while(i < r) {
      if (indg == n1) {
        A[i] = Ad[indd];
        indd++;
      }
      else if (indd == n2) {
        A[i] = Ag[indg];
        indg++;
      }
      else if (Ag[indg] < Ad[indd]) {
        A[i] = Ag[indg];
        indg++;
      }
      else {
        A[i] = Ad[indd];
        indd++;
      }
      i++;
    }

    free(Ag);
    free(Ad);
}



void sousTriFusion (int* A, int p,int r) {
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

