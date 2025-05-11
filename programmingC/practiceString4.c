#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool isContained(char c, char *b) { // s[3] = "a", res = "ap"
  for(int i=0; i<strlen(b); i++)
    if(c == b[i])
      return true;
  return false;
}

char * frequent(char const* s){
  char * res = malloc(sizeof(char)* (strlen(s)/2+1));

  int k =0;
  for(int i=0; i <strlen(s)-1; i++){
    for(int j=i+1; j< strlen(s); j++){
      if(s[i] == s[j] && !isContained(s[i],res)) {
        res[k] = s[i];
        k++;
      }
    }
  }

  res[k] = '\0';
  k++;
  res = realloc(res, k);
  return res;
}


int main() {

  char * s = "appannaggio";
  printf("%s\n", frequent(s));
  return 0;
}


