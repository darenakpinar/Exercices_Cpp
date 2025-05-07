#include <stdio.h>

int main (){
	int number = 0;
	int result = 0;
	int a = 9;
	int b = 1;
	for (int i = 9; i>0; i--){

	result = number * 9 + i-1;
	number += i;
	number*=10;
	printf ("%d\n", result);
	}
return 0;
}
