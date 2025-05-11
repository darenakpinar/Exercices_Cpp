#include <stdio.h>
int delta( int *A, int A_size){
    int greatest= A[0];
    int smallest = A[0];

    for (int i = 0; i < A_size; i++){
       if (smallest > A[i]){
            smallest = A[i];
       }
       else if (greatest < A[i]){
        greatest = A[i];
       }
    }
    return greatest - smallest;
}
int main(){
    int A[] = {1, 5, 8, 3};
    printf("%d \n", delta(A,4)); // 8 - 1 = 7
    return 0;
}