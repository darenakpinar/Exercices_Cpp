#include <stdio.h>
#include <string.h>

void helper(char const* s, int start, int end, int n){

    if (end == n) return ;
    
    for (int i = start; i <=  end; i++){
        printf("%c, " s[i]);
    }
    printf("\n");

    helper(s, start , end , n);
}

void print_all_substrings(char const * s, const int n){

        if (n == 0) return;  
        
        helper(s, 0, 0, n);

        print_all_substring(s + 1, n -1);

}