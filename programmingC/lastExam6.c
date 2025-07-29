#include <stdio.h>

int prod(const int m, const int n, int M[m][n], const int i, const int j){
    int sumOfRow = 0, sumOfCol = 0;
    for (int k = 0; k < n; k++){
        sumOfRow += M[i][k];
    }
    for (int t = 0; t < m; t++){
        sumOfCol += M[t][j];
    }
    return sumOfRow * sumOfCol;
    
}

int main(){
    int M[3][4] = {     
    {0, 8, 23, 3}, 
    {-1, 4, 6, 7},
    {8, 11, 7, -3}};
    
    printf("%d\n", prod(3, 4, M[3][4], 1, 3));
    return 0;
}