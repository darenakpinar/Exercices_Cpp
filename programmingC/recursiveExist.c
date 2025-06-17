#include <stdio.h>

int exists(int A[], int n, int val){
    if (n == 0) return 0;
    if (A[n - 1] == val) return 1;
    return exists(A, n - 1, val);
}