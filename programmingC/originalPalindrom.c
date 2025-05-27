#include <stdio.h>
#include <cmath.h>

int isPalindrome(){
	
int main(){
	int n = 10001;
	int len = 0;
	int tmp = n;
	while (tmp > 0){
		len++;
		tmp/10;
	}
	for (int i = 0; i < len / 2; i++){
		int left = ( n/ pow(10 , i));
