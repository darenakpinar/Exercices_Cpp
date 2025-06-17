#include <stdio.h>
#include <stdbool.h>

bool is_mirrored(int *M, int n_rows, int n_cols){

    for (int i = 0; i < n_rows; i++){
        for (int j = 0; j <n_cols/ 2; j++){
            if (M[n_cols * i + j] != M[n_cols * i + (n_cols -1 - j)])return false;
        }
    }
    return true;
}
