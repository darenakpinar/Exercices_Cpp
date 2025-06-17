#include <stdio.h>

int minArr(int A[], int n){
    if (n == 1) return A[0];
    int min_rest = minArr(A, n -1);
    
    return (A[n -1] < min_rest) ? A[n - 1] : min_rest;
}