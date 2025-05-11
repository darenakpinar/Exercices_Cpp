#include <stdio.h>

int smallest(int x[], int n){

    int smallest = -1;
    for (int i = 0; i < n; i++){
        if (x[i] % 2 == 0 && smallest == -1){
            smallest = x[i];
        }
        else if (x[i] % 2 == 0 && smallest > x[i] && smallest != -1){
            smallest = x[i];
        }
    }
    return smallest;
}

int main(){

    int a[] = {10, 2, 3, 8, 1};
    printf("%d \n", smallest(a,5));
    int b[] = {1, 3, 5, 7, 9};
    printf("%d \n", smallest(b,5));

    return 0;
}