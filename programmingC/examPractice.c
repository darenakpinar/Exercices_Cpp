#include <stdio.h>


int n_matches(int a[], int b[], int x){
    int matches = 0;
    for (int i = 0; i<x; i++){
        if (a[i] == b[i]){
            matches++;
        }
    }
    return matches;
}
int main(){
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {1, 5, 3, 4, 2};
    int C[] = {1, 0, 3, 4, 2};

    printf("%d \n", n_matches(A,B,5));
    printf("%d \n", n_matches(B,C, 5));
    
    return 0;
}