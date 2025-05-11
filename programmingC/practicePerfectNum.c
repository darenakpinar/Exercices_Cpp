#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_perfect(int *M, size_t n_rows, size_t n_cols){
    
    for (int i = 0; i < n_rows; i++){  
        int sum  = 0;   
        for (int j = 0; j < n_cols; j++){
            sum += M[i * n_cols + j];
        }
        if (sum != (1 << (i + 1))) {
            return false;
        }
    }
    return true;

}

int main(){

   int A[4][3] = { {0,1,1}, // 0+1+1 = 2
        {2,0,2}, // 2+0+2 = 4
        { 5,1,2}, // 5+1+2 = 8
        {6,7,3}}; // 6+7+3 = 16

    if (!is_perfect(&A[0][0], 4, 3)){
        printf("0\n");
    }else{
        printf("1\n");
    }
    return 0;
}