#include <stdio.h>

int *colwise(const int m, const int n, int M[m][n]){

        int len = m * n;
        int *ptr = (int*)malloc(len * sizeof(int));
        int k = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){

                ptr[k++] = M[j][i];
            } 
        }
        return ptr;
}

int main(){

    int M[3][4] = { { 1, 2, 3, 4},
         { 5, 6, 7, 8},
        { 9, 10, 11, 12} };
    int* V = colwise(3, 4, M); // V is {1,5,9,2,6,10,3,7,11,4,8,12}

    return 0;
}