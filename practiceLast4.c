#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool no_prime(int X[], int n){

	for (int i = 0;i< n; i++){
		int x = X[i];

		if (x < 2)
			continue;

	bool is_prime = true;
	for (int d = 2; d * d <= x; d++){
		if (x % d == 0){
			is_prime = false;
			break;
		}
	}

	if (is_prime)
		return false;

	}

	return true;
}

int main(void){
	int A[] = {10, 4, 8, 11};
	int B[] = {1, 4, 8, 12};

	printf ("%d \n", no_prime(A,4));
	printf("%d \n", no_prime(B, 4));

return 0;
}
