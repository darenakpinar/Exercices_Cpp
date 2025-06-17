#include <stdio.h>

int gcd(int a, int b){

    int (b == 0) return a;
    return gcd(b, a % b);
}