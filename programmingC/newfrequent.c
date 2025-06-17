#include <stdio.h>
#include <string.h>

char *frequent(char const *s){

    int len = strlen(s);

    int counts[256] = {0};
    for (int i = 0; i < len; i++){
        counts[(unsigned char)s[i]]++;
    }

    char *new = (char*)malloc(len);
    if (!new)return NULL;
    int j = 0;
    for (int i = 0; i < 256; i++){
        if (counts[i] > 1){
            new[j++] = i;
        }
    }
    new[j] = '\0';
    return new;
}