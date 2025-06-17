#include <stdio.h>

int sumArr(int A[], int n ){
    if (n == 0) return 0;
    return sum(A, n - 1) + A[n -1];
}