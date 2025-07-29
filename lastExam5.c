#include <stdio.h>
#include <stdbool.h>

int count_occ_helper(char const* a, char const*b, const num_positions){
    if (num_positions <= 0)return 0;
    bool match = true;
    for (int i = 0; a[i] && match; ++i){
        if (a[i] != b[i])match = false;
    }
    return match + count_occ_helper(a, b+1, num_positions - 1);
}

int count_occ(char const *a, char const *b){
    int a_len = strlen(a);
    int b_len = strlen(b);
    const int num_positions = b_len - a_len + 1; // < 0 if a_len > b_len
    return count_occ_helper(a, b, num_positions);
}

int main(){
    char const *a = "acca";
    char const *b = "laccaccamacca";

    printf("%d\n"m count_occ(a, b));
    return 0;
}