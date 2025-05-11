#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 int main(void){
    srand(time(NULL));

    int N;

    printf("How many flips? ");
    scanf("%d", &N);

    if (N < 1){
        printf("Bad Input! \n");
        return 1;
    }

    int heads = 0, tails = 0;

    for (int i = 0; i < N; i++){
        if (rand() % 2 == 0){
            heads++;
        }
        else {
            tails++;
        }
    }

    double p_heads = (double)heads * 100.0 / N;
    double p_tails = (double)tails * 100.0 / N;

    printf("Heads: %d (%.1f%%s)\n", heads, p_heads);
    printf("Tails: %d (%.1f%%s)\n", tails, p_tails);

    return 0;


 }