#include <stdio.h>
#include <string.h>


void helper(const char *s, int start, int k, int n){

    if ((start + k) > n) return;
    
    for (int i = 0; i < k; i++){
        printf("%c", s[start + i]);
    }
    printf("\n");
    helper(s, start + 1, k , n);
}
void find_substrings(const char *s, const int n){P}