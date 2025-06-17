#include <stdio.h>

int power(int x, int n){

    if (x == 0) return 1;

    return n * power(x -1, n);
}