#include <iostream>
#include <cassert>

bool isSorted(int* A, int n){
	for (int i = 1; i < n-1; i++){
		if (A[i] > A[i + 1]) return false;
	}
	return true;
}

void swap(int*A, int n){
	assert(n <= 1 || isSorted(A, n));  
	
	if ( n <= 1 || A[0] <= A[1]) return;

	std::swap(A[0], A[1]);

	swap(A + 1, n-1);  // recurse on the next one 
}

void sort(int*A, int n){

	if (n <= 1) return;

	sort(A + 1, n -1);
	swap ( A, n);

}

int main(){

	int A[] = { 3, 5, 1, 7, 2};
	int n = sizeof(A) / sizeof(A[0]);

	sort(A, n);

	for (int i= 0; i < n; i++){
		std::cout << A[i] << " ";
	}
}
