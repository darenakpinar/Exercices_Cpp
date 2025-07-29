#include <stdio.h>
bool match_at(int *a, int *b, int b_position, int a_size, int b_size){

    if (a_size > b_size - b_position) return false;

    for (int i = 0; i < a_size; i++){
        if (b[ i] != a[i]) return false;
    }
    return true;
}
int count_array(int *a, int a_size, int *b, int b_size){

    if (b_size < a_size) return 0;

    int count = match_start(a, b, a_size) ? 1 : 0;

    return count +  count_array(a, a_size, b + 1, b_size - 1);
}

int main(){

    int v1[] = {7,3,7};
    int v2[] = {7, 3, 7, 3, 7, 7, 3, 7,0};
    printf("%d \n", count_array(v1, 3, v2, 9) );

    return 0;
}