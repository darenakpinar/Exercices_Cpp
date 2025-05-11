#include <stdio.h>
#include <stdlib.h>

int main (){

    srand(time(NULL));


    int r = rand() % 10;
    printf("Random [0...9]: %d\n", r);

    return 0;

}