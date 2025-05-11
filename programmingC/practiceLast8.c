#include <stdio.h>

int count_twice(int x[], int x_size, int y[], int y_size){
    int count = 0;
    for (int i = 0; i < x_size; i++){

        if (x[i] == y[i]*2 ){
            count++;
        }
    }
    return count;
}

int main(){

    int A[] = {2, 4, 6, 8, 10};
    int B[] = {1, 2, 3, 4, 5};
    printf("%d \n", count_twice(A,5,B,5));
    int C[] = {10, 20, 30, 40};
    int D[] = {5, 10, 20, 20};
    printf("%d \n", count_twice(C,4,D,4));
}