#include <stdio.h>
#include <math.h>

bool  isPolindrom(int x, int xLength){
	int original = x;
	int reversed = 0;

	while (x > 0){
		int digit = x % 10;
		reversed = reversed * 10 + digit;
		x /= 10;
	}
	if (original == reversed ) return true;

	return false;
}
int main(){
	int n;
	scanf("%d", &n);
	
	if (n < 0){
		printf("Invalid Input!");
		return 1;
	}
	 int length = 0;
	 while (n>0){
		length++;
		n /=10;
	 }
	 
	if (isPolindrom(n, length) == true){
		printf("The integer is palindrom!\n");
	}else{
		printf("The integer is not palindrom!\n");
	}
	
	return 0;
}