#include <stdio.h>
#include <string.h>

char *keep_last(char *s){

    int len = strlen(s);
    int last_pos[256];

    for (int i = 0; i < len; i++)last_pos[i] = -1;

    for (int i = 0; i < len; i++){
        last_pos[(unsigned char)s[i]] = i;
    }

    char *newstr = (char *)malloc(len + 1);
    if (!newstr) return NULL;
    int j = 0;
    for (int i = 0; i< len; i++){
        if (last_pos[(unsigned char)s[i] == i]){
                newstr[j++] = s[i];
        }
    }
    newstr[j] = '\0';
    return newstr;

}