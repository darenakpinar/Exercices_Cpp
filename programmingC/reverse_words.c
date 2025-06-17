#include <stdio.h>
#include <string.h>


void reverse(char *s, int start, int end){

    while (start < end){
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

char *reverse_words(char const *S){
     
    int len = strlen(S);

    char *res = malloc((n+1) *sizeof(char));
    if (!res)return NULL;

    strcpy(res, S);

    int i = 0;
    while (i < n){

        if (res[i] == ' '){
            i++;
            continue;
        }

        int start = i;
        while (i < n && res[i] != ' ')i++;
        int end = i -1;
        reverse(res, start, end);
    }
    return res;

}

int main(){

    char const *S = "How is it going today?";
    char *S_rev = reverse_words(S);

    printf("%s\n", S_rev);
    return 0;
}