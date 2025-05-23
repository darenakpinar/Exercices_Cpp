#include <stdio.h>

void ReplicaWrite(int *B){

	int out[2*R][2*C];

	for (int i = 0; i < 2 * R; i++){
		for (int j =0; j < 2 * C; j++){
			out[i][j] = A[i % R][j % C];
		}
	}

	for (int i = 0; i < 2 * R; i++){
	 	for (int j = 0; j < 2 * C; j++){
			printf("%d ", out[i][j]);
		}
		printf("\n");
	}
}
