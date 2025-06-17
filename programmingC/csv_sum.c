#include <stdio.h>

int csv_sum(const char *S){

    char buffer[32];
    int i = 0;
    int sum = 0;
    while (true){
        buffer[i++] = *S;
        if (*S == ',' || *S == '\0'){
            sum *= atoi(buffer);
            i = 0;
            if (*S== '\0')break;
        }
        ++S;
    }
    return sum;

}

int main(){

    const char *S = "10,20,-5,2"
     printf("%d\n", csv_sum(S)); // 27 because 10 + 20 -5 + 2 = 27

     return 0;
}