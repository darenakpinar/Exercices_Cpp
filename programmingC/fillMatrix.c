#include <stdio.h>
#include <math.h>

void fill(int *m, int n, int k){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (abs(i -j) <k){
				m[i*n + j] = 1;
			}else{
				m[i*n +j] = 0;
			}
		}
	}
}
