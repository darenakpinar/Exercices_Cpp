#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void) {
    srand((unsigned)time(NULL));

    const int MIN_P = 1, MAX_P = 100;
    int secret = (rand() % MAX_P) + 1;
    printf("Welcome to the number-guessing game!\n");
    printf("Think of a number between %d and %d; I'll try to guess it.\n\n", MIN_P, MAX_P);

    int low = MIN_P, high = MAX_P;
    int guess, count = 0;
    bool found = false;

    do {
        // draw uniformly from [low..high]
        guess = (rand() % (high - low + 1)) + low;
        count++;
        printf("AI guesses: %d\n", guess);

        if (guess == secret) {
            found = true;
        }
        else if (guess < secret) {
            printf("  Too low!\n\n");
            low = guess + 1;          // eliminate <= guess
        }
        else {
            printf("  Too high!\n\n");
            high = guess - 1;         // eliminate >= guess
        }
    } while (!found);

    printf("Congratulations to the AI!  It found the number %d in %d %s.\n",
           secret, count, count == 1 ? "try" : "tries");
    return 0;
}
