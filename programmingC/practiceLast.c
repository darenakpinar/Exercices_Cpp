#include <stdio.h>

int main(){
	int n;
	scanf("%d\n", &n);

	if (n <= 1 || n>7 ) {
		printf ("Invalid Input ");
		return 1;
	}

	for (int i = 1; i <=n; i++){
			printf("\n");
			int p = i;
		for (int j = 0; j<n; j++){
			printf("%d ", p);
			p *= 2;
		}
	}
	return 0;
}
