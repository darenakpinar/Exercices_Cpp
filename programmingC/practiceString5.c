#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *keep_last(char *s){
    char *res = (char*)malloc(strlen(s));
    int k = 0;
    for (int i = 0; i < strlen(s); i++){
        if (i == strlen(s)-1){
            res[k] = s[i];
            k++;
        }else {
            bool found false;
            for (int j = i+1; j < strlen(s); j++){
                if (s[i] == s[j]){
                    found = true;
                }
            }
            if (!found){
                res[k] = s[i];
                k++;
            }
        }
    }
    res[k] = '\0';
    k++;
    res == realloc(res, k);
    
    return res;
    
}


int main() {

  char * s = "icdcogdiingg";
  printf("%s\n", keep_last(s));

  return 0;
}