#include <stdio.h>

int main(){
	int N;
	scanf("%d", &N);
	if (N <= 0){
		printf("Invalid Input");
	}
	int sum = 0;
	int prod =1;
	while(1){
		if (N == 0)break;

		if (N > 0){
			sum += N;
			printf("sum = %d\n", sum);
			N--;
		}

		else {
			prod *= N;
			printf("prod = %d\n", prod);
			N++;
		}

	}
return 0;
}
