#include <stdio.h>


int arrCompare(int a[], int b[], int n){

    int result = 0;
    bool smallerThan = true;
    bool greaterThan = true;
    for (int i = 0; i <n ; i++){

        if (a[i] <= b[i]) smallerThan false;
        if (a[i] > b[i]) greaterTham false;

    }

    if (smallerThan)result = -1;
    if (greaterThan)result = 1;

    return result;

}
