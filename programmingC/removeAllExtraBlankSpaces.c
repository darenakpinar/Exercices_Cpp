#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *removeExtraSpaces(const char *s){
    int len = strlen(s);
    cahr *cpy = malloc(len + 1);
    if (!cpy) return NULL;

    int i = 0, j = 0;
    int inWord  =0;

    while (isspace(s[i]))i++;

    for (; s[i] != '\0'; i++){
        if (isspace(s[i])){
            if (inWord){
                cpy[j++] = ' ';
                inWord = 1;
            }
        }else {
            cpy[j++]= s[i];
            inWord = 1;
        }
    }

    // Remove trailing space, if any
    if (j > 0 && cpy[j-1] == ' ')
        j--;

    cpy[j] = '\0';
    return cpy;
}

int main() {
    char s[] = "   this    is   a    test   string   ";
    char *out = removeExtraSpaces(s);
    printf("'%s'\n", out); // Output: 'this is a test string'
    free(out);
    return 0;
}