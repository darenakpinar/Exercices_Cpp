#include <stdio.h>



int arrCompare(int A[], int B[], int n){

	bool allGreater = true;
	bool allSmaller = true;

	for (int i = 0; i < n; i++)}
		if (A[i]>B[i]) allSmaller = false;
		if (A[i] <= B[i]) allGreater = false;
	}

	if (!allSmaller) return 1;
	else if (!allGreater) return -1;
	return 0;
}

