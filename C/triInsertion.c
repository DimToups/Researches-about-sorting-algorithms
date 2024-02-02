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
  int max=200000;
 int* a =malloc(max*sizeof(int));
 for (size_t i = 0; i < max; i++) {
    a[i] = rand() %(100 + 1);;

       printf("%d-", a[i]); }

printf("\n" );
time_t begin = time( NULL );

a=TrieInsertion(a,max);
 time_t end = time( NULL);


for (size_t i = 0; i < max ; i++) {

      printf("%d-", a[i]); }
      printf("\n" );


      unsigned long secondes = (unsigned long) difftime( end, begin );
       printf( "Finished in %ld sec\n", secondes );
       free(a);

return 0;


}
