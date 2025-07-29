#include <stdio.h>
#include <stdbool.h>


int count_subset(int *A, int A_size, int n){

    if (A_size == 0)  return (n < 0) ? 1 : 0;
   
    int include = count_subset(A + 1, A_size -1, n - A[0]);
    int exclude = count_subset(A + 1, A_size - 1, n);

    return include + exclude;

}

int main (){

    int v1[] = {1,2,3,0,6,7};
    printf("%d\n", count_subset(v1, 6, 15));
    // 10
    return 0;
    
}