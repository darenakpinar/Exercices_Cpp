#include <stdio.h>

int main(){
	int a[5] = { 7, 8, 9, 12};
	int result = find(a,5); 
	printf("%d\n", result);

	return 0;
}

int find(int a[], int n){
	int result = -1;
	for (int i = 0; i < n; i++){
		if ((result == -1 && a[i]*a[i] > 66)||
		   result > a[i] && a[i]*a[i] > 66)){
		result = a[i];
		{
	{
	return result;
}
