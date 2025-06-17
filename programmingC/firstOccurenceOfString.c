#include <stdio.h>
#include <string.h>

char *keep_first(char *s){

    int len = strlen(s);
    int first_pos[256];

    for (int i = 0; i < 256; i++) first_pos[i] = -1;

    for (int i = 0; i< len; i++){
        unsigned char c = s[i];
        if (first_pos[c] == -1){
            first_pos[c] = i;
        }
    }

    char *newstr = (char*)malloc(len + 1);
    if (!newstrp)return NULL;
    int j = 0;
    for (int i = 0; i < len; i++){
        unsigned char c = s[i];
        if (first_pos[c] == i){
            newstrp[j++] = c;
        }
    }
    newstrp[j] = '\0';
    return newstrp;
}