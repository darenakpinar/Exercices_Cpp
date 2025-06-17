#include <stdio.h>

int isSorted(int A[] , int n ){
    if (n == 1) return 1;
    return (A[n - 2] <= A[n - 1]) && isSorted(A, n - 1);
}