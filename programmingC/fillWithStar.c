#include <stdio.h>
#include <string.h>

char *star(char *a){

    int len = strlen(a);
    char *newstr = (char*)malloc(len * 2 +1);
    if (!newstr) return NULL;
    int j = 0;
    for (int i = 0; i < len; i++){

        if (a[i] == ' '){
            newstr[j++] = '*';
            newstr[j++] = '*';
        }else{
            newstr[j++] = a[i]; 
        }
    }
    newstr[j] = '\0';
    return newstr;

}

int main(){

    char *s = "I Love Coding";
    printf ("%s\n", star(s)); // output: I**Love**Codding
}