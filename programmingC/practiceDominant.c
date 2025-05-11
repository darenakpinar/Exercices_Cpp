#include <stdio.h>
#include <stdbool.h>

bool dominant(int N, int M[N][N]){

    int sumDominant, sumOthers = 0;

    for (int i = 0; i < N;  i++){
        for (int j = 0; j < N; j++){
            if (j  == i){
                sumDominant += M[i][j];
            }else {
                sumOthers += M[i][j];
            }
        }
    }
    if (sumDominant > sumOthers) return true;
    else return false;
}

int main (){
    int A[3][3] = { {10,2,1},{4,11,6},  {7,8,12}};
    printf("%d\n", dominant(3,A)); // output 1   10+11+12 > 2+1+4+6+7+8

    return 0;
}