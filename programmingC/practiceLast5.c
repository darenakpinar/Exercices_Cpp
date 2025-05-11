#include <stdio.h>

int delta (int *A, int A_size){
    int lowest = A[0];
    int secondLowest = A[1];
    if (lowest > secondLowest){
        int temp = lowest;
        lowest = secondLowest;
        secondLowest = temp;
    }
    for (int i = 2; i < A_size; i++){
        if (A[i] <= lowest){
            secondLowest = lowest;
            lowest = A[i];
        }
        else if(A[i] < secondLowest && A[i] > lowest){
            secondLowest = A[i];
        }
    }
    return secondLowest - lowest;
}
int main(){

    int A[] = {1, 5, 8, 3};
    printf("%d \n", delta(A, 4));
    return 0;
}