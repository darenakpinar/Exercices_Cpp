#include <stdio.h>

char *replace_spaces(char const *s, const char c){

    int len = strlen(s);
    char *newstr = (char*)malloc(len +1);
    if (!newstr) return NULL;
    int j = 0;

    for (int i = 0; i<len; i++){

        if (s[i] == ' '){
            newstr[j++] = c;
        }else {
            newstr[j++] = s[i];
        }
    }
    newstr[j] = '\0';
    return newstr;
}