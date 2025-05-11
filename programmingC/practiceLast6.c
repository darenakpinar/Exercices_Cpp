#include <stdio.h>
#include <stddef.h> /*for size_t */

float euclidean(const float *X, const int X_size,size_t n,size_t Y_size){

    if (n == 0 || n != m){

        return 0.0f;
    }

    float sum = 0.0f;

    for (size_t i = 0; i < n; i++){
        float d =  A[i] - B[i];
        sum += d * d;
    }

    return sum;


}

int main(){

    float A[] = {1.0f, 2.0f, 4.0f, 8.0f};
    float B[] = {1.0f, 1.0f, 4.0f, 4.0f};
    printf("%f \n", euclidean(A,4,B,4));
}