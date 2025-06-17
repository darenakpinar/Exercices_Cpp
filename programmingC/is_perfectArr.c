#include <stdio.h>
#include <stdbool.h>
#include <cmath.h>

bool is_perfect(int *M, size_t n_rows, size_t n_cols){

    for (int i = 0, i < n_rows; i++){
        int sum_row = 0;
        for (int j = 0; j < n_cols; j++){
           sum_row += M[n_cols * i + j];
            
        }
        int powerTwo = pow(2, i + 1);
        if ( sum_row !=  powerTwo)return false;
    }
    return true;
}