#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    size_t length = (rand() % 10) + 1;  // length from 1..10
    int N[length];

    // fill
    for (size_t i = 0; i < length; i++)
        N[i] = rand() % 10 + 1;          // values 1..10, say

    // shuffle
    for (size_t i = 0; i < length; i++) {
        size_t j = rand() % length;
        int tmp = N[i];
        N[i] = N[j];
        N[j] = tmp;
    }

    // print
    for (size_t i = 0; i < length; i++)
        printf("%d ", N[i]);
    printf("\n");
    return 0;
}
