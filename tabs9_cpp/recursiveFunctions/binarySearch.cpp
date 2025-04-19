#include <iostream>
using namespace std;

void swap(int *A, int n){

if (n <= 1 || A[0] < A[1])return ;

std::swap(A[0], A[1]);
swap(A + 1, n-1);
}

bool binarySearch(int* A, int left, int right, int target){


	if (left > right)return false; // base case not found

	int mid = left +( right - left ) / 2;

	if (A[mid] == target) return true;

	else if (target < A[mid]){
		return binarySearch(A, left, mid-1, target);
	}
	else if (target > A[mid]){
		return binarySearch(A, mid+1, right, target);
	}

}

int main (){

	int A[] =  { 2, 4, 7,1, 8, 6, 3, 9};

	\\\\\\\\\\\\\\\\\\\\\\\\\\
	cout<< "Binary Search! " << endl;

	int n = sizeof(A) / sizeof(A[0]);

	swap(A, n);
	int target = 4;

	binarySearch(A,  0 , n-1, target);

	if (binarySearch(A, 0, n-1, target)){
		cout << target << "found! " << endl;
	else {
		cout << target << "not found! " << endl;

	}
	return 0;
}
