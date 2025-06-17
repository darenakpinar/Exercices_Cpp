#include <>


bool dominant(int N, int M[N][N]){
    int sumDiagonal = 0;
    int sumOther = 0;
    for (int i = 0; i < N; i++){   
        for (int j = 0; j < N; j++){

            if (i == j){
                sumDiagonal += M[i][j];
            }else {
                sumOther += M[i][j];
            }
        }
    }
    if (sumDiagonal > sumOther)return true;
    
    return false;
}