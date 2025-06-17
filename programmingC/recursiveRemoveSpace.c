#include <stdio.h>
#include <string.h>

void removeSpaces(char *src, char *dest, int i , int j ){

    if (src[i] == '\0') {
        dest[j] = '\0';
        return;
    }
    if (src[i] != ' ')dest[j++] = src[i];
    return removeSpaces(src, dest, i + 1, j );
}