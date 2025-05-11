#include <stdio.h>
#include <stdlib.h>

int** transpose(int** M, int m, int n) {
    // 1) allocate n rows
    int** T = malloc(n * sizeof *T);

    // 2) for each row i (0 ≤ i < n), allocate m ints
    for (int i = 0; i < n; i++) {
        T[i] = malloc(m * sizeof *T[i]);
        // 3) copy column i of M into row i of T
        for (int j = 0; j < m; j++) {
            T[i][j] = M[j][i];
        }
    }
    return T;
}
int main(){

    int M[2][3] = { {0,1,2}, {3,4,5}};

    printf("%d\n", transpose(M, 2, 3)); // output {}// {{0, 3} {1, 4} {2, 5}}

    return 0;
}