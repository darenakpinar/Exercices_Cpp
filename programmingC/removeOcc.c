#include <stdio.h>
#include <string.h>


void removeOcc(char s[], char word[]){

        int n = strlen(s), m = strlen(word);
        int i = 0, j = 0;
        while (i < n){

            int match = 1; 
            for (int k = 0; k < m; k++){
                if (i + k >= n || s[i + k] != word[k]){
                    match = 0;
                    break;
                }
            }
            if (match){
                i += m;
            }else {
                s[j++] = s[i++];
            }
        }
        s[j] = '\0';
}

int main(){

    char s[] = "daren is daren";
    char word[] = "daren";

    removeOcc(s, word);

    printf("%s\n", s);

    return 0;

}