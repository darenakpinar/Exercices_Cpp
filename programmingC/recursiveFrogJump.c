#include <stdio.h>

int countHelper (int n, int lastJump){

    if (n ==0){
        return 1;
    }else if (n < 0){
        return 0;
    }
    int ways = 0;
    for (int jump = 1; jump <= 3; jump++){
        if (jump != lastJump) ways += countHelper(n - jump, jump);
    }

    return ways;
}


int countJump(int n){

    
        return countHelper(n, 0);
    
    
}