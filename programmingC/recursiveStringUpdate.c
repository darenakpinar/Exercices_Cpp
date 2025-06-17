#include <stdio.h>
#include <string.h>

void count (char const *S, int *count_a, int *count_b, int *count_c){
    
        int len = strlen(S);
        if (*S == '\0') return;
        if (*S == 'a')(*count_a)++;
        if (*S == 'b')(*count_b)++;
        if (*S == 'c')(*count_c)++;
        count (S + 1, count_a, count_b, count_c); // move to the next char 
}

int main(){

    char const *S = "aabacabcabcbabbc";
    int count_a = 0, coun_b = 0, count_c = 0;

    count(S, &count_a, &count_b, &count_c);
    printf("count_a=%d\n", count_a); // 6
    printf("count_b=%d\n", count_b); // 6
    printf("count_c=%d\n", count_c); // 4
    return 0;
}