#include <stdio.h>
#include <string.h>

void removeLastOcc(char *s, const char *word){
    int n = strlen(s);
    int m = strlen(word);
    int lastIdx = -1;

    // find last occurrence index
    for (int i = 0; i <= n -m; i++){
        if (strncmp(s + i, word, m) == 0){
            lastIdx = i;
        }
    }
    // If found remove it by shifting chars left
    if (lastIdx != -1) {
        for (int i = lastIdx; i <= n - m; i++){
            s[i] = s[i + m];
        }
    }
}
int main() {
    char str[100] = "foo bar baz bar foo";
    removeLastOcc(str, "bar");
    printf("%s\n", str); // Output: foo bar baz  foo
    return 0;
}