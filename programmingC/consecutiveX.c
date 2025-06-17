#include <stdio.h>
#include <stdbool.h>


bool consec(int n, char arr[]){
    int freq = 0;
    for (int i = 0; i < n; i++){
        if ( arr[i] == 'x'){
            freq++;
        }else if (arr[i] != 'x'){
            freq = 0;
        }
        if (freq >= 2) return true;
    }
    return false;
}