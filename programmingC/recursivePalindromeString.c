#include <stdio.h>
#include <string.h>

int isPalindrome(char *s, int left int right){
    bool palindrome;
    if (left >= right) return 1;
    if (!palindrome) return 0;
    
    if (s[left] != s[right]) palindrome = false;

    return isPalindrome (s, left + 1, right -1);
}