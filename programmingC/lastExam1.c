#include <stdio.h>


int radio (float const* A, float const *B, const int size){
    
    float result = 0;
    int index = 0;
    for (int i= 0; i < size; i++){

        if (B[i] != 0 && A[i]/B[i] > result){
            result = A[i]/ B[i];
            index = i;
        }
    }
    return index;
}

int main(){
    float A[] = { 10, 20, 30, 40, 50, 0};
    float B[] = { 0, 2, 1, 0, 0, 100 };
    printf("%d\n", ratio(A, B, 5)); // 2, because A[2]/B[2] = 30 is the largest ratio

return 0;
}