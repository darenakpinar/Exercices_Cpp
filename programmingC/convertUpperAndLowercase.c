#include <stdio.h>
#include <ctype.h>
#include <cstring>

int main(){
    char c[] = "Daren Is the goat of codding";
    int len = strlen (c);

    for (int i = 0; i < len; i++){
        c[i] = toupper(c[i]);
    }

    printf("%s", c);
    return 0;
}