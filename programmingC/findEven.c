#include <iostream>


int find(int a[], int n){
	int result = -1;
	for (int i = 0; i < n; i++){
		if (a[i] % 2 == 0 && (result == -1 || result < a[i]){
			result = a[i];
		}
	}
	return result;
}
