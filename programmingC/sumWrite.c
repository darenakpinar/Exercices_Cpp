#include <stdio.h>
int *es3(int *m, int rows, int cols){
	int* v = (int*)malloc(sizeof(int) * cols);

	for (int i = 0; i < cols; i++){
		v[j] = 0;
		for (int j = 0; j < rows;j++){
			v[j] = m[j * cols + i);
		}
	}
	return v;
}
int main(){

	int M1[][3] = {1,2,3}, {4,5,6} };
	int i = 0;
	int *v = es2 (&M1[0][0], 2, 3);
	for (i = 0; i <3; i++){
		printf ("%d", v[i]);
	}
	return 0;
}

