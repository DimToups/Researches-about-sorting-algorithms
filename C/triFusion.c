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


int main() {
    int max = 100000000;
    int *a= malloc(max * sizeof(int));;
    srand(time(NULL));

    for (int i = 0; i < max; i++)
	a[i] = rand() % 101;
    printf("\n");

    long clk_tck = CLOCKS_PER_SEC;
    clock_t t1, t2;

    t1 = clock();
    triFusion(a, max);
    t1 = clock();

    printf("\n");
    (void)printf("Nb ticks/seconde = %ld,  Nb ticks depart : %ld, "
                "Nb ticks final : %ld\n",
                clk_tck, (long)t1, (long)t2);
   (void)printf("Temps consomme (s) : %lf \n",
                (double)(t1-t2)/(double)clk_tck);

    for (int i = 1; i < max; i++)
	if (a[i]<a[i-1])
	    printf("ton programme c'est de la merde ");

    free(a);
}
