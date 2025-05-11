#include <stdio.h>
#include <string.h>


char *  star(char *a){
    if (a[0] == '\0') return a;

    size_t len = strlen(a);

    for (int i = 0; i < len; i++){
        if (a[i] == ' '){
            a[i] = '*';
        }
    }
    return a;
}
int main(){
    char s[] = "I Love Coding";
    printf("%s\n", star(s));
    
    
    return 0;
}
