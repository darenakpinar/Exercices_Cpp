#include <stdio.h>
#include <string.h>

bool isPalindrome(char s[]){

    int len = strlen(s);

    bool flag = true;
    for (int i = 0; i < len; i++){
        if (s[i] != s[len -1 -i]) flag = false;
    }

    return flag;

}
int main(){

    char s1[] = "noon";
    char s2[] = "radar";
    char s3[] = "daren";

    printf("%d\n", isPalindrome(s1));
    printf("%d\n", isPalindrome(s2));
    printf("%d\n", isPalindrome(s3));

    return 0;
}