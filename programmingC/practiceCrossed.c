#include <stdio.h>
#include <stdbool.h>


int crossed(int *M, int n_rows, int n_cols){
    
    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j < n_cols; j++){
            if (i+1 == M[i*n_cols + j]){
                return 1;
            }
        }
    }
    return 0;

}

int main(){

    int M[3][3] = { {1,5,1},{0,2,0},{3,7,3}};

    printf("%d\n", crossed(&(M[0][0]), 3,3)); // output 1,  diagonals are 1, 2, 3.

    return 0;
}