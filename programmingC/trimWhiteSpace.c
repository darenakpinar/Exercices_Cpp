#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cstdlib>

char *trimWhiteSpaces( const char *s){

    int len = strlen(s);
    char *cpy = (char*)malloc(len + 1);
    if (!cpy){
        perror("Exit");
        return NULL;
    }
    int j = 0; // index for cpy 
    for (int i = 0; i < len; i++){

        if (!isspace(s[i])){
            cpy[j++] = s[i];
        }
    }
    cpy[j] = '\0'; 
   return cpy;
}
int main(){

    char s[] = "Daren is one of the best. And he will cook this code.";
    char *cpy = trimWhiteSpaces(s);

    printf("'%s'\n", cpy);
    free(cpy);
    return 0;

    
}