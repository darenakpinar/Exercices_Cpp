#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool is_mirrored(int *M, int n_rows, int n_cols) {
    for (int i = 0; i < n_rows; i++) {
        // check row i
        for (int j = 0; j < n_cols/2; j++) {
            int left  = M[i*n_cols + j];
            int right = M[i*n_cols + (n_cols - 1 - j)];
            if (left != right) {
                return false;
            }
        }
    }
    return true;
}

int main(){
    int A[3][4] = {
        {1, 2, 2, 1},
        {0, 0, 0, 0},
        {7, 2, 2, 7}
    };

    printf("%d\n", is_mirrored(&A[0][0], 3, 4)); // output 1

    return 0;
}