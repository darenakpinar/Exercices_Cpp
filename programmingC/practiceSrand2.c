#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randint_range(int A, int B){
    return (rand() % (B - A + 1)) + A;
}

int main (void){
    srand(time(NULL));

    int A, B;
    printf("Enter A B (with A < B): ");
    if (scanf ("%d %d", &A, &B) != 2 || A >= B){
        printf("Bad input\n");
        return 1;
    }

    int r = randint_range(A, B);
    printf("Random in [%d...%d]: %d\n", A, B, r);
    return 0;
}