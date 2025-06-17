#include <stdio.h>
#include <string.h>

void reverseStr(char *str, int left, int right){

    if (left >= right) return 1;
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;
    return revrerseStr(str, left + 1, int right -1);
}