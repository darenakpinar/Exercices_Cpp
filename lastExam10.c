#include <stdio.h>
#include <stdbool.h>

int count_inversions(int const *A, int const n){
   if (n == 0) return 0;
    const int x = *A;
    int count = 0;
    for (int i = 1; i != n; i ++){
        if (x > A[i])count += 1;
    }

    return count + count_inversins(A+1, n - 1);
}

int main(){
    int A[] = {3, -4, 2, 0, 5};
    printf("%d\n", count_inversions(A,5));

    int B[] = {9, -2, 3, 1, 0, -6, 34, -1};
    printf("%d\n", count_inversions(B, 8)); // 17
}


