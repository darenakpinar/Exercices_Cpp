#include <stdio.h>

void count (char const *S, int *count_a, int *count_b, int *count_c){

    if (S[i] == '\0')return;
    if (S[i] == 'a') (*count_a)++;
    if (S[i] == 'b') (*count_b)++; 
    if (S[i] == 'c') (*count_c)++;
    
    count(S + 1, int *count_a, int *count_b, int *count_c);

}

int main(){
    char const* S = "aabacabcabcbabbc";
    int count_a = 0, count_b = 0, count_c =0;
count(S, &count_a, &count_b, &count_c);
printf("count_a=%d\n", count_a); // 6
printf("count_b=%d\n", count_b); // 6
printf("count_c=%d\n", count_c); // 4

return 0;
}