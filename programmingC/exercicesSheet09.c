#include <stdio.h>
#include <stdbool.h>

int count_ways(int n, int last_jump){
    int count = 0;
    if (n <= 0) return 1; // base case.

    int total = 0;
    for (int jump = 1; jump <= 3; jump++){
        if (jump != last_jump){
            total += count_ways(n-jump, jump);
        }
    }
    return total;
}

int main(){

    //The Frog Fred must travel exactly n meters(n >= 0) 1 2 or 3 meters in one jump. It can never make consecutive jumps of the same length.


    printf(count_ways())

    return 0;
}