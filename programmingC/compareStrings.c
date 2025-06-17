#include <stdio.h>
#include <string.h>

int main(){
    char s1[] = "apple";
    char s2[] = "apple";
    char s3[] = "banana";

    printf("%d\n", strcmp(s1, s2));
    printf("%d\n", strcmp(s2, s3));
    printf("%d\n", strcmp(s3, s2));

    return 0;
}