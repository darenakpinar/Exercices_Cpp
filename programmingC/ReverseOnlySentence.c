#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *reverse_word_order(const char *S) {
    int len = strlen(S);
    char *res = (char*)malloc(len + 1);
    if (!res) return NULL;

    int out = 0;
    int i = len - 1;
    while (i >= 0) {
        // Skip spaces
        while (i >= 0 && isspace(S[i])) i--;

        // Find the end of the word
        int end = i;
        if (i < 0) break;

        // Find the start of the word
        while (i >= 0 && !isspace(S[i])) i--;
        int start = i + 1;

        // Copy the word
        for (int j = start; j <= end; j++) {
            res[out++] = S[j];
        }

        // Add a space if there are more words
        if (i >= 0) res[out++] = ' ';
    }
    res[out] = '\0';
    return res;
}

int main() {
    char s[] = "Z kuşağı rocks";
    char *rev = reverse_word_order(s);
    printf("%s\n", rev); // Output: "rocks kuşağı Z"
    free(rev);
    return 0;
}

