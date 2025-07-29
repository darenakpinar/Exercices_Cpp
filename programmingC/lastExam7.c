#include <stdio.h>

int second_largest(int const* A, const int n){
    int max_number = A[0];  // On task we assume n > 1
    int second_number = A[1];
    if (second_number > max_number){
        max_number = A[1];
        second_number = A[0];
    }
    for (int i = 0; i < n; i++ ){
        if (A[i] > max_number){
            second_number = max_number;
            max_number = A[i];
        }else if (A[i] > second_number && A[i] < max_number){
            second_number = A[i];
        }
    }
    return second_number;
}
int main(){
    int A[] = {3, -4, 2, 0, 5};
    printf("%d\n", second_largest(A, 5)); // 3
    printf("%d\n", second_largest(A, 4)); // 2
    printf("%d\n", second_largest(A, 3)); // 2
    printf("%d\n", second_largest(A, 2)); // -4
    
    return 0;

}