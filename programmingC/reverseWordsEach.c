#include <stdio.h>
#include <string.h>

char *reverse_words(char const *S){


    int len = strlen(S);
    char *s = (char*)malloc(len +1);
    strcpy(s, S);
    int start = 0; 
    for (int i = 0; i < len; i++){

        if (s[i] == ' ' || s[i] == '\0') {
             int end = i -1;
            while (start < end){
                char tmp = s[start];
                s[start] = s[end];
                s[end] = tmp;
                start++;
                end--;
            }
        start = i + 1;
        }    
    }
    s[i] =='\0';
    return s;
}