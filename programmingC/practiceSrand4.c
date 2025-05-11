#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    size_t length = rand() % 10;
    int N[length];
    
    for (size_t i = 0; i < length; i++ ){
        int random;
        random = rand() % 10;
        N[i] = random;
        printf("%d ", N[i] );
    }

    return 0;
}