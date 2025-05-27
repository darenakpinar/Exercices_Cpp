#include <stdio.h>


int main(){

	int n = 123444;
	int c = 4;
	int freq;
	while (n <){
		if ( n % 10 == c)freq++;
		n %= 10;
	}
	if (freq > 1){
		printf("Freq of %d is : %d", c, freq);
	}else{
		return 0;
	}
	return 0;
}
