#include "triInsertion.h"

void triInsertion(int* A, int n) {
    for (int i = 1; i < n; i++) {
        int cle = A[i];
        int j = i - 1;
        while ((j >= 0) && (A[j] > cle)) {
            A[j + 1] = A[j];
            j--;
        }
	A[j + 1] = cle;
    }
}
