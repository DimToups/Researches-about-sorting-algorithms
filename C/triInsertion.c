#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

int* TrieInsertion(int* A, int n) {
    for (size_t i = 1; i < n; i++) {
        int cle = A[i];
        int j = i - 1;
        while ((j >= 0) && (A[j] > cle)) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = cle;
    }
    return A;
}

int main() {
  int max=20000;
 int* a =malloc(max*sizeof(int));
 for (size_t i = 0; i < max; i++) {
    a[i] = rand() %(100 + 1);;

     }

printf("\n" );

    long clk_tck = CLOCKS_PER_SEC;
    clock_t t1 ;
    t1 = clock();

a=TrieInsertion(a,max);
t1 = clock();



//for (size_t i = 0; i < max ; i++) {

  //    printf("%d-", a[i]); }
    //  printf("\n" );


    printf("\n");
    printf("Nb ticks/seconde = %ld,  Nb ticks depart : %ld, \n",
                clk_tck, (long)t1);
   printf("Temps consomme (s) : %lf \n",
                (double)(t1)/(double)clk_tck);
       free(a);

return 0;


}
